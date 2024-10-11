//  Ifeanyi Ugwuoke
//  Course.cpp
//  Project 1

#include <sstream>
#include <iostream>
#include "Course.h"
#include <stdio.h>
using namespace std;

Course::Course() {
    head = nullptr;
}

Course::~Course() {
    deleteAllNodes();
}

int Course::extractCourseNumber(const string& courseCode) const {
    stringstream ss(courseCode);
    string prefix;
    int number;
    ss >> prefix >> number;
    return number;
}

void Course::addCourse(const string& courseCode, int grade, int creditHours) {
    CourseNode* newNode = new CourseNode;
    newNode->courseCode = courseCode;
    newNode->grade = grade;
    newNode->creditHours = creditHours;
    newNode->next = nullptr;

    int newCourseNum = extractCourseNumber(courseCode);

    if (!head || extractCourseNumber(head->courseCode) >= newCourseNum) {
        newNode->next = head;
        head = newNode;
    } else {
        CourseNode* prevPtr = head;
        CourseNode* nodePtr = head->next;

        while (nodePtr && extractCourseNumber(nodePtr->courseCode) < newCourseNum) {
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        newNode->next = nodePtr;
        prevPtr->next = newNode;
    }
}

void Course::deleteCourse(const string& courseCode) {
    if (!head) {
        cout << "The list is empty. No course to delete." << endl;
        return;
    }

    CourseNode* nodePtr = head;
    CourseNode* prevPtr = nullptr;
    int courseNum = extractCourseNumber(courseCode);

    if (extractCourseNumber(head->courseCode) == courseNum) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {
        while (nodePtr && extractCourseNumber(nodePtr->courseCode) != courseNum) {
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr) {
            prevPtr->next = nodePtr->next;
            delete nodePtr;
        } else {
            cout << "Course not found." << endl;
        }
    }
}

void Course::deleteAllNodes() {
    while (head) {
        CourseNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void Course::displayList() const {
    if (!head) {
        cout << "The list is empty." << endl;
        return;
    }

    CourseNode* nodePtr = head;
    while (nodePtr) {
        cout << nodePtr->courseCode << " - Grade: " << nodePtr->grade
             << ", Credit Hours: " << nodePtr->creditHours << endl;
        nodePtr = nodePtr->next;
    }
}
