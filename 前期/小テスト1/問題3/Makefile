CC = gcc
CFLAGS = -lm

OBJS = question3.o

.c.o:
	$(CC) $< -o $@ $(CFLAGS)
	./$(OBJS)

all: $(OBJS)

clean:
	rm -f *.o
