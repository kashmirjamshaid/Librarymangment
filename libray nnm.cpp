#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Define constants
const int MAX_BOOKS = 100;
const int MAX_TITLE_LENGTH = 100;

// Structure to represent a book
struct Book {
    char title[MAX_TITLE_LENGTH];
    char category[20];
};

// Function prototypes
void addBook(Book books[], int& count);
void searchBook(const Book books[], int count);
void removeBook(Book books[], int& count);

int main() {
	//program name
	cout<<"*********************************"<<endl;
	cout<<"**  Library Management System  **"<<endl;
	cout<<"*********************************"<<endl<<endl;
	cout<<"* Welcome to World of Knowledge *"<<endl<<endl;
	
    // Array to store books
    Book books[MAX_BOOKS];
    
    // Variable to keep track of the number of books
    int bookCount = 0;

    // Load existing data from file
    ifstream inputFile("library_data.txt");

    while (inputFile >> books[bookCount].title >> books[bookCount].category) {
        bookCount++;
    }

    inputFile.close();

    // Main menu
    int choice;

    do {
        // Display menu
        cout << " **************************\n";
		cout << " * 1. Add a Book          *\n";
        cout << " * 2. Search for a Book   *\n";
        cout << " * 3. Remove a Book       *\n";
        cout << " * 4. Exit                *\n";
        cout << " **************************\n"<<endl;
        // User input
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, bookCount);
                break;
            case 2:
                searchBook(books, bookCount);
                break;
            case 3:
                removeBook(books, bookCount);
                break;
            case 4:
                // Save data to file before exiting
                ofstream outputFile("library_data.txt");
                for (int i = 0; i < bookCount; ++i) {
                    outputFile << books[i].title << " " << books[i].category << "\n";
                }
                outputFile.close();
                cout << "Exiting the program.\n";
                cout << "*****************************************\n";
				cout << "** Programmed by K.G.H Tech Industries **\n";
                cout << "*****************************************\n"<<endl;
                cout << " Kashmir jamshaid(23-NTU-CS-1167)\n";
                cout << " Gulam Rasool    (23-NTU-CS-1159)\n";
                cout << " Haider Ali      (23-NTU-CS-1164)\n";
				break;
        
        }
    } while (choice != 4);

    return 0;
}

// Function to add a book
void addBook(Book books[], int& count) {
    if (count < MAX_BOOKS) {
        cout << "Enter book title: ";
        cin.ignore(); // Clear input buffer
        cin.getline(books[count].title, MAX_TITLE_LENGTH);

        cout << "Enter book category (CS, Business, Textile): ";
        cin >> books[count].category;

        cout << "Book added successfully.\n";
        count++;
    } else {
        cout << "Library is full. Cannot add more books.\n";
    }
}

// Function to search for a book
void searchBook(const Book books[], int count) {
    char searchTitle[MAX_TITLE_LENGTH];
    cout << "Enter the title to search: ";
    cin.ignore(); // Clear input buffer
    cin.getline(searchTitle, MAX_TITLE_LENGTH);

    bool found = false;

    for (int i = 0; i < count; ++i) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            cout << "Book found in category: " << books[i].category << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }
}

// Function to remove a book
void removeBook(Book books[], int& count) {
    char removeTitle[MAX_TITLE_LENGTH];
    cout << "Enter the title to remove: ";
    cin.ignore(); // Clear input buffer
    cin.getline(removeTitle, MAX_TITLE_LENGTH);

    bool found = false;

    for (int i = 0; i < count; ++i) {
        if (strcmp(books[i].title, removeTitle) == 0) {
            // Remove the book by shifting the remaining books
            for (int j = i; j < count - 1; ++j) {
                strcpy(books[j].title, books[j + 1].title);
                strcpy(books[j].category, books[j + 1].category);
            }
            count--;
            cout << "Book removed successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }
}
