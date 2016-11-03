main: main.c
	gcc main.c -o helperino
run:
	./helperino
clean:	
	rm helperino
	rm *~
	rm *#
