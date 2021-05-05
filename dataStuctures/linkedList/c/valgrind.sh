# Quickly test and run valgrind, checks for memory issues
gcc -g linkedList.c main.c
valgrind ./a.out
rm a.out
