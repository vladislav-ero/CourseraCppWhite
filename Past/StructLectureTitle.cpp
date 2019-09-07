#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    string specialization;
    explicit Specialization(const string& new_specialization) {
        specialization = new_specialization;
    }
};

struct Course {
    string course;
    explicit Course(const string& new_course) {
        course = new_course;
    }
};

struct Week {
    string week;
    explicit Week(const string& new_week) {
        week = new_week;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(const Specialization& new_spec,
                 const Course& new_course,
                 const Week& new_week) {
        specialization = new_spec.specialization;
        course = new_course.course;
        week = new_week.week;
    }
};

int main() {
    
}
