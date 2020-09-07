CC = gcc
LIBS = -lcrypt
OUTNAME = trip
OBJ = trip.o cli.o

%.o: %.c
	$(CC) -c $? -O3 -o $@
all: $(OBJ)
	$(CC) $(LIBS) $? -o $(OUTNAME)
clean:
	rm *.o
cleana:
	rm *.o $(OUTNAME)
