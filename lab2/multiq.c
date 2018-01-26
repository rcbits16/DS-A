// Keep 'queues' unsorted...
#include<stdio.h>
#include<stdlib.h>
#include"multiq.h"

/************************************************************INTERFACE FUNCTIONS*****************************************************/


// Creates a list of num queues. (All empty)

// I'm ignoring the specification, allocating in the beggining seems kinda useless, we'll handle everything online
MultiQ* create_MQ(void)
{
	MultiQ *newmq = (MultiQ*)malloc(sizeof(MultiQ));
	newmq->head =NULL;
	newmq->tail =NULL;
	newmq->tasks=0;
return newmq;		
}

// Adds t to the queue acc to priority
void add_task(MultiQ *mq, Element *e)
{
if(mq==NULL||e==NULL)	return;

	Queue *qconcerned = get_Q_from_MQ(mq, e->t.priority);			

	if(qconcerned==NULL)
		qconcerned = add_oQ(mq, e->t.priority);

	mq->tasks+=1;
	add_el(qconcerned,e);
}

// return the front of the non-empty Queue in  mq with the highest priority
Element* next_task(MultiQ *mq){
if(mq==NULL||mq->tasks==0) return NULL;

	Qhead *curq = mq->head;
	while(curq!=NULL)
	{
		if( length_Q(curq->thisq)>0)
		{
			return front_el(curq->thisq);
		}
		else	curq = curq->nextq;
	}
}

// returns 1 if anything was deleted, 0 if not.
int del_next_task(MultiQ *mq)
{
if(mq==NULL) return 0;
	Qhead *curq = mq->head;

	while(curq!=NULL)
	{
		if( length_Q(curq->thisq)>0)
		{
		 	del_top(curq->thisq);
		 	mq->tasks -=1;
		 	break;
		}
		else	curq = curq->nextq;
	}

}

//true if multi-queue is empty 
Boolean is_empty_MQ(MultiQ *mq)		//I'm not sure what shoud NULL be treated as logically, treating it as empty for now..
{
if(mq== NULL) return TRUE;
	
	if(mq->tasks>0) return FALSE;
	else return TRUE;
}

// total no of tasks in multi-queue
int size_MQ(MultiQ *mq)
{
if(mq==NULL) return 0;
return mq->tasks;
}

// return no of tasks with this priority
int size_MQ_by_priority(MultiQ *mq, int p)
{
	Queue *qconcerned = get_Q_from_MQ(mq,p);
	return length_Q(qconcerned);
}

//returns the queue with priority p
Queue* get_Q_from_MQ(MultiQ *mq, int p)
{
if(mq==NULL||p<0) return NULL;

	Qhead* curq = mq->head;
	
	while(curq!=NULL)
	{
		if(curq->priority ==p) break;
		else curq = curq->nextq;
	}
	if(curq!=NULL) return (curq->thisq);
else return NULL;	
}

/************************************************************HELPER FUNCTIONS*****************************************************/


// Adds a new q in order
Queue* add_oQ(MultiQ *mq, int p)
{		
if(mq==NULL||p<0) return NULL;								//checked		
	Qhead *curq = mq->head;
	if( curq == NULL || p< curq->priority){
		return add_fQ(mq,p);	
	}
	else{
		Qhead *next = curq->nextq;
		while( next != NULL && next->priority < p )
		{
			curq = curq->nextq;
			next = curq->nextq;
		}
		Qhead *nqh = malloc(sizeof(Qhead));
		nqh->nextq = next;
		nqh->priority =p;
		nqh->thisq = new_Q();

		curq->nextq  = nqh;
		mq->numq += 1;

		if(next == NULL)	mq->tail = nqh;
		
		return nqh->thisq;
	}
}

//insert at end
Queue* add_eQ(MultiQ *mq, int p)
{
	if(mq==NULL||p<0) return NULL;

	if(mq->head==NULL){
		return add_fQ(mq,p);
	}
	else{
	Qhead *nqh = malloc(sizeof(Qhead));
		nqh->nextq = NULL; 
		nqh->priority = p;
		nqh->thisq = new_Q();
		
		mq->tail->nextq = nqh;
		mq->tail = nqh;
		mq->numq +=1;
		
		return nqh->thisq;
	}
}

Queue* add_fQ(MultiQ *mq, int p)
{
	if(mq==NULL||p<0) return NULL;

	Qhead *nqh = malloc(sizeof(Qhead));
	if(mq->head == NULL){
		mq->tail = nqh;
	}
		nqh->nextq = mq->head;
		nqh->priority = p;
		nqh->thisq = new_Q();
		
		mq->head = nqh;
		mq->numq += 1;
	return nqh->thisq;
}

void del_MQ(MultiQ *mq)
{
if(mq==NULL) return;
	
	Qhead *it = mq->head;
	while(it!=NULL){
		Qhead *it2 = it->nextq;
		delete_Q(it->thisq);
		free(it);
		it =it2;
	}
free(mq);
}

