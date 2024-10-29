libraries = complex_numbers.h

sources = complex_numbers.cpp test_complex_numbers.cpp

executable = test_complex_numbers

$(executable): $(libraries) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)
