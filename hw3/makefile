.PHONY: dirs clean stat

all: bin/unit
	
bin/unit: dirs test/ut_main.cpp test/ut_cat.h src/cat.h
	g++ -std=c++11 test/ut_main.cpp -g -o bin/unit -lgtest -lpthread

dirs:
	mkdir -p bin

clean: dirs
	rm bin/*

stat:
	wc src/* test/*
