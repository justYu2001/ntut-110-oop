# This is the default target, which will be built when you invoke
.PHONY: all

all: hello ut_all
# This rule tells make how to build HelloWorld from
hello: HelloWorld.cpp
	g++ HelloWorld.cpp -o HelloWorld

ut_all: ut_main.cpp
	g++ -std=c++11 -Wfatal-errors ut_main.cpp -o ut_all -lgtest -lpthread
# This rule tells make to delete hello and hello.o
.PHONY: clean
clean:
	rm -f HelloWorld
	rm -f ut_all