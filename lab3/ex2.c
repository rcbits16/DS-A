#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"memr.h"

int main(void)
{
	printf("heap heap ....\n");
	int m,*a;
		m= 1000000000;
		a = myalloc(m*sizeof(int));
		if(a!=NULL){
			printf("First:%p,Last: %p \n",a,(a+m-1));
			usleep(999999999);
			myfree(a);	
		}

	printf("hop hop ....\n");

}
