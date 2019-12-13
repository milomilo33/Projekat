//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : Vladimir Jovin
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================
#include "GroupOfStudents.h"
#include <fstream>
#include <cstring>

GroupOfStudents::GroupOfStudents(vector< StudentCourses >& v) {
	st_vec = v;
}

const vector<StudentCourses>& GroupOfStudents::get_student_courses() const {
	return st_vec;
}

void GroupOfStudents::display() {
	for (int i = 0; i < st_vec.size(); i++) {
		st_vec[i].display();
		std::cout << std::endl;
	}
}

void GroupOfStudents::sort(int start, int end)
{
	//implementacija merge sort-a
	if (start >= end) return;

	int middle = (start + end) / 2;
	static vector<StudentCourses> v_copy(2*st_vec.size());
	int i = start, j = middle + 1, k = 0;
	sort(start, middle);
	sort(middle + 1, end);

	while (i <= middle && j <= end) {
		if (st_vec[i] <= st_vec[j]) v_copy[k++] = st_vec[i++];
		else v_copy[k++] = st_vec[j++];
	}

	while(i <= middle) v_copy[k++] = st_vec[i++];

	while(j  <= end) v_copy[k++] = st_vec[j++];

	for (int p = 0; p <= end - start; ++p) st_vec[p + start] = v_copy[p];


}

void GroupOfStudents::display_sorted() {
	GroupOfStudents gs_tmp;
	gs_tmp.st_vec = st_vec;
	gs_tmp.sort(0, st_vec.size()-1);
	gs_tmp.display();
	//this->sort(0, st_vec.size()-1);
	//this->display();
}

void GroupOfStudents::display_highest() {
	double max = 0;
	for (int i = 0;i < st_vec.size();i++) {
		if (st_vec[i].get_final_score() > max)
			max = st_vec[i].get_final_score();
	}
	for (int i = 0;i < st_vec.size();i++) {
		if (st_vec[i].get_final_score() == max)
			st_vec[i].display();
	}
}

void GroupOfStudents::write_to_file(string path) {
	sort(0, st_vec.size() - 1);
	std::ofstream f;
	f.open(path + ".txt");
	for (int i = 0; i < st_vec.size(); i++)
	{
		f << st_vec[i].get_student().get_id() << " " << st_vec[i].get_student().get_first_name() << " " << st_vec[i].get_student().get_last_name() << " " << st_vec[i].get_courses().get_final_score() << " " << st_vec[i].get_courses().get_letter_grade() << "\n";
	}
	f.close();
}

char* string_to_char(string s) {
	char c[100];
	for (int i=0;i < s.size();i++) {
		*(c + i) = s[i];
	}
	return c;
}

void GroupOfStudents::write_to_bin(string path) {
	std::ofstream f(path + ".bin", std::ios::binary);

	for (int i = 0; i < st_vec.size(); i++)
	{
		string s = st_vec[i].get_student().get_id();
		f << s << " ";
		s = st_vec[i].get_student().get_first_name();
		f << s << " ";
		s = st_vec[i].get_student().get_last_name();
		f << s << " ";
		double sc = st_vec[i].get_courses().get_final_score();
		f << sc << " ";
		char c = st_vec[i].get_courses().get_letter_grade();
		f << c << std::endl;
	}
	f.close();
}

int GroupOfStudents::get_st_vec_size()
{
	return st_vec.size();
}

void GroupOfStudents::display_student(string input)
{
	for (StudentCourses sc : st_vec) {
		if (sc.get_student().get_id() == input) {
			sc.get_student().display();
			return;
		}
	}
	return;
}