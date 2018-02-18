#include<stdio.h>
#include"multiq.h"
// reads from f a list of pairs (task_id, priority) and adds each	item to a MultiQ appropriately.

MultiQ* loadData(FILE *fp)			// DOES NOT CLOSE THE FILE>>>
{
	if(fp==NULL) return NULL;
	MultiQ *newmq = create_MQ();
	int task_id,priority;
	Element *ne;
	while(fscanf(fp, "%d,%d", &task_id, &priority)==2)		// expect 2 successful conversions	
	{
		ne = new_el();
		ne->t.priority = priority;
		ne->t.task_id = task_id;
		add_task(newmq,ne);
	}	
return newmq;
}

MultiQ* testDel(MultiQ *mq, int num)
{
	for(int i=0;i<num;i++)
	{	
		if(!del_next_task(mq)) break;
	}
}




