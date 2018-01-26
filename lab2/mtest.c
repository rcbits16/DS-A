#include<stdio.h>
#include"multiq.h"

int main(void)
{

	char file_name[50];
	
	printf("Enter the file-name:");
	scanf("%s",file_name);
	FILE *fp = fopen(file_name,"r");
	if(fp==NULL)
	{ 
		printf("Incorrect file-name..\n");
		return 0;
	}
	
	MultiQ *mq = loadData(fp);

	printf("Showing the data in order...\n");
	
	Element *e =next_task(mq);
	while(e!=NULL)
	{
		printf("Priority: %d, Task_id: %d\n",e->t.priority,e->t.task_id);	
		del_next_task(mq);
		e =next_task(mq);
	}

del_MQ(mq);	
}



