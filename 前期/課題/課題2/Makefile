CC = gcc
CFLAGS = -lm

OBJS = 課題2.o

.c.o:
	$(CC) $< -o $@ $(CFLAGS)
	./$(OBJS)

all: $(OBJS)

clean:
	rm -f *.o
