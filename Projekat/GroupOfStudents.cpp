//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : Vladimir Jovin
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================
#include "GroupOfStudents.h"
#include <fstream>

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
	GroupOfStudents gs_tmp;
	gs_tmp.st_vec = st_vec;
	gs_tmp.sort(0, st_vec.size());
	gs_tmp.display();
}

void GroupOfStudents::display_highest() {
	double max = 0;
	for (int i = 0;i < st_vec.size();i++) {
		if (st_vec[i].get_final_score > max)
			max = st_vec[i].get_final_score;
	}
	for (int i = 0;i < st_vec.size();i++) {
		if (st_vec[i].get_final_score == max)
			st_vec[i].display();
	}
}

void GroupOfStudents::write_to_file() {
	string path = "Prosek_Student.txt";
	std::ofstream f;
	f.open(path);
	for (int i = 0; i < st_vec.size(); i++)
	{
		f << st_vec[i].get_student().get_id() << " " << st_vec[i].get_student().get_first_name() << " " << st_vec[i].get_student().get_last_name() << " " << st_vec[i].get_courses().get_final_score() << " " << st_vec[i].get_courses().get_letter_grade() << "\n";
	}
	f.close();
}

void GroupOfStudents::write_to_bin() {
	std::ofstream f("Prosek_Student_Binarno.bin", std::ios::binary);

}