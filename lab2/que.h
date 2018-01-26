#ifndef QUEUE_H
#define QUEUE_H

typedef enum{
FALSE=0, TRUE=1
}Boolean;

#ifndef NEW_EL
#define NEW_EL
typedef struct element
{
   struct element *next;
   int data;       // exemplar data
}Element;
#endif

typedef struct queue{
	Element *head;
	Element *tail;
	int size;
}Queue;

// returns empty queue
Queue* new_Q();

// true if queue is empty
Boolean is_empty_Q(Queue *q);

// deletes element at top
void del_top(Queue *q);

// returns element at top
Element* front_el(Queue *q);
//add e at front
void add_f(Queue *q, Element *e);
// adds e at rear
void add_el(Queue *q , Element *e);

//returns length
int length_Q(Queue *q);

//deletes the whole list, inlcuding list-head
void delete_Q(Queue* q);
// allocates new element
Element* new_el();

void delete_el(Queue *q, Element *e);

#endif
