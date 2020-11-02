CC = gcc
CFLAGS = -lm

OBJS = question2.o

.c.o:
	$(CC) $< -o $@ $(CFLAGS)
	./$(OBJS)

all: $(OBJS)

clean:
	rm -f *.o
