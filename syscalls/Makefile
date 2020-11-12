all: main so
main: main.c
	gcc -o main ./main.c -ldl

so: A.c
	gcc -shared -fpic -o A.so A.c

clean:
	rm -f *.so main
