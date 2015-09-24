
all: testformat.c weatherio.c headerstructs.c
	gcc -o testformat testformat.c weatherio.c headerstructs.c

clean:
	rm *.o testformat