#include <stdio.h>
#include<stdlib.h>
#include"SeqList.h"
#include"cycle.h"

int main(void)
{
	int n;
	do{
		printf("Enter size (+ve):\n");
		scanf("%d",&n);
	}while(n<1);
	
	SeqList *l1 = createList(n);
//	l1 = createCycle(l1);
//temporary to check if test cyclic working good..
	l1->tail->next = l1->head;
	
	if(testCyclic(l1))	
	{	
		printf("The list is cyclic.\n");
		reverse(l1);
		printf("reversed the list\n");
		if(testCyclic(l1)) printf("Still cyclic\n");
	}
	else	printf("The list is not cyclic.\n");

	deleteList(l1);
return 0;
}


