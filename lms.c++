

#include<iostream>
using namespace std;

   // This is an interface class
   // class Book
   class Book{
        // private data
        int id;
        string title;
        string author;
        string genre;
  
     // Now, this is an ambigious or prototype method. Meaning, it can have its declaration without implementation or initialization.
       // we can later decide its implementaion using scope resolution operator
       // add
       void addBook(int bookId, string bookTitle, string bookAuthor, string bookGenre);
        Book(int bookId, string bookTitle, string bookAuthor, string bookGenre);
        // remove
        // update
        
          

      // getters
       int  getId();    
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
  // Librarian class
   class Librarian : public Book{

    // addBook implementation
         void addBook(int bookId, string bookTitle, string bookAuthor, string bookGenre){
             Book(bookId,bookTitle,bookAuthor,bookGenre);
         }
   // remove
    void removeBook(int bookId, string bookTitle, string bookAuthor, string bookGenre);
   // update
    void updateBook(int bookId, string bookTitle, string bookAuthor, string bookGenre);
 
   
   };

        
        // implementation for Book() constructor 
        // add book
         Book:: Book(int bookId, string bookTitle, string bookAuthor, string bookGenre){
            id = bookId;
            title = bookTitle;
            author = bookAuthor;
            genre = bookGenre;
         }

        
          // removeBook implementation
          // updateBook implementation
        // getters  implementation
       int Book:: getId(){ return id; }    
       string Book:: getTitle(){ return title;}
       string Book:: getAuthor(){ return author;}
       string Book:: getGenre(){ return genre;}

       // setters implementation
    //    void Book::setId(int bookId){
    //        id = bookId;
    //    }
    //    void Book::setTitle(string bookTitle){
    //        title = bookTitle;
    //    }
    //    void Book:: setAuthor(string bookAuthor){
    //        author = bookAuthor;
    //    }
    //    void Book:: setGenre(string bookGenre){
    //        genre = bookGenre;
    //    }
           
    

   // Members class
   class Members : public Librarian{

   };

  
   int main(){

    return 0;
   };