target: p1.x p2.x p3.x p3.s

p1.x: p1.c
	gcc -o p1.x p1.c
p2.x: p2.c
	gcc -o p2.x p2.c

p3.s: p3.cpp
	g++ -std=c++11 -S -o p3.s p3.cpp

p3.x: p3.cpp
		g++ -std=c++11 -o p3.x p3.cpp
clean:
	rm *.x *.o

run3:
	make && ./p3.x
