.PHONY: install build test clean
all: run_test_exec1 run_test_exec2
	valgrind --leak-check=full ./run_test_exec1
	valgrind --leak-check=full ./run_test_exec2
run_test_exec1: ex_test1.o ex1.o
	gcc -I . -std=c99 -g -O0 $^ -o $@ 
run_test_exec2: ex1.o ex_test2.o ex2.o link.o
	gcc -I . -std=c99 -g -O0 $^ -o $@ 
%.o: %.c
	gcc -I . -c -std=c99 -g -O0 $< -o $@
clean:
	rm -f *.o *.c~ *.h~ *.h.gch run_test_exec1 a.out Makefile~ run_test_exec2
