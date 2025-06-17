.PHONY:all
all:processa processb

processa:processa.cpp
	g++ -o $@ $^ -std=c++11
processb:processb.cpp
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm processa processb