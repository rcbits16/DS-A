#include<stdlib.h>
#include "SeqList.h"
#include "memr.h"

//TODO: Adapt the code for circular linked lists. 

//Compare element by key. (1 if a>b, 0 otherwise)
int greater(Element *a, Element *b)		//checked
{
     return( a->k.num > b->k.num );
}

// Creates an empty list, returns pointer to it.
SeqList* newList(void)					//checked
{
	SeqList* nlist = (SeqList*) myalloc(sizeof(SeqList));
	nlist->head = NULL;
	nlist->tail = NULL;
	nlist->size = 0;
	return nlist;
}

//deletes the whole list, inlcuding list-head
void deleteList(SeqList* sl)			//checked
{
	if(sl==NULL) return;
	
	Element *it = sl->head;
	while(it!=NULL){
		Element *it2 = it->next;
		myfree(it);
		it = it2;	
	}
	myfree(sl);
}

//allocates new element
Element* newElement(void)				//checked
{
	Element *new = (Element*)myalloc(sizeof(Element));
	new->next = NULL;
	new->k.num=0;
	new->data=0;
	return new;
}

// add e to sl in order of key assuming sl is ordered
void insertInOrder(SeqList *sl, Element *e)
{										//checked		
	if(sl==NULL||e==NULL) return;		
	
	Element *cur_pos = sl->head;
	if( cur_pos == NULL || e->k.num < cur_pos->k.num ){
		insertAtFront(sl,e);	
	}
	else{
		Element *next = cur_pos->next;
		while( next != NULL && next->k.num < e->k.num )
		{
			cur_pos = cur_pos->next;
			next = cur_pos->next;
		}
		cur_pos->next  = e;
		e->next = next;
		sl->size += 1;

		if(next == NULL)	sl->tail = e;
	}
}

// add e at the front of the list
void insertAtFront(SeqList *sl, Element *e)
{										//checked	
	if(sl==NULL||e==NULL) return;

	if(sl->head == NULL){
		sl->tail = e;
	}
		e->next = sl->head;
		sl->head = e;
		sl->size += 1;
}

// add e at the end of the list
void insertAtEnd(SeqList *sl, Element *e)
{										//checked	
	if(sl==NULL||e==NULL) return;
	
	if(sl->head == NULL){
		insertAtFront(sl,e);
	}
	else{
		sl->tail->next = e;
		e->next = NULL; 
		sl->tail = e;
		sl->size +=1;
	}
}

// delete e from sl
void delete(SeqList *sl, Element *e)	//checked
{															
	if( sl==NULL||e==NULL) return;	
	
	Element *it = sl->head;
	if(it == e)	deleteAtFront(sl);
	else{
	
		Element *it2 = it->next;
		while(it2!=NULL){
			
			if(it2 == e){		// element found
				
				it->next = it2->next;
				myfree(it2);
				sl->size -= 1;	
				if(it->next == NULL) 
					sl->tail = it;		//Reset tail if last element has been removed.
			 	break;
			 }
			else{
				it = it->next;	it2 = it->next;		// move both iterators ahead..
			}	
		}
	}
}

// delete the first element from sl
void deleteAtFront(SeqList *sl)			//checked
{
	if(sl->head == NULL) return;
	else{	
		Element *it = sl->head;
		sl->head = it->next;
		sl->size -= 1;
		if(it->next == NULL) sl->tail = NULL;		//Reset tail if last element has been removed.
		myfree(it);
	}
} 
 
// find the element e with key k and returns a pointer to it
Element* find(SeqList *sl, Key k)		//checked
{
	Element *it = sl->head;
	while(it!=NULL){
		if(it->k.num == k.num) break;
		else it = it->next;
	}
	return it;
}

SeqList* reverse(SeqList *sl)
{
	if(sl==NULL) return sl;

	Element *prev,*current,*next;
	prev = NULL;
	current = sl->head;
/*
Doing so will screw up the link reversal cycle detection algorithm.
//Exchanging head and tail pointers
	sl->head = sl->tail;
*/

	sl->tail = current; //Current already pointed to head of original list	
	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	sl->head = prev;	// This accomplishes the same result, except when there's a cycle!!	
	return sl;
}

