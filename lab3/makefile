test: memr.o list.o uses.o cycle.o test.o 
	gcc memr.o list.o uses.o cycle.o test.o -o test
memr.o:	memr.c memr.h
	gcc -c memr.c -o memr.o
list.o: list.c SeqList.h memr.h
	gcc -c list.c -o list.o
uses.o: uses.c SeqList.h memr.h
	gcc -c uses.c -o uses.o
cycle.o:cycle.c cycle.h SeqList.h
	gcc -c cycle.c -o cycle.o
test.o: test.c SeqList.h cycle.h
	gcc -c test.c -o test.o
