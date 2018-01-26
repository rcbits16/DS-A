#include<stdlib.h>
#include "que.h"


// create empty queue
Queue* new_Q(void)
{
	Queue *nQ = (Queue*)malloc(sizeof(Queue));
	nQ->head = NULL;
	nQ->tail = NULL;
	nQ->size = 0;
return nQ;
}

Boolean is_empty_Q(Queue *q)
{
if(q==NULL) return TRUE;

	if(q->size > 0) return FALSE;
	else return TRUE;
}


// delete the first element
void del_top(Queue *q)			//checked
{
	if(q->head == NULL) return;
	else{	
		Element *it = q->head;
		q->head = it->next;
		q->size -= 1;
		if(it->next == NULL) q->tail = NULL;		//Reset tail if last element has been removed.
		free(it);
	}
} 

// returns element at top
Element* front_el(Queue *q)
{
        return q->head;
}

// add e at the front of the list
void add_f(Queue *q, Element *e)
{										//checked	
	if(q==NULL||e==NULL) return;
	if(q->head == NULL){
		q->tail = e;
	}
		e->next = q->head;
		q->head = e;
		q->size += 1;
}

// add e at the end of the list
void add_el(Queue *q, Element *e)
{										//checked	
	if(q==NULL||q==NULL) return;
	
	if(q->head == NULL){
		add_f(q,e);
	}
	else{
		q->tail->next = e;
		e->next = NULL; 
		q->tail = e;
		q->size +=1;
	}
}

// returns length
int length_Q(Queue *q)
{
if(q==NULL) return 0;

return q->size;
}

//deletes the whole list, inlcuding list-head
void delete_Q(Queue* q)			//checked
{
	if(q==NULL) return;
	
	Element *it = q->head;
	while(it!=NULL){
		Element *it2 = it->next;
		free(it);
		it = it2;	
	}
	free(q);
}

//allocates new element
Element* new_el(void)				//checked
{
	Element *new = (Element*)malloc(sizeof(Element));
	new->next = NULL;
	return new;
}

// delete e from q
void delete_el(Queue *q, Element *e)	//checked
{															
	if( q==NULL||e==NULL) return;	
	
	Element *it = q->head;
	if(it == e)	del_top(q);
	else{
	
		Element *it2 = it->next;
		while(it2!=NULL){
			
			if(it2 == e){		// element found
				
				it->next = it2->next;
				free(it2);
				q->size -= 1;	
				if(it->next == NULL) 
					q->tail = it;		//Reset tail if last element has been removed.
			 	break;
			 }
			else{
				it = it->next;	it2 = it->next;		// move both iterators ahead..
			}	
		}
	}
}


