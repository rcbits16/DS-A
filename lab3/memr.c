#include"memr.h"
#include<stdlib.h>

unsigned long long heap=0;

void* myalloc(unsigned int user_size)
{
	int *p= malloc(user_size+sizeof(int));
	if(p!=NULL)
	{
	p[0]= user_size;
	heap += (user_size+sizeof(int));
	p++;
	return (void*)p;
	}
else return NULL;
}

void myfree(void *ptr)
{
	int *p = (int*)ptr;
	p--;
	heap -= p[0];
	free(p);
}

unsigned long long heap_usage(void)
{
	return heap;
}

