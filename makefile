target: p1.x p2.x
p1.x: p1.c
	gcc -o p1.x p1.c
p2.x: p2.c
	gcc -o p2.x p2.c

clean:
	rm *.out *.x ~*