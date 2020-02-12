CC = g++
CFLAGS =
COPTFLAGS = -O3 -g
LDFLAGS =




queue_test: queue_test.o queue.o timer.o
	$(CC) $(COPTFLAGS) -o $@ $^


dlist_test: dlist_test.o dlist.o timer.o
	$(CC) $(COPTFLAGS) -o $@ $^

%.o: %.cc
	$(CC) $(CFLAGS) $(COPTFLAGS) -o $@ -c $<

clean:
	rm -f core *.o

# eof
