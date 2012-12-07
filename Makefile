CC = g++
CFLAGS = -Wall -Wextra

all: tweet_parse naughty

tweet_parse: question_five.cpp
	$(CC) $(CFLAGS) -o tweet_parse question_five.cpp

naughty: question_three.cpp
	$(CC) $(CFLAGS) -o naughty question_three.cpp

clean:
	rm -f lexical_analysis
	rm -f ranked_list
	rm -f naughty
	rm -f tweet_parse
	rm -f *.o
	rm -f *~
