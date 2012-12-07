CC = g++
CFLAGS = -Wall -Wextra

tweet_test: question_five.cpp
	$(CC) $(CFLAGS) -o tweet_test question_five.cpp

naughty_test:	question_three.cpp Entry.o
	$(CC) $(CFLAGS) -o naughty_test question_three.cpp Entry.o

Entry.o: Entry.h Entry.cpp
	$(CC) $(CFLAGS) -c Entry.cpp

clean:
	rm -f naughty_test
	rm -f tweet_test
	rm -f *.o
	rm -f *~
