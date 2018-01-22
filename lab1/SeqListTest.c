#include <stdio.h>
#include<stdlib.h>
#include"SeqList.h"

int main(void)
{
	SeqList *l1 = newList();
	Element *temp;
	
		for(int i=1;i<=10;i++){
			temp = newElement();
			temp->k.num = i;
			temp->data = i*i;
			insertInOrder(l1,temp);
		}

	SeqList *l2 = newList();
	
		for(int i=20;i>=11;i--){
			temp = newElement();
			temp->k.num = i;
			temp->data = i*i;
			insertAtEnd(l2,temp);
		}
	l2 = insertionSort(l2);

	temp = l2->head;
	while(temp!=NULL){
		printf("Key: %d, Data: %d \n",temp->k.num,temp->data);
		temp = temp->next;
	}	

	l1 = merge(l1,l2);
	free(l2);
	temp = l1->head;
	while(temp!=NULL){
		printf("Key: %d, Data: %d \n",temp->k.num,temp->data);
		temp = temp->next;
	}			
deleteList(l1);
return 0;
}







