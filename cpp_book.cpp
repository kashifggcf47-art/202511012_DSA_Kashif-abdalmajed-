#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void showMenu();
void displayHistory();
void displayConcepts();

int main() {
    int choice;

    do {
        showMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;


        cin.ignore(); 

        switch (choice) {
            case 1:
                displayHistory();
                break;
            case 2:
                displayConcepts();
                break;
            case 3:
                cout << "\nExiting the book system. Happy Learning!" << endl;
                break;
            default:
                cout << "\nInvalid Choice. Please select 1, 2, or 3." << endl;
        }
    } while (choice != 3);

    return 0;
}


void showMenu() {
    cout << "\n=============================================" << endl;
    cout << "  BOOK: Foundations and History of C++   " << endl;
    cout << "=============================================" << endl;
    cout << "[1] View History of C++" << endl;
    cout << "[2] Learn About C++ Concepts" << endl;
    cout << "[3] Exit Program" << endl;
    cout << "=============================================" << endl;
}

void displayHistory() {
    ifstream file("history.txt");
    string line;

    cout << "\n--- History of C++ ---" << endl;
    
    if (file.is_open()) {

        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {

        cout << "[Notice: history.txt not found. Showing default content]" << endl;
        cout << "C++ was created by Bjarne Stroustrup in 1979 at Bell Labs as an extension of C." << endl;
    }
}


void displayConcepts() {
    ifstream file("concepts.txt");
    string line;

    cout << "\n--- C++ Programming Concepts ---" << endl;
    
    if (file.is_open()) {

        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {

        cout << "[Notice: concepts.txt not found. Showing default content]" << endl;
        cout << "Concepts include: Data Types, Control Flow, Loops, Arrays, and File Streams." << endl;
    }
}
