/**
 * Singly linked list c implementation
 *
 * @author Vladimir Efimov
 */

#include <stdio.h>
#include <stdlib.h>

/** Node and linkedList Structs **/

/*
 * Node struct with next node pointer and value pointer.
 * Void value pointer allows flexibility to what is in our list
 */
struct node {
	struct node* next;
	void* value;
};

/*
 * LikedList object with head and tail.
 * Apply operations/fuctions to this object.
 */
struct linkedList {
	struct node* head;
	struct node* tail;
};

/** Operations/functions that are applied to linkedList struct **/

/* Returns new linkedList Struct (memory allocated) */
struct linkedList* init() {
	struct linkedList* lst = malloc(sizeof(struct linkedList));
	lst->head = 0;
	lst->tail = 0;
	return lst;
}

/* Push -> adds to start of list */
void push(struct linkedList* list, void* value) {
	// If null pointer, fast return.
	if (!list) {
		return;
	}

	struct node *newNode = malloc(sizeof(struct node));
	// Check that malloc was successful (not null, not 0)
	if (newNode) {
		(*newNode).value = value;
		(*newNode).next = (*list).head;

		(*list).head = newNode;
		// If tail is null, set it.
		if (!((*list).tail)) {
			(*list).tail = newNode;
		}
	}
	// Done
}

/* Peak -> returns value of head node */
void* peak(struct linkedList* list) {
	if (!list) {
		return 0;
	}
	return list->head->value;
}

/*
 * Pop -> returns value from start, removes head node.
 * if nothing to pop, returns 0
 */
void* pop(struct linkedList* list) {
	if (!list) {
		return 0;
	}

	// If empty return -1
	if (!(list->head)){
		return 0;
	}

	struct node* curHead = list->head;
	void* value = curHead->value;

	// Move head to nest
	list->head = curHead->next;

	// If removed last item, dereference tail.
	if (!(list->head)) {
		list->tail = list->head;
	}

	free(curHead); //delete node;

	return value;
}

/* Append -> Adds to end of list */
void append(struct linkedList* list, void* value) {
	if (!list) {
		return;
	}
	if (!(list->head)) {
		push(list, value);
		return;
	}

	struct node *newNode = malloc(sizeof(struct node));
	// Check that malloc was successful (not null, not 0)
	if (newNode) {
		// if empty list, do push instead.

		newNode->value = value;
		newNode->next = 0;
		list->tail->next = newNode;
		list->tail = newNode;
	}

}

/* Delete -> free memory, deletes whole list (frees memory) */
void delete(struct linkedList* list) {
	if (!list) {
		return;
	}
	while(list->head) {
		pop(list);
	}
	free(list);
}

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
	printf("\n***\n");
	printIntList(lst);
	delete(lst);
	return 0;
}

