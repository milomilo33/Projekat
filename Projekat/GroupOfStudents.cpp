//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================
#include "GroupOfStudents.h"

GroupOfStudents::GroupOfStudents(vector< StudentCourses >& v) {
	st_vec = v;
}

const vector<StudentCourses>& GroupOfStudents::get_student_courses() const {
	return st_vec;
}

void GroupOfStudents::display() {
	for (int i = 0;i <= st_vec.size();i++) {
		st_vec[i].display();
		std::cout << std::endl;
	}
}

void GroupOfStudents::display_sorted() {

}

void GroupOfStudents::display_highest() {

}

void GroupOfStudents::write_to_file() {

}

void GroupOfStudents::write_to_bin() {

}