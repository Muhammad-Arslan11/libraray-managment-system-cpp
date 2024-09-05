 
 
To restrict the access of Member class instances to the methods of the Book class, you should reconsider your design and inheritance structure. Currently, your Member class inherits publicly from the Book class (`class Members : public Book`), which means it inherits all the public and protected members of the Book class, including its methods.

Here are a few approaches you can take to achieve your goal:

### 1. Composition Instead of Inheritance

Instead of inheriting from the Book class, you can use composition, where the Member class has a private member that is an instance of the Book class. This way, Member class instances will have access only to the public interface you define explicitly.

Here’s how you can refactor your Member class using composition:

```cpp
class Members {
private:
    vector<Book> collection;  // Collection of books

public:
    Members() {}

    void borrow(int bookId, string bookTitle, string bookAuthor, string bookGenre, vector<Book>& library) {
        // Implement borrow functionality using library vector directly
    }

    void view_borrowed_books() {
        // Implement viewing borrowed books
    }

    void return_book(int bookId, string bookTitle, string bookAuthor, string bookGenre, vector<Book>& library) {
        // Implement returning a book to the library
    }

    // Optionally, you can provide methods to interact with the collection
    void addBookToCollection(Book& book) {
        collection.push_back(book);
    }

    void removeBookFromCollection(int bookId) {
        collection.erase(remove_if(collection.begin(), collection.end(),
                                   [bookId](Book& book) {
                                       return book.getId() == bookId;
                                   }),
                         collection.end());
    }
};
```

In this approach:
- **Member class does not inherit from Book class.**
- Member class has its own collection of books (`vector<Book> collection`).
- Methods such as `borrow`, `view_borrowed_books`, and `return_book` operate on the library vector directly without needing inheritance.
- You have control over which methods and functionality are exposed by the Member class.

### 2. Private Inheritance with Friendship

If you still need some level of interaction with the Book class methods but want to restrict access to other parts, you could use private inheritance along with friendship. However, this approach is less common and should be used cautiously as it can lead to tighter coupling between classes.

Here’s an example:

```cpp
class Members : private Book {
    // Member class inherits privately from Book
    // Implement Member class methods and manage interactions with Book class through private inheritance
public:
    Members() {}

    // Define methods to interact with Book class as needed
};
```

### Conclusion

Using composition instead of inheritance is generally preferred when you want to restrict access to the functionality of another class while still maintaining some interaction. It promotes better encapsulation and reduces dependency between classes. Evaluate your design requirements carefully to choose the best approach for your specific use case.