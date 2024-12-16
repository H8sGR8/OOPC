#pragma once

#include <iostream>
using namespace std;

class Book {
  public:
	string title;
	string author;
	string isbn;
	string status;
	string no_of_pages;
	string year;
	Book(){};
	Book(string title, string author, string isbn,
	 string status, string no_of_pages, string year);
};

ostream& operator<<(ostream& out, Book& book);
