#include "mapTemplate.h"
#include "Books.h"

int main(){
	Map<int, Book> Library;
	Library.add(1, Book("The C++ Programming Language", "Bjarne Stroustrup", "978-0-321-99278-9", "AVAILABLE", "1368", "2013"));
    Library.add(2, Book("Effective Java", "Joshua Bloch", "978-1-118-05741-4", "BORROWED", "416", "2008"));
    Library.add(3, Book("Design Patterns: Elements of Reusable Object-Oriented Software", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides", "978-0-596-52068-7", "RESERVED", "395", "1994"));
    Library.add(4, Book("The Art of Computer Programming", "Donald Knuth", "978-0-201-63361-0", "AVAILABLE", "672", "1968"));
    Library.add(5, Book("Eloquent JavaScript", "Marijn Haverbeke", "978-1-59327-599-0", "AVAILABLE", "472", "2018"));
    Library.add(6, Book("Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", "978-0-13-235088-4", "BORROWED", "464", "2008"));
    Library.add(7, Book("Introduction to Algorithms", "Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein", "978-0-262-03384-8", "AVAILABLE", "1312", "2009"));
    Library.add(8, Book("You Don't Know JS: Scope & Closures", "Kyle Simpson", "978-1-4919-5641-2", "RESERVED", "98", "2014"));
    Library.add(9, Book("The Pragmatic Programmer", "Andrew Hunt, David Thomas", "978-0-201-61622-4", "AVAILABLE", "352", "1999"));
    Library.add(10, Book("Refactoring: Improving the Design of Existing Code", "Martin Fowler", "978-0-201-48567-7", "BORROWED", "431", "1999"));
    Library.add(11, Book("Code Complete: A Practical Handbook of Software Construction", "Steve McConnell", "978-0-7356-1967-8", "RESERVED", "960", "2004"));
    Library.add(12, Book("The Mythical Man-Month: Essays on Software Engineering", "Frederick P. Brooks Jr.", "978-0-201-83595-3", "AVAILABLE", "336", "1975"));
    Library.add(13, Book("Algorithms", "Robert Sedgewick, Kevin Wayne", "978-0-321-57351-3", "BORROWED", "992", "2011"));
    cout << Library << endl;
    
    cout << "Size of map is: " << Library.size() << "\n" << endl;
    
    cout << "Is empty?: " << ((Library.empty())? "true" : "false") << "\n" << endl;
    
    Library.erase(10);
    cout << "Size of map is: " << Library.size() << "\n" << endl;
    cout << Library << endl;
    
    Library.clear();
    cout << "Is empty?: " << ((Library.empty())? "true" : "false") << "\n" << endl;
    
    Library[10] = Book("Refactoring: Improving the Design of Existing Code", "Martin Fowler", "978-0-201-48567-7", "BORROWED", "431", "1999");
    cout << Library << endl;
    
    Library.find(10)->year = "2010";
    cout << Library << endl;
    
}
