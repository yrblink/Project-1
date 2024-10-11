//  Ifeanyi Ugwuoke
//  main.cpp
//  Project 1

#include "Course.h"
#include <sstream>
#include <iostream>
using namespace std;
int main() 
    {
    Course courseList;
    string courseCode;
    int grade, creditHours;

    cout << "Enter 10 courses (course code, grade, credit hours):" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Course " << i + 1 << " code: ";
        cin >> ws;
        getline(cin, courseCode);

        cout << "Course " << i + 1 << " grade: ";
        cin >> grade;

        cout << "Course " << i + 1 << " credit hours: ";
        cin >> creditHours;

        courseList.addCourse(courseCode, grade, creditHours);
    }

    cout << "Courses before deletions:" << endl;
    courseList.displayList();

    cout << "Enter the course code of the course you want to delete: ";
    cin >> ws;
    getline(cin, courseCode);
    courseList.deleteCourse(courseCode);

    cout << "Courses after first deletion:" << endl;
    courseList.displayList();

    cout << "Enter the course code of another course you want to delete: ";
    cin >> ws;
    getline(cin, courseCode);
    courseList.deleteCourse(courseCode);

    cout << "Courses after second deletion:" << endl;
    courseList.displayList();

    return 0;
}
