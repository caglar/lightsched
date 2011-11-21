LIBS= -g -Wall -pthread -O2
all: test
scheduler.o:
	g++ -c $(LIBS) scheduler.cc
test.o:
	g++ -c $(LIBS) test.cc
test: test.o scheduler.o
	g++ $(LIBS) test.o scheduler.o -o test
clean:
	rm -rf *.o test
