mtest:  que.o multiq.o mquses.o mtest.o 
	gcc que.o multiq.o mquses.o mtest.o -o mtest
que.o: 	que.c que.h
	gcc -c que.c -o que.o
multiq.o: multiq.h multiq.c que.h
	gcc -c multiq.c -o multiq.o
mquses.o: multiq.h mquses.c que.h
	gcc -c mquses.c -o mquses.o
mtest.o:mtest.c que.h multiq.h 
	gcc -c mtest.c -o mtest.o
