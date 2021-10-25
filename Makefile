CC = gcc
CFLAGS = -I.

DEPS = linkedlist.h
OBJ = main.o linkedlist.o
MAIN = main.exe

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)


$(MAIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o $(MAIN)
