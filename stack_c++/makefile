libraries = stack.h

sources = stack.cpp test_stack.cpp

executable = test_stack

$(executable): $(libraries) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)
	
.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
