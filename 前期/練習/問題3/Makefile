CC = gcc

OBJS = practice3.o

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	./$(OBJS)

all: $(OBJS)

clean:
	rm -f *.o
