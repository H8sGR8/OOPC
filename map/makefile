libraries = Books.h mapTemplate.h

sources = Books.cpp testMap.cpp

executable = testMap

$(executable): $(libraries) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)
	
.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)
