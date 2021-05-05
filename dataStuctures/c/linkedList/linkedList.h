#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

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

struct linkedList* init();
void push(struct linkedList* list, void* value);
void* peak(struct linkedList* list);
void* pop(struct linkedList* list);
void append(struct linkedList* list, void* value);
void delete(struct linkedList* list);

#endif


