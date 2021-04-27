/*
 * Simple singly linked list.
 */


#include <stdio.h>
#include <stdlib.h>

// Node with next node pointer and value pointer.
// Void value pointer allows flexibility to what is in our list
// Having issues with void pointer. TODO use void instead of int
struct node {
	struct node* next;
	//void* value;
	int value;
};

// likedList object with head and tail.
// Apply operations to this object.
struct linkedList {
	struct node* head;
	struct node* tail;
};



// Operations are applied to linkedList struct

// Initiate, malloc linkeList
// TODO This should just me a macro
struct linkedList* init() {
	return malloc(sizeof(struct linkedList));
}

// Push -> adds to start of list
// TODO void* instead of int
void push(struct linkedList* list, int value) {
	// If null poiter, fast return.
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

// Peak -> returns value of head node
int peak(struct linkedList* list) {
	if (!list) {
		return -1;
	}
	return list->head->value;
}

// Pop -> returns value from start, removes head node.
// if nothing to pop, returns -1
//(TODO return null ptr when void pointer works)
int pop(struct linkedList* list) {
	if (!list) {
		return -1;
	}

	// If empty return -1
	if (!(list->head)){
		return -1;
	}

	struct node* curHead = list->head;
	int value = curHead->value;

	// Move head to nest
	list->head = curHead->next;

	// If removed last item, dereference tail.
	if (!(list->head)) {
		list->tail = list->head;
	}

	free(curHead); //delete node;

	return value;
}
// Append -> Adds to end of list
void append(struct linkedList* list, int value) {
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

		(*newNode).value = value;
		//(*newNode).next = (*list).head;
		list->tail->next = newNode;
		list->tail = newNode;
	}

}

// Delete -> free memory, delete's whole list
void delete(struct linkedList* list) {
	if (!list) {
		return;
	}
	while(list->head) {
		pop(list);
	}
	free(list);
}

// Print -> for debugging, print out the list of int
void printIntList(struct linkedList* list) {
	if (!list) {
		return;
	}
	// TODO convert to using -> operator
	struct node *head = (*list).head;
	// While head is not null
	// Note: assuming value is int. Expect this to break hard otherwise.
	while(head) {
		printf("%d ", head->value);
		head = head->next;
	}
}
void printPopIntList(struct linkedList* list) {
	if (!list) {
		return;
	}
	// TODO convert to using -> operator
	// node *head = list->head;
	// While head is not null
	// Note: assuming value is int. Expect this to break hard otherwise.
	int value = -1;
	while(list->head) {
		value = pop(list);
		printf("%d ", value);

	}
}

int main(int argc, char **argv)
{
	struct linkedList* lst;
	lst = init();
	int a = 5;
	int b = 1;
	int c = 9;
	push(lst, a);
	push(lst, b);
	push(lst, c);
	append(lst, 88);
	printIntList(lst);
	printf("\n***\n");
	printIntList(lst);
	delete(lst);
	// delete frees lst,
	//printf("\n***\n");
	//printIntList(lst);
	return 0;
}

