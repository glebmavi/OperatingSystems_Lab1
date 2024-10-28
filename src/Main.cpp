#include <iostream>
#include <vector>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <chrono>
#include <linux/sched.h> // Здесь определение структуры clone_args
#include "Shell.h"

// Враппер для clone3
int clone3(struct clone_args *cl_args, size_t size) {
    return syscall(SYS_clone3, cl_args, size);
}

void execute_task(Shell& shell, const std::string& command) {
    // Для измерения времени выполнения
    auto start = std::chrono::high_resolution_clock::now();

    // Setup clone3 arguments
    struct clone_args cl_args = {0};
    cl_args.flags = CLONE_FS | CLONE_FILES, // Необходимо для работы с файлами
    cl_args.exit_signal = SIGCHLD;

    // Создание процесса
    int pid = clone3(&cl_args, sizeof(cl_args));
    if (pid == 0) {
        // Процесс-потомок: Выполнение команды
        std::vector<char*> args;
        shell.execute_command(command);
        exit(0);
    } else if (pid > 0) {
        // Процесс-родитель: Ожидание завершения процесса-потомка
        int status;
        waitpid(pid, &status, 0);

        // Измерение времени выполнения
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_time = end - start;
        std::cout << "Execution time: " << elapsed_time.count() << " seconds" << std::endl;
    } else {
        std::cerr << "clone3 failed!" << std::endl;
    }
}

int main() {
    Shell shell;
    std::string command;

    // Луп для ввода команд
    while (true) {

        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != nullptr) {
            std::cout << "shell " << cwd << "> ";
        } else {
            std::cerr << "getcwd() error" << std::endl;
        }
        std::getline(std::cin, command);

        // Выход из программы
        if (command == "exit") break;

        // Выполнение команды
        execute_task(shell, command);
    }

    return 0;
}