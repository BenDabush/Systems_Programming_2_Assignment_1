CC = gcc
AR = ar
CFLAGS = -g -Wall
ALL_OBJFILES = my_mat.o main.o
OBJECTS_MAIN = main.c my_mat.h
MY_MAT_OBJECTS = my_mat.c my_mat.h
CONNECTIONS = connections

all : $(CONNECTIONS)
	
$(CONNECTIONS) : $(ALL_OBJFILES)
	$(CC) $(CFLAGS) $(ALL_OBJFILES) -o $(CONNECTIONS)

main.o : $(OBJECTS_MAIN)
	$(CC) $(CFLAGS) -c main.c

my_mat.o : $(MY_MAT_OBJECTS)
	$(CC) $(CFLAGS) -c my_mat.c


.PHONY: clean all

clean:
	rm -f *.o $(ALL_OBJFILES) $(CONNECTIONS)