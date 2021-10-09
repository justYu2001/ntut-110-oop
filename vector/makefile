.PHONY: all
all: bin/test

bin/vector: src/vector.cpp src/length.h
	g++ src/vector.cpp -o bin/vector

bin/test: test/ut.cpp test/length_test.h bin
	g++ -std=c++11 test/ut.cpp -o bin/ut_all -lgtest -lpthread

.PHONY: bin
bin:
	mkdir -p bin

.PHONY: clean
clean:
	rm -f bin/*