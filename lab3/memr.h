#ifndef MEMR_H
#define MEMR_H

extern unsigned long long heap;
void * myalloc(unsigned int size);
void myfree(void *ptr);

unsigned long long heap_usage();
#endif
