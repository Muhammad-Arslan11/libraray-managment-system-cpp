

#include <iostream>
#include <vector>
using namespace std;

// This is an interface class
// class Book
class Book
{
   // private data
   int id;
   string title;
   string author;
   string genre;
   bool available;

public:
   // constructor
public:
   Book() {}
   Book(int bookId, string bookTitle, string bookAuthor, string bookGenre);
   // add
   //  void addBook(int bookId, string bookTitle, string bookAuthor, string bookGenre);
   //   // remove
   //   // update
   //   void update(int bookId, string bookTitle, string bookAuthor, string bookGenre );

   // make a funtion to show inventory
   void inventory_of_books(vector<Book> &books);

   // getters
   int getId();
   string getTitle();
   string getAuthor();
   string getGenre();

   // setters
   void setId(int bookId);
   void setTitle(string bookTitle);
   void setAuthor(string bookAuthor);
   void setGenre(string bookGenre);

   // make Librarian class as friend class of Book so that it can access its data without any permission
   friend class Librarian;
};

// implementation for Book() constructor
// add book
Book::Book(int bookId, string bookTitle, string bookAuthor, string bookGenre)
{
   id = bookId;
   title = bookTitle;
   author = bookAuthor;
   genre = bookGenre;
}

// removeBook implementation

// updateBook implementation

// implementation for show inventory function
void Book:: inventory_of_books(vector<Book> &books){
   cout << "Inventory\n"
        << endl;
   for (auto &book : books)
   {
      cout << "ID:" << book.getId() << ", Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Genre: "
           << book.getGenre() << endl;
   }
}
// getters  implementation
int Book::getId() { return id; }
string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getGenre() { return genre; }

// setters implementation
void Book::setId(int bookId)
{
   id = bookId;
}
void Book::setTitle(string bookTitle)
{
   title = bookTitle;
}
void Book::setAuthor(string bookAuthor)
{
   author = bookAuthor;
}
void Book::setGenre(string bookGenre)
{
   genre = bookGenre;
}

// Librarian class
class Librarian : public Book
{

   // constructor for Librarian
public:
   Librarian() {}
   // create a vector for collection of books
   vector<Book> library;
   // addBook implementation
   void addBook(int bookId, string bookTitle, string bookAuthor, string bookGenre)
   {
      library.push_back(Book(bookId, bookTitle, bookAuthor, bookAuthor));
   }

   // remove
   void removeBook(int bookId, string bookTitle, string bookAuthor, string bookGenre){}
   // update
   void updateBook(int bookId, string bookTitle, string bookAuthor, string bookGenre){}
};

// Members class
class Members : public Book
{
};

int main()
{
   // create a collection of books here

   // add multiple books in the library
   // library.push_back(Book(001, "Power of Habits", "Charles Duhigg", "self-help"));

   // library.push_back(Book(002, "Dr.Faustus", "Cristopher Marlow", "Literatur"));
   // library.push_back(Book(004, "Compasque", "Robert Green", "Literatur"));
   // library.push_back(Book(004, "The Art of War", "Sun Tzu ", "War"));
   // library.push_back(Book(004, "The 33 Strategies of War", "Robert Green", "War"));

   Librarian librarian;
   Members memeber;
    
    // both memeber and librarian should be able to see inventory
     librarian.inventory_of_books();
     memeber.inventory_of_books();

   return 0;
};