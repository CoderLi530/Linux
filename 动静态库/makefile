static-lib = libmath.a
dy-lib = libmethod.so 

.PHONY:all
all: $(static-lib) $(dy-lib)

$(static-lib):math.o
	ar rc $@ $^
math.o:math.c
	gcc -c $^

$(dy-lib):log.o print.o
	gcc -shared -o $@ $^
log.o:log.c
	gcc -fPIC -c $^
print.o:print.c
	gcc -fPIC -c $^

.PHONY:clean
clean:
	rm -rf *.a *.o *.so mylib

.PHONY:output
output:
	mkdir -p mylib/include
	mkdir -p mylib/lib
	cp *.a mylib/lib 
	cp *.so mylib/lib
	cp *.h mylib/include

