# Quickly test and run valgrind, checks for memory issues
gcc -g ../linkedList/linkedList.c stringBuilder.c
valgrind ./a.out
rm a.out
