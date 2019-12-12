//============================================================================
// File Name   : StudentCourses.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================
#include "StudentCourses.h"
#include <string>

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

StudentCourses& StudentCourses::operator=(const StudentCourses& old)
{
	if (&old != this) {
		string first_name = old.get_student().get_first_name();
		string last_name = old.get_student().get_last_name();
		string id = old.get_student().get_id();
		Courses c = old.get_courses();
		vector<int> quiz;
		vector<int> homework;
		vector<int> test;
		for (int tmp : c.get_quiz()) {
			quiz.push_back(tmp);
		}
		for (int tmp : c.get_homework()) {
			homework.push_back(tmp);
		}
		for (int tmp : c.get_test()) {
			test.push_back(tmp);
		}
		Student s(first_name, last_name, id);
		Courses cs(quiz, homework, test);
		cs.calc_final_score();
		cs.calc_letter_grade();
		this->student = s;
		this->courses = cs;
	}
	return *this;
}

StudentCourses::StudentCourses(const StudentCourses& old)
{
	string first_name = old.get_student().get_first_name();
	string last_name = old.get_student().get_last_name();
	string id = old.get_student().get_id();
	Courses c = old.get_courses();
	vector<int> quiz;
	vector<int> homework;
	vector<int> test;
	for (int tmp : c.get_quiz()) {
		quiz.push_back(tmp);
	}
	for (int tmp : c.get_homework()) {
		homework.push_back(tmp);
	}
	for (int tmp : c.get_test()) {
		test.push_back(tmp);
	}
	Student s(first_name, last_name, id);
	Courses cs(quiz, homework, test);
	cs.calc_final_score();
	cs.calc_letter_grade();
	this->student = s;
	this->courses = cs;
}