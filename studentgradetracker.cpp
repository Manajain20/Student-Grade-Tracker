#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;
 
//max number of students
const int MAX_STUDENTS = 100;
 
//to hold student data
struct Student {
    string name;
    float grades[5];   // Up to 5 subjects
    int subjectCount;
    float average;
    char letterGrade;
};
 
// Fn to get grade from average
char getLetterGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}
 
// Fn for average
float calculateAverage(float grades[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return sum / count;
}
 
// Fn to get valid grade input
float getValidGrade(int subjectNum) {
    float grade;
    while (true) {
        cout << "   Subject " << subjectNum << " marks (0-100): ";
        cin >> grade;
        if (cin.fail() || grade < 0 || grade > 100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Invalid! Enter marks between 0 and 100." << endl;
        } else {
            return grade;
        }
    }
}
 
// fn to add a student
void addStudent(Student students[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "\n Maximum student limit reached!" << endl;
        return;
    }
 
    Student s;
    cin.ignore();
    cout << "\n Enter student name: ";
    getline(cin, s.name);
 
    int numSubjects;
    cout << " How many subjects? (1-5): ";
    while (!(cin >> numSubjects) || numSubjects < 1 || numSubjects > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " Enter a number between 1 and 5: ";
    }
 
    s.subjectCount = numSubjects;
    cout << " Enter marks for each subject:" << endl;
    for (int i = 0; i < numSubjects; i++) {
        s.grades[i] = getValidGrade(i + 1);
    }
 
    s.average = calculateAverage(s.grades, s.subjectCount);
    s.letterGrade = getLetterGrade(s.average);
 
    students[count] = s;
    count++;
 
    cout << "\n Student \"" << s.name << "\" added successfully!" << endl;
}
 
// fn to display all students
void displayAll(Student students[], int count) {
    if (count == 0) {
        cout << "\n No students added yet." << endl;
        return;
    }
 
    cout << " " << left << setw(20) << "Name"
         << setw(12) << "Average"
         << setw(8)  << "Grade"
         << "Subjects" << endl;
 
    for (int i = 0; i < count; i++) {
        cout << " " << left << setw(20) << students[i].name
             << setw(12) << fixed << setprecision(2) << students[i].average
             << setw(8)  << students[i].letterGrade
             << students[i].subjectCount << " subject(s)" << endl;
    }
}
 
// fn to find topper
void findTopper(Student students[], int count) {
    if (count == 0) {
        cout << "\n No students to evaluate." << endl;
        return;
    }
 
    int topperIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].average > students[topperIndex].average) {
            topperIndex = i;
        }
    }
 
    cout << "\n Topper: " << students[topperIndex].name << endl;
    cout << "   Average: " << fixed << setprecision(2) << students[topperIndex].average << "%" << endl;
    cout << "   Grade  : " << students[topperIndex].letterGrade << endl;
}
 
// fn to search a student by name
void searchStudent(Student students[], int count) {
    if (count == 0) {
        cout << "\n No students added yet." << endl;
        return;
    }
 
    cin.ignore();
    string searchName;
    cout << "\n Enter student name to search: ";
    getline(cin, searchName);
 
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].name == searchName) {
            found = true;
            cout << " Name   : " << students[i].name << endl;
            cout << " Average: " << fixed << setprecision(2) << students[i].average << "%" << endl;
            cout << " Grade  : " << students[i].letterGrade << endl;
            cout << " Marks  : ";
            for (int j = 0; j < students[i].subjectCount; j++) {
                cout << students[i].grades[j];
                if (j < students[i].subjectCount - 1) cout << ", ";
            }
            break;
        }
    }
 
    if (!found) {
        cout << "\n Student \"" << searchName << "\" not found." << endl;
    }
}
 
// Display menu
void showMenu() {
    cout << "     STUDENT GRADE TRACKER    " << endl;
    cout << " 1. Add Student" << endl;
    cout << " 2. View All Students" << endl;
    cout << " 3. Find Topper" << endl;
    cout << " 4. Search Student" << endl;
    cout << " 5. Exit" << endl;
    cout << " Enter your choice: ";
}
 
int main() {
    cout << "\n Welcome to the Student Grade Tracker!" << endl;
 
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
 
    do {
        showMenu();
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Invalid choice. Enter 1-5: ";
        }
 
        switch (choice) {
            case 1: addStudent(students, studentCount); break;
            case 2: displayAll(students, studentCount); break;
            case 3: findTopper(students, studentCount); break;
            case 4: searchStudent(students, studentCount); break;
            case 5: cout << "\n Goodbye! Keep tracking those grades.\n" << endl; break;
        }
 
    } while (choice != 5);
 
    return 0;
}
 