#ifndef SEQLIST_H
#define SEQLIST_H

typedef struct key
{
	int num;	//for now, key is a num
}Key;

typedef struct element
{
	struct element *next;
	Key k;
	int data;	// exemplar data
}Element;

typedef struct seqlist
{
	Element *head;
	Element *tail;
	int size;
}SeqList;

//Compare element by key. (1 if a>b, 0 otherwise)
int greater(Element *a, Element *b);

// creates an empty list
SeqList* newList(void);

//deletes the whole list, inlcuding list-head
void deleteList(SeqList* sl);

//allocates new element
Element* newElement(void);

// add e to sl in order of key assuming sl is ordered
void insertInOrder(SeqList *sl, Element *e);

// add e at the front of the list
void insertAtFront(SeqList *sl, Element *e);

// add e at the end of the list
void insertAtEnd(SeqList *sl, Element *e);

// delete e from sl
void delete(SeqList *sl, Element *e);

// delete the first element from sl
void deleteAtFront(SeqList *sl);
 
// find the element e with key k and returns a pointer to it
Element* find(SeqList *sl, Key k);

//Reverses the linked list
SeqList* reverse(SeqList *sl);

// Merges two ordered listes in order
SeqList* merge(SeqList *l1, SeqList *l2);

//Sorts an unsorted list
SeqList* insertionSort(SeqList *sl);

// creates a list of size N, fills it with random data
SeqList* createList(int N);

// Creates a cycle with probability = 0.5(roughly).
SeqList* createCycle(SeqList *sl);
#endif












