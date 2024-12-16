#include "Books.h"

Book::Book(string title, string author, string isbn,
   string status, string no_of_pages, string year)
: title(title), author(author), isbn(isbn), status(status),
  no_of_pages(no_of_pages), year(year)
{
}

ostream& operator<<(ostream& out,  Book& book)
{
out << "Title: " << book.title << ", ";
out << "Author: " << book.author << ", ";
out << "ISBN: " << book.isbn << ", ";
out << "Status: " << book.status << ", ";
out << "Number of pages: " << book.no_of_pages << ", ";
out << "Publication date: " << book.year;
return out;
}
