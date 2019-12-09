//============================================================================
// File Name   : Student.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Student.h"

Student::Student() {}

Student::Student(string firstName,string lastName,string ID) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->ID = ID;
}

string Student::get_first_name() const {
	return this->firstName;
}

string Student::get_last_name() const {
	return this->lastName;
}

string Student::get_id() const {
	return this->ID;
}
void Student::display() const {
	std::cout << "Oznaka studenta: " << this->get_id() << std::endl;
	std::cout << "Ime studenta: " << this->get_first_name() << std::endl;
	std::cout << "Prezime studenta: " << this->get_last_name() << std::endl;
}
