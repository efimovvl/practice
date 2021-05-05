/**
 * Singly linked list c test.
 *
 * @author Vladimir Efimov
 */

#include <stdio.h>
#include <stdlib.h>
#include "./linkedList.h"

/* Print -> for debugging/testing, print out the list of int */
void printIntList(struct linkedList* list) {
        if (!list) {
                return;
        }
        struct node *head = list->head;
        // While head is not null
        // Note: assuming value is int. Expect this to break hard otherwise.
        while(head) {
                printf("%d ", *((int*)(head->value)));
                head = head->next;
        }
	printf("\n");
}

int main(int argc, char **argv)
{
        struct linkedList* lst;
        lst = init();
        int a = 5;
        int b = 1;
        int c = 9;
        int d = 88;
        push(lst, &a);
        push(lst, &b);
        push(lst, &c);
        append(lst, &d);
        printIntList(lst);
        printf("***\n");
        printIntList(lst);
        delete(lst);
        return 0;
}

