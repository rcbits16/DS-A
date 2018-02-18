#include"cycle.h"
#include<stdlib.h>

//This implementation uses Floyd's cycle detection(a.ka.hare and tortoise) algorithm.
//Only tests for cyclicity,doesn't determine cycle size, or starting point.
Bool testCyclic(SeqList *sl)
{
// Pay attention to the case of list with two nodes...
	if(sl==NULL||sl->size==0||sl->size==1) return FALSE;
	
	Element *hare,*tort;
	hare = sl->head;
	tort = sl->head; 

	while(hare!=NULL)
	{
		hare = hare->next;
		tort = tort->next;
		if(hare!=NULL)	
			hare = hare->next;
		if(hare!=NULL&&tort!=NULL)
			if(hare==tort)	return TRUE;
	}
	return FALSE;
}


//This implementation uses link reversal algorithm
// If the list is cyclic, the new head after reversal, will be the same as the old head.
//Lookout for the case where only one element. Don't give false positives :p
/*
Bool testCyclic(SeqList *sl)
{
// reverse the damn list, 
// if new head same as old one, return true :P

}
*/
