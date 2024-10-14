libraries = stack.h test_allocation.h

sources = stack.c test_stack.c test_allocation.c

executable = test_stack

$(executable): $(libraries) $(sources)
	gcc -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)

.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
