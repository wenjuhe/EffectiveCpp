CC = g++ -std=c++14
CFLAGS = -g -Wall

introduction:
	$(CC) $(CFLAGS) -o introduction introduction.cpp
clean:
	rm -f introduction *.o