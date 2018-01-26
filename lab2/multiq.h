// I'm making the multi-q too a linked list
#ifndef MULTIQ_H
#define MULTIQ_H

/************************************************************STRUCT DEFINITIONS*****************************************************/

typedef struct task{	// would contain info about the task
	int priority;	
	int task_id;
}Task;

#ifndef NEW_EL
#define NEW_EL
typedef struct element
{
   struct element *next;
   Task t;
}Element;

#endif

#include"que.h"

typedef struct qhead
{
   Queue *thisq;
   struct qhead *nextq;
   int priority;
}Qhead;

typedef struct multiq{
	Qhead *head;
	Qhead *tail;
	int tasks;
	int numq;
}MultiQ;

/************************************************************INTERFACE FUNCTIONS*****************************************************/

// Creates a new list of queues. (All empty)
MultiQ* create_MQ(void);

// Adds t to the queue acc to priority
void add_task(MultiQ *mq, Element *t);

// return the front of the non-empty Queue in  mq with the highest priority
Element* next_task(MultiQ *mq);

// deletes top task, returns 1 if something deleted, 0 if not
int del_next_task(MultiQ *mq);

//true if multi-queue is empty 
Boolean is_empty_MQ(MultiQ *mq);

// total no of tasks in multi-queue
int size_MQ(MultiQ *mq);

// return no of tasks with this priority
int size_MQ_by_priority(MultiQ *mq, int p);

//returns the queue with priority p
Queue* get_Q_from_MQ(MultiQ *mq, int p);

/************************************************************USECASE FUNCTIONS*****************************************************/
//loads data from a file and makes a multi-q out of it
MultiQ* loadData(FILE *fp);

//delete num top elements
MultiQ* testDel(MultiQ *mq, int num);
/************************************************************HELPER FUNCTIONS*****************************************************/

// Adds a new q in order of priority
Queue* add_oQ(MultiQ *mq, int p);
// Adds new q at end
Queue* add_eQ(MultiQ *mq, int p);
// Adds new q at front
Queue* add_fQ(MultiQ *mq, int p);

// deletes entire multiq
void del_MQ(MultiQ *mq);

#endif
