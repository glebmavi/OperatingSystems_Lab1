Процессы (fork/clone3): Независимые единицы выполнения с собственным адресным пространством. Используются для изолированного выполнения программ.
Потоки (std::thread): Легковесные единицы выполнения внутри одного процесса, разделяющие адресное пространство.

clone3 в Main.cpp: Используется для запуска отдельных программ (бенчмарков) как независимых процессов.
Потоки внутри бенчмарков: Используются для параллельного выполнения задач внутри каждого процесса бенчмарка.
