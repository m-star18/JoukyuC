CC = gcc

OBJS = 課題3.o

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	./$(OBJS)

all: $(OBJS)

clean:
	rm -f *.o
