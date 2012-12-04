CC = g++
CFLAGS = -Wall -Wextra

naughty_test:	question_three.cpp
	$(CC) $(CFLAGS) -o naughty_test question_three.cpp

clean:
	rm -f naughty_test
	rm -f *.o
	rm -f *~
