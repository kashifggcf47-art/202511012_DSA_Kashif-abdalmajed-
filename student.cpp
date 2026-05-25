#include <iostream>
#include "student.h"

using namespace std;

const int MAX_STUDENTS = 100;
Student studentList[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "\n[Error] Student database is full!\n";
        return;
    }

    Student s;
    cout << "\n--- Add New Student ---\n";
    cout << "Enter Student ID: ";
    cin >> s.id;
    
    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == s.id) {
            cout << "[Error] This Student ID already exists!\n";
            return;
        }
    }

    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter Course: ";
    getline(cin, s.course);

    studentList[studentCount] = s;
    studentCount++;
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (studentCount == 0) {
        cout << "\nNo students registered in the system.\n";
        return;
    }

    cout << "\n--- Registered Students List ---\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << studentList[i].id 
             << " | Name: " << studentList[i].name 
             << " | Age: " << studentList[i].age 
             << " | Course: " << studentList[i].course << endl;
    }
}

void searchStudent() {
    if (studentCount == 0) {
        cout << "\nDatabase is empty. No student to search.\n";
        return;
    }

    int searchId;
    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == searchId) {
            cout << "\n[Student Found]:\n";
            cout << "Name: " << studentList[i].name << endl;
            cout << "Age: " << studentList[i].age << endl;
            cout << "Course: " << studentList[i].course << endl;
            return;
        }
    }
    cout << "Sorry, student with ID " << searchId << " not found.\n";
}

void updateStudent() {
    if (studentCount == 0) {
        cout << "\nNo students available to update.\n";
        return;
    }

    int updateId;
    cout << "\nEnter Student ID to update: ";
    cin >> updateId;

    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == updateId) {
            cout << "\nCurrent Name: " << studentList[i].name << endl;
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, studentList[i].name);
            cout << "Enter New Age: ";
            cin >> studentList[i].age;
            cin.ignore();
            cout << "Enter New Course: ";
            getline(cin, studentList[i].course);
            
            cout << "Student details updated successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    if (studentCount == 0) {
        cout << "\nNo students available to delete.\n";
        return;
    }

    int deleteId;
    cout << "\nEnter Student ID to delete: ";
    cin >> deleteId;

    for (int i = 0; i < studentCount; i++) {
        if (studentList[i].id == deleteId) {

            for (int j = i; j < studentCount - 1; j++) {
                studentList[j] = studentList[j + 1];
            }
            studentCount--;
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
