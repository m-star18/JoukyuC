CC = gcc

OBJS = practice4.o

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	./$(OBJS)

all: $(OBJS)

clean:
	rm -f *.o
