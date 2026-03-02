#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool issued;

public:
    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        issued = false;
    }

    int getId() const {
        return id;
    }

    void display() const {
        cout << "ID: " << id
             << ", Title: " << title
             << ", Author: " << author
             << ", Status: " << (issued ? "Issued" : "Available")
             << endl;
    }

    void issueBook() {
        if (!issued) {
            issued = true;
            cout << "Book issued successfully.\n";
        } else {
            cout << "Book already issued.\n";
        }
    }

    void returnBook() {
        if (issued) {
            issued = false;
            cout << "Book returned successfully.\n";
        } else {
            cout << "Book was not issued.\n";
        }
    }
};

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\n==== Library Management System ====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;

            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            library.push_back(Book(id, title, author));
            cout << "Book added successfully!\n";
        }

        else if (choice == 2) {
            if (library.empty()) {
                cout << "No books available.\n";
            } else {
                for (const auto &b : library) {
                    b.display();
                }
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to issue: ";
            cin >> id;

            bool found = false;
            for (auto &b : library) {
                if (b.getId() == id) {
                    b.issueBook();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found.\n";
        }

        else if (choice == 4) {
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;

            bool found = false;
            for (auto &b : library) {
                if (b.getId() == id) {
                    b.returnBook();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found.\n";
        }

        else if (choice == 5) {
            cout << "Exiting system...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
