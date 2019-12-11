//============================================================================
// File Name   : StudentCourses.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================
#include "StudentCourses.h"

Student StudentCourses::get_student() const { return student; }

double StudentCourses::get_final_score() {
	return courses.get_final_score();
}

void StudentCourses::display() {
	student.display();
	courses.display();
}

bool StudentCourses::operator<=(StudentCourses sc) {
	string s1 = student.get_last_name() + student.get_first_name() + student.get_id();
	string s2 = sc.get_student().get_last_name() + sc.get_student().get_first_name() + sc.get_student().get_id();
	if (s1 <= s2)
		return true;
	else
		return false;
}

Courses StudentCourses::get_courses() const{
	return courses;
}