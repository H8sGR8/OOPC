libraries = poly.h

sources = poly.cpp test_poly.cpp

executable = test_poly

$(executable): $(libraries) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)
	
.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
