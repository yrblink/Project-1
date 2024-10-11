//  Ifeanyi Ugwuoke
//  Course.h
//  Project 1
//

#ifndef Course_h
#define Course_h
#include <string>
using namespace std;
class Course {
private:
    // Struct definition inside the Course class
    struct CourseNode {
        string courseCode;
        int creditHours;
        int grade;
        CourseNode* next;
    };

    CourseNode* head;

    int extractCourseNumber(const string& courseCode) const;

public:
    Course();
    ~Course();
    void addCourse(const string& courseCode, int grade, int creditHours);
    void deleteCourse(const string& courseCode);
    void deleteAllNodes();
    void displayList() const;
};


#endif /* Course_h */
