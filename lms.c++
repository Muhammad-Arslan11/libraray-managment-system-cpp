

#include <iostream>
#include <vector>
#include <algorithm>
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
   bool available = true;

public:
   // constructor
   Book() {}
   Book(int bookId, string bookTitle, string bookAuthor, string bookGenre);

   // make a funtion to show inventory
   void show_inventory(vector<Book> &books);
   // make a function to show the availability of book
   void show_availability(int bookId, vector<Book>& library);

   // getters
public:
   int getId();
   string getTitle();
   string getAuthor();
   string getGenre();
   bool getAvailable();

   // setters
public:
   void setId(int bookId);
   void setTitle(string bookTitle);
   void setAuthor(string bookAuthor);
   void setGenre(string bookGenre);
   void setAvailable(bool boolean);

   // make Librarian class as friend class of Book so that it can access its data without any permission
   friend class Librarian;
};

// implementation for Book() constructor
Book::Book(int bookId, string bookTitle, string bookAuthor, string bookGenre)
{
   id = bookId;
   title = bookTitle;
   author = bookAuthor;
   genre = bookGenre;
}

// implementation for show inventory function
void Book::show_inventory(vector<Book> &books)
{
   cout << "Inventory\n"
        << endl;
   for (auto& book : books)
   {
      cout << "ID:" << book.getId() << ", Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Genre: "
           << book.getGenre() << endl;
   }
}

// implementation for show book function
// chatgpt code
void Book::show_availability(int bookId, vector<Book>& library)
{

   for (auto &book : library)
   {
      if (book.getId() == bookId)
      {
         cout << "Book ID: " << bookId << " is available." << endl;
         book.setAvailable(true);
         break;
      }
   }
   {
      std::cout << "Book ID: " << bookId << " is not available." << std::endl;
   }
   // chatgpt code
}

// getters  implementation
int Book::getId() { return id; }
string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getGenre() { return genre; }
bool Book::getAvailable() { return available; }

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
void Book::setAvailable(bool boolean)
{
   available = boolean;
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
      library.push_back(Book(bookId, bookTitle, bookAuthor, bookGenre));
   }

   // remove
   void removeBook(int bookId)
   {
      // chatgpt code
      library.erase(remove_if(library.begin(), library.end(),
                              [bookId](Book &book)
                              {
                                 return book.getId() == bookId;
                              }),
                    library.end());
      // chatgpt code
   }

   // show books
   void showBooks()
   {
      show_inventory(library);
   }
};

// Members class
class Members : public Book
{
      // maka a collection of books for the members
      vector<Book> collection;

   // constructor
public:
   Members(){}

   // borrow
   void borrow(int bookId, string bookTitle, string bookAuthor, string bookGenre,vector<Book>& library)
   {
      for (auto book : library)
      {
         if (bookId == book.getId())
         {
            // push the book from library into the member's collection
            collection.push_back(Book(bookId, bookTitle, bookAuthor, bookGenre));

                // delete or remove book from library collection
                library.erase(remove_if(library.begin(), library.end(),
                                        [bookId](Book &book)
                                        {
                                           return book.getId() == bookId;
                                        }),
                              library.end());
               // update availability
               book.setAvailable(false);
            
         }
         break;
      }
           
   }

   // view books
void
view_borrowed_books()
{
   cout << "Borrowed Books\n"
        << endl;
   for (auto &book : collection)
   {
      cout << "ID:" << book.getId() << ", Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Genre: "
           << book.getGenre() << endl;
   }
}
// return book
void return_book(int bookId, string bookTitle, string bookAuthor, string bookGenre, vector<Book> library)
{
   for(auto book : library){
      if(bookId == book.getId()){
        // push book into the library 
           library.push_back(Book(bookId, bookTitle, bookAuthor, bookGenre));

       // delete or remove book from collection
                collection.erase(remove_if(collection.begin(), collection.end(),
                [bookId](Book &book)
              {
              return book.getId() == bookId;
              }),
         collection.end());
      // update availability
           book.setAvailable(false);

}
break;
}
  
}


};



int main()
{

   Librarian librarian; // librarian instance
   Members member;  // member instance

   // add books in the inventory
   librarian.addBook(0, "12 Rules for life", "Jordan Peterson", "Self-help");
   librarian.addBook(1, "Laws of Human Nature", "Robert Green", "Self-help");
   librarian.addBook(2, "Crime and Punishment", "Dostoyevsky", "Psychological Novel");
   librarian.addBook(3, "1984", "George Orwell", "Fiction");
   librarian.addBook(4, "The Pleasures of Philosophy", "Betrand Russel", "Philosophy");
   librarian.addBook(5, "The Darling", "Anton Chekhov", "Fiction");
   librarian.addBook(6, "Brothers Karamazov", "Dostoyevsky", "Psychological Novel");
   librarian.addBook(7, "Hearts and Hands", "O'Henry", "Fiction");
   librarian.addBook(8, "Atomic Habits", "James Clear", "Discipline");
   librarian.addBook(9, "Pride and Prejudice", "Jane Austen", "Classic Novel");


   // remove book from the library
  
    librarian.showBooks();  // before removal
    librarian.removeBook(0);
     librarian.showBooks();  // after removal
   


 // test members methods
 // 1- show borrowed books
 member.view_borrowed_books();
 // 2- borrow book
  member.borrow(1, "Laws of Human Nature", "Robert Green", "Self-help");
   librarian.showBooks();  // after borrow
    member.view_borrowed_books();  // after borrow
    // 3- return book
  member.return_book(1, "Laws of Human Nature", "Robert Green", "Self-help");
   librarian.showBooks();  // after return 
   member.view_borrowed_books();  // after return
   

 

  
   
  


   // both memeber and librarian should be able to see inventory
   // librarian.show_inventory(&library);

   return 0;
};