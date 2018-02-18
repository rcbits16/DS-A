#include<stdio.h>
#include<stdlib.h>
#include"memr.h"
#include"SeqList.h"


/*
* Note that both these procedures must use only the interface given above i.e. should not
* touch the underlying implementation. This also implies that no allocation / de-allocation is
* to be done in these procedures.
*/


// Merges two ordered listes in order
SeqList* merge(SeqList *l1, SeqList *l2)
{
	if(l1->size >= l2->size)
	{
		SeqList *merged = l1;
		Element *it = l2->head,*it2;
		
		while(it!=NULL){
			it2 = it->next;
			insertInOrder(merged,it);
			it = it2;

		}	
		return merged;
	}
	else return merge(l2,l1);
}

//Sorts an unsorted list
SeqList* insertionSort(SeqList *sl)
{
	if(sl==NULL) return sl;

	Element *it = sl->head,*it2;
	sl->head = NULL; sl->tail = NULL; sl->size = 0;	
	while(it!=NULL){
		it2 = it->next;
		insertInOrder(sl,it);
		it = it2;
	}	
	return sl;	
}

SeqList* createList(int N)
{
	SeqList *randomlist = newList();
	Element *randomel;
	for(int i=0;i<N;i++)
	{
		randomel  =  newElement();
		randomel->k.num = i;
		randomel->data = rand();
		insertAtEnd(randomlist,randomel);
	}
	FILE *fp1 = fopen("heap_used.txt","w");
	fprintf(fp1,"Heap usage in the last call to createList:%llu\n",heap_usage());
	return randomlist;	
}
	
SeqList* createCycle(SeqList *sl)
{
	int fate = rand();
	Key k;	k.num =fate;
	if((fate%2)<1)
		sl->tail->next = find(sl,k);
	return sl;
} 







