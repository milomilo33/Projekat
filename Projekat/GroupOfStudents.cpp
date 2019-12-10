//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : Vladimir Jovin
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
	for (int i = 0; i <= st_vec.size(); i++) {
		st_vec[i].display();
		std::cout << std::endl;
	}
}

void GroupOfStudents::sort(int start, int end)
{
	//implementacija merge sort-a
	if (start >= end) return;

	int middle = (start + end) / 2;
	static vector<StudentCourses> v_copy(st_vec.size());
	int i = start, j = middle + 1, k = 0;
	sort(start, middle);
	sort(middle + 1, end);

	while (i <= middle && j <= end) {
		if (st_vec[i] <= st_vec[j]) v_copy[k++] = st_vec[i++];
		else v_copy[k++] = st_vec[j++];
	}

	while(i <= middle) v_copy[k++] = st_vec[i++];

	while(j  <= end) v_copy[k++] = st_vec[j++];

	for (int p = 0; p <= end - 1; ++p) st_vec[p + start] = v_copy[p];


}

void GroupOfStudents::display_sorted() {
	this->sort(0, st_vec.size());
	this->display();

}

void GroupOfStudents::display_highest() {

}

void GroupOfStudents::write_to_file() {

}

void GroupOfStudents::write_to_bin() {

}