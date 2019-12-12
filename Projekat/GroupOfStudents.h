//============================================================================
// File Name   : GroupOfStudents.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef GROUPOFSTUDENTS_H_
#define GROUPOFSTUDENTS_H_

#include <vector>
#include "StudentCourses.h"

using std::vector;

class GroupOfStudents
{
private:
	vector<StudentCourses> st_vec;
public:
	GroupOfStudents() {}
	GroupOfStudents(vector< StudentCourses >& v);
	const vector<StudentCourses>& get_student_courses() const;
	void display();
	void sort(int , int); // ovde je sortiranje po prez pa imenu pa ID
	void display_sorted();
	void display_highest();
	void write_to_file(string); // za txt
	void write_to_bin(string); // za bin
	int get_st_vec_size();
	void display_student(string);
};

#endif /*GROUPOFSTUDENTS_H_*/
