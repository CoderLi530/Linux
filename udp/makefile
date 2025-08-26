.PHONY:all
all:udpserver debug udpclient
udpserver:main.cc
	g++ -o $@ $^ -std=c++11 

debug:main.cc
	g++ -o $@ $^ -g -std=c++11 -Wall

udpclient:udpclient.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f udpserver debug udpclient
