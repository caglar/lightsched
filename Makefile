all: test
scheduler.o:
	g++ -c scheduler.cc
test.o:
	g++ -c test.cc
test: test.o scheduler.o
	g++ test.o scheduler.o -o test
clean:
	rm -rf *.o test
