CC = g++
CFLAGS = -Wall -Wextra

tweet_parse: question_five.cpp
	$(CC) $(CFLAGS) -o tweet_parse question_five.cpp

naughty: question_three.cpp Entry.o
	$(CC) $(CFLAGS) -o naughty question_three.cpp Entry.o

Entry.o: Entry.h Entry.cpp
	$(CC) $(CFLAGS) -c Entry.cpp

clean:
	rm -f output.txt
	rm -f naughty
	rm -f tweet_parse
	rm -f *.o
	rm -f *~
