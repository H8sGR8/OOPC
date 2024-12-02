libraries = matrix.h

sources = matrix.cpp testMatrix.cpp

executable = testMatrix

$(executable): $(libraries) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)
	
.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
