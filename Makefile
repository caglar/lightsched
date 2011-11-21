LIBS= -g -Wall -pthread -O2
all: test2 test
scheduler.o:
	g++ -c $(LIBS) scheduler.cc
test2.o:
	g++ -c $(LIBS) test2.cc
test2: test2.o scheduler.o
	g++ $(LIBS) test2.o scheduler.o -o test2
test.o:
	g++ -c $(LIBS) test.cc
test: test.o scheduler.o
	g++ $(LIBS) test.o scheduler.o -o test
clean:
	rm -rf *.o test2 test
