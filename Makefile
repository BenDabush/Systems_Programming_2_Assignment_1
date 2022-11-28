CC = gcc
AR = ar
CFLAGS = -g -Wall
ALL_OBJFILES = my_mat.c main.c
OBJECTS_MAIN = main.c my_mat.h

all : $(ALL_OBJFILES)

connections : my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

main.o : $(OBJECTS_MAIN)
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.a *.o