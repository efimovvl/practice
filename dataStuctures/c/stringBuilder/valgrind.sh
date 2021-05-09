# Quickly test and run valgrind, checks for memory issues
gcc -g ../linkedList/linkedList.c stringBuilder.c main.c
valgrind ./a.out
rm a.out
