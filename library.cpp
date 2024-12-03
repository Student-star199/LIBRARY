#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    // Constructor
    Book() : isAvailable(true) {}

    // Method to set book details
    void setBookDetails(const string& t, const string& a, const string& i) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = true;
    }

    // Method to display book details
    void displayBookDetails() {
        cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << isbn;
        cout << "\nAvailability: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }

    // Method to borrow the book
    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book successfully borrowed.\n";
            return true;
        } else {
            cout << "The book is already borrowed.\n";
            return false;
        }
    }

    // Method to return the book
    void returnBook() {
        isAvailable = true;
        cout << "Book successfully returned.\n";
    }

    // Method to get the book's ISBN
    string getISBN() {
        return isbn;
    }
};

int main() {
    Book library[5];

    // Initialize book details
    library[0].setBookDetails("Book A", "Author A", "123");
    library[1].setBookDetails("Book B", "Author B", "456");
    library[2].setBookDetails("Book C", "Author C", "789");
    library[3].setBookDetails("Book D", "Author D", "012");
    library[4].setBookDetails("Book E", "Author E", "345");

    string isbn;
    while (true) {
        cout << "\nEnter the ISBN of the book you want to borrow (or '0' to exit): ";
        cin >> isbn;
        if (isbn == "0") break;

        bool found = false;
        for (int i = 0; i < 5; ++i) {
            if (library[i].getISBN() == isbn) {
                found = true;
                library[i].borrowBook();
                break;
            }
        }
        if (!found) {
            cout << "ISBN not found in the library.\n";
        }
    }
    return 0;
}
