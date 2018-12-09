all: sharemem.o
	gcc sharemem.o
run:
	./a.out
clean:
	rm *.o
	rm *.out
sharemem.o: sharemem.c
	gcc -c sharemem.c
