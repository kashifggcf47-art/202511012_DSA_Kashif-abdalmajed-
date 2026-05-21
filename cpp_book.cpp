#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// إعلان الدوال (Prototypes)
void showMenu();
void displayHistory();
void displayConcepts();

int main() {
    int choice;

    do {
        showMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;

        // تنظيف الذاكرة المؤقتة بعد إدخال الرقم لكي تعمل قراءة الملفات بشكل صحيح
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

// دالة عرض قائمة الكتاب
void showMenu() {
    cout << "\n=============================================" << endl;
    cout << "  BOOK: Foundations and History of C++   " << endl;
    cout << "=============================================" << endl;
    cout << "[1] View History of C++" << endl;
    cout << "[2] Learn About C++ Concepts" << endl;
    cout << "[3] Exit Program" << endl;
    cout << "=============================================" << endl;
}

// دالة قراءة وعرض التاريخ من ملف خارجي
void displayHistory() {
    ifstream file("history.txt");
    string line;

    cout << "\n--- History of C++ ---" << endl;
    
    if (file.is_open()) {
        // قراءة الملف سطرًا بسطر حتى نهايته
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        // نص احتياطي (Hardcoded) في حال عدم وجود الملف كما سمح الواجب
        cout << "[Notice: history.txt not found. Showing default content]" << endl;
        cout << "C++ was created by Bjarne Stroustrup in 1979 at Bell Labs as an extension of C." << endl;
    }
}

// دالة قراءة وعرض المفاهيم من ملف خارجي
void displayConcepts() {
    ifstream file("concepts.txt");
    string line;

    cout << "\n--- C++ Programming Concepts ---" << endl;
    
    if (file.is_open()) {
        // قراءة الملف سطرًا بسطر حتى نهايته
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        // نص احتياطي
        cout << "[Notice: concepts.txt not found. Showing default content]" << endl;
        cout << "Concepts include: Data Types, Control Flow, Loops, Arrays, and File Streams." << endl;
    }
}