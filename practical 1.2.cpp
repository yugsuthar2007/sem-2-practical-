#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Book {
private:
    int id;
    string title;
    string author;
    int copies;

public:
    
    Book(int id, string title, string author, int copies) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->copies = copies;
    }

    int getId() { return id; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getCopies() { return copies; }

    bool issueBook() {
        if (copies > 0) {
            copies--;
            return true;
        }
        return false;
    }

    void returnBook() {
        copies++;
    }

    void display() {
        cout << "ID: " << id 
             << ", Title: " << title 
             << ", Author: " << author 
             << ", Copies: " << copies << endl;
    }
};

class User {
private:
    int userId;
    string name;

public:
    User(int id, string name) {
        this->userId = id;
        this->name = name;
    }

    int getUserId() { return userId; }
    string getName() { return name; }
};

class IssueRecord {
public:
    int bookId;
    int userId;
    int dueDays;
    int lateDays;

    IssueRecord(int bId, int uId, int dueDays) {
        this->bookId = bId;
        this->userId = uId;
        this->dueDays = dueDays;
        this->lateDays = 0;
    }

    int calculateFine() {
        return lateDays * 5;
};

class Library {
private:
    vector<Book> books;
    vector<User> users;
    vector<IssueRecord> records;

public:
  
    void addBook(int id, string title, string author, int copies) {
        books.push_back(Book(id, title, author, copies));
        cout << "Book added successfully!\n";
    }

   
    void addUser(int id, string name) {
        users.push_back(User(id, name));
        cout << "User added successfully!\n";
    }

    
    void displayBooks() {
        for (auto &b : books) {
            b.display();
        }
    }

   
    void searchByTitle(string title) {
        for (auto &b : books) {
            if (b.getTitle() == title) {
                b.display();
                return;
            }
        }
        cout << "Book not found\n";
    }

    
    void searchByAuthor(string author) {
        bool found = false;
        for (auto &b : books) {
            if (b.getAuthor() == author) {
                b.display();
                found = true;
            }
        }
        if (!found) cout << "No books found\n";
    }

  
    void issueBook(int bookId, int userId, int dueDays) {
        for (auto &b : books) {
            if (b.getId() == bookId) {
                if (b.issueBook()) {
                    records.push_back(IssueRecord(bookId, userId, dueDays));
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "No copies available\n";
                }
                return;
            }
        }
        cout << "Book not found\n";
    }

    void returnBook(int bookId, int lateDays) {
        for (auto &b : books) {
            if (b.getId() == bookId) {
                b.returnBook();

                for (auto &r : records) {
                    if (r.bookId == bookId) {
                        r.lateDays = lateDays;
                        cout << "Book returned!\n";
                        cout << "Fine: ₹" << r.calculateFine() << endl;
                        return;
                    }
                }
            }
        }
        cout << "Invalid return\n";
    }

    
    void totalBooks() {
        cout << "Total books: " << books.size() << endl;
    }
};

int main() {
    Library lib;

    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Add User\n";
        cout << "3. Display Books\n";
        cout << "4. Search by Title\n";
        cout << "5. Search by Author\n";
        cout << "6. Issue Book\n";
        cout << "7. Return Book\n";
        cout << "8. Total Books\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, copies;
            string title, author;
            cout << "Enter ID, Title, Author, Copies: ";
            cin >> id >> title >> author >> copies;
            lib.addBook(id, title, author, copies);
        }
        else if (choice == 2) {
            int id;
            string name;
            cout << "Enter User ID and Name: ";
            cin >> id >> name;
            lib.addUser(id, name);
        }
        else if (choice == 3) {
            lib.displayBooks();
        }
        else if (choice == 4) {
            string title;
            cout << "Enter title: ";
            cin >> title;
            lib.searchByTitle(title);
        }
        else if (choice == 5) {
            string author;
            cout << "Enter author: ";
            cin >> author;
            lib.searchByAuthor(author);
        }
        else if (choice == 6) {
            int bookId, userId, days;
            cout << "Enter Book ID, User ID, Due Days: ";
            cin >> bookId >> userId >> days;
            lib.issueBook(bookId, userId, days);
        }
        else if (choice == 7) {
            int bookId, lateDays;
            cout << "Enter Book ID and Late Days: ";
            cin >> bookId >> lateDays;
            lib.returnBook(bookId, lateDays);
        }
        else if (choice == 8) {
            lib.totalBooks();
        }

    } while (choice != 0);

    return 0;
}