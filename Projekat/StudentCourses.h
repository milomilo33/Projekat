//============================================================================
// File Name   : StudentCourses.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef _STUDENTCOURSES_H_
#define _STUDENTCOURSES_H_

#include "Student.h"
#include "Courses.h"

class StudentCourses
{
	Student student;
	Courses courses;
public:
	StudentCourses() {};
	StudentCourses(Student& s, Courses& c) : student(s), courses(c) {}
	Student get_student() const;
	Courses get_courses() const;

	double get_final_score();
	void display();
	bool operator<=(StudentCourses sc);
};

#endif
