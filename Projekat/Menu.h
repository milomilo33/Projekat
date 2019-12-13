//============================================================================
// File Name   : Menu.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <stdexcept>
#include "GroupOfStudents.h"

using std::string;

class Menu
{
public:
	struct InvalidData : std::runtime_error {
		InvalidData(): runtime_error("Invalid input data format") {}
	};

	struct InvalidFile : std::runtime_error {
		InvalidFile(): runtime_error("Invalid input file name") {}
	};

	enum OPTIONS{ INFO=1, READ_FILE=2, DISPLAY=3, HIGHEST=4, DISPLAY_SORTED=5, DISPLAY_STUDENTS=6, WRITE_FILE=7, EXIT=8 };
		
private:
	GroupOfStudents gs;
	bool binary_write;
	string filename;
	string out_path;
	
public:
	Menu() : binary_write(false) {}

	bool is_id_valid(string id) const;
	void display_menu() const;
	void display_info() const;
	void read_students();
	void read_students_binary();
	void display_students();
	void display_student();
	void display_students_sorted();
	void display_highest_score();
	void set_binary_write();
	void set_filename(string);
	string get_filename();
	void write();
	void set_out_path(string);
};

#endif /*MENU_H_*/
