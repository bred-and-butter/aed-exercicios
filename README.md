Disponível também em
https://github.com/bred-and-butter/aed-exercicios

Compilar arquivo main:

gcc list_functions.c main.c -o main.exe

Executar arquivo main:

./main.exe (linux)
.\main.exe (windows eu acho)

Se valgrind estiver disponível (exclusivo linux):

valgrind --leak-check=yes ./main.exe

Compilar arquivo de testes:

gcc list_functions.c test_file.c -o test.exe

Executar arquivo de testes:

./test.exe (linux)
.\test.exe (windows eu acho)

Se valgrind estiver disponível:

valgrind --leak-check=yes ./test.exe

Valgrind pode ser instalado com:

sudo apt install valgrind
