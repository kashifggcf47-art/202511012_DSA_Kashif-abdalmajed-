#include <iostream>
#include <string>

using namespace std;


void checkResult(string name, double marks[], int numSubjects) {
    double total = 0;
    

    for (int i = 0; i < numSubjects; i++) {
        total += marks[i];
    }
    

    double average = total / numSubjects; 


    cout << "\n------ Result Report ------" << endl;
    cout << "Student Name: " << name << endl;
    cout << "Total Marks: " << total << "/" << (numSubjects * 100) << endl;
    cout << "Average: " << average << "%" << endl;
    

    if (average >= 50.0) {
        cout << "Status: PASSED" << endl;
    } else {
        cout << "Status: FAILED" << endl;
    }
    cout << "---------------------------\n" << endl;
}

int main() {

    string studentName;
    const int NUM_SUBJECTS = 3; 
    double marks[NUM_SUBJECTS];
    char choice;

    cout << "=== Student Result Management System ===" << endl;


    do {

        cout << "Enter student's name: ";
        cin.ignore();
        getline(cin, studentName);


        for (int i = 0; i < NUM_SUBJECTS; i++) {
            cout << "Enter marks for Subject " << (i + 1) << ": ";
            cin >> marks[i]; 
        }


        checkResult(studentName, marks, NUM_SUBJECTS);


        cout << "Do you want to enter another student? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the system!" << endl;
    return 0;
}
