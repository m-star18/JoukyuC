CC = gcc

OBJS = 課題7.o

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	./$(OBJS)

all: $(OBJS)

clean:
	rm -f *.o
