#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        issued = false;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "\nBook Added Successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo Books Available.\n";
            return;
        }

        cout << "\n========== BOOK LIST ==========\n";

        for (int i = 0; i < books.size(); i++) {
            cout << "\nBook ID : " << books[i].id;
            cout << "\nTitle   : " << books[i].title;
            cout << "\nAuthor  : " << books[i].author;
            cout << "\nStatus  : " << (books[i].issued ? "Issued" : "Available");
            cout << "\n-----------------------------";
        }
    }

    void searchBook() {
        int id;
        cout << "\nEnter Book ID to Search: ";
        cin >> id;

        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                cout << "\nBook Found!";
                cout << "\nTitle  : " << books[i].title;
                cout << "\nAuthor : " << books[i].author;
                cout << "\nStatus : " << (books[i].issued ? "Issued" : "Available") << endl;
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }

    void issueBook() {
        int id;
        cout << "\nEnter Book ID to Issue: ";
        cin >> id;

        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                if (!books[i].issued) {
                    books[i].issued = true;
                    cout << "\nBook Issued Successfully!\n";
                } else {
                    cout << "\nBook Already Issued!\n";
                }
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }

    void returnBook() {
        int id;
        cout << "\nEnter Book ID to Return: ";
        cin >> id;

        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                if (books[i].issued) {
                    books[i].issued = false;
                    cout << "\nBook Returned Successfully!\n";
                } else {
                    cout << "\nThis Book Was Not Issued.\n";
                }
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }

    void deleteBook() {
        int id;
        cout << "\nEnter Book ID to Delete: ";
        cin >> id;

        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                books.erase(books.begin() + i);
                cout << "\nBook Deleted Successfully!\n";
                return;
            }
        }

        cout << "\nBook Not Found!\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n===================================";
        cout << "\n   LIBRARY MANAGEMENT SYSTEM";
        cout << "\n===================================";
        cout << "\n1. Add Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Delete Book";
        cout << "\n7. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.issueBook();
                break;

            case 5:
                library.returnBook();
                break;

            case 6:
                library.deleteBook();
                break;

            case 7:
                cout << "\nThank You for Using Library Management System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 7);

    return 0;
}
