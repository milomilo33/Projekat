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
	//implementacija quick sort-a
	/*int left, right;
	StudentCourses* sc;
	while (end > start) {
		left = start;
		right = end;
		sc = &st_vec[start];
		while (left < right) {
			while (!(st_vec[right] <= *sc)) right--;
			st_vec[left] = st_vec[right];
			while (!(*sc <= st_vec[left]) && left < right)left++;
			st_vec[right] = st_vec[left];
		}
		st_vec[left] = *sc;
		sort(start, left - 1);
	}
	*/
	StudentCourses tmp = st_vec[0];
	st_vec[0] = st_vec[1];
	st_vec[1] = tmp;

}

void GroupOfStudents::display_sorted() {
/*	GroupOfStudents gs_tmp;
	gs_tmp.st_vec = st_vec;
	gs_tmp.sort(0, st_vec.size());
	gs_tmp.display();
	*/
	this->sort(0, st_vec.size());
	this->display();
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

char* string_to_char(string s) {
	char c[100];
	for (int i=0;i < s.size();i++) {
		*(c + i) = s[i];
	}
	return c;
}

void GroupOfStudents::write_to_bin() {
	std::ofstream f("Prosek_Student_Binarno.bin", std::ios::binary);
	for (int i = 0; i < st_vec.size(); i++)
	{
		string s = st_vec[i].get_student().get_id();
		char* tmp;
		tmp = string_to_char(s);
		f.write(tmp, sizeof(char[100]));
		s = st_vec[i].get_student().get_first_name();
		tmp = string_to_char(s);
		f.write(tmp, sizeof(char[100]));
		s = st_vec[i].get_student().get_last_name();
		tmp = string_to_char(s);
		f.write(tmp, sizeof(char[100]));
		double sc = st_vec[i].get_courses().get_final_score();
		f.write((char*)&sc,sizeof(double));
		char c = st_vec[i].get_courses().get_letter_grade();
		f.write((char*)&c, sizeof(char));
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
