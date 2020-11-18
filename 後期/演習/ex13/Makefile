CC = gcc

OBJS = ex13.o

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	./$(OBJS)

all: $(OBJS)

clean:
	rm -f *.o
