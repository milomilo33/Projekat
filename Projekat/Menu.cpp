//============================================================================
// File Name   : Menu.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================
#include "Menu.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <vector>
#include "Courses.h"
#include <string>
#include "std_lib_facilities.h"
#undef vector

void Menu::display_menu() const{
	std::cout << "Izaberite jednu od opcija:" << std::endl;
	std::cout << "1. Prikazi osnovne informacije o autorima" << std::endl;
	std::cout << "2. Ucitaj studente iz datoteke" << std::endl;
	std::cout << "3. Prikazi informacije o studentu" << std::endl;
	std::cout << "4. Prikazi studente sa najboljim prosekom" << std::endl;
	std::cout << "5. Sortiraj" << std::endl;
	std::cout << "6. Prikazi informacije o svim studentima" << std::endl;
	std::cout << "7. Upisi studente u izlaznu datoteku" << std::endl;
	std::cout << "8. Izlaz iz programa" << std::endl;
}

void Menu::display_info() const {
	std::cout << "Autori(Prezime/Ime, Indeks):" << std::endl;
	std::cout << "Jovin Vladimir, SW-30-2018" << std::endl;
	std::cout << "Petljanski Jovan, SW-31-2018" << std::endl;
	std::cout << "Milovanovic Milovan, SW-41-2018\n" << std::endl;
}

bool Menu::is_id_valid(string id) const {
	std::regex r("[a-zA-Z]{2}\\d+\/\\d{4}");
	return std::regex_match(id, r);
}

void Menu::read_students() {
	//hard-coded filename
	std::ifstream infile("ulaz.txt");

	if (infile.is_open()) {
		std::vector<StudentCourses> st_vec;
		string line1;
		while (std::getline(infile, line1)) {
			string line2, line3, line4;

			if (!std::getline(infile, line2)) throw InvalidData();
			if (!std::getline(infile, line3)) throw InvalidData();
			if (!std::getline(infile, line4)) throw InvalidData();

			std::stringstream line1ss(line1);
			std::stringstream line2ss(line2);
			std::stringstream line3ss(line3);
			std::stringstream line4ss(line4);

			int word_count = 0;
			string word;
			string firstName, lastName, sID;
			while (line1ss >> word) {
				word_count++;
				if (word_count == 1)
					firstName = word;
				else if (word_count == 2)
					lastName = word;
				else if (word_count == 3)
					sID = word;
			}
			if (word_count != 3 || !is_id_valid(sID)) throw InvalidData();
			Student stud(firstName, lastName, sID);

			std::vector<int> homework;
			while (line2ss >> word) {
				try {
					int ocena = std::stoi(word);
					if (ocena < 0 || ocena > 100) throw InvalidData();
					homework.push_back(ocena);
				}
				catch (...) {
					throw InvalidData();
				}
			}
			if (homework.size() != Courses::NUM_HW) throw InvalidData();

			std::vector<int> test;
			while (line3ss >> word) {
				try {
					int ocena = std::stoi(word);
					if (ocena < 0 || ocena > 100) throw InvalidData();
					test.push_back(ocena);
				}
				catch (...) {
					throw InvalidData();
				}
			}
			if (test.size() != Courses::NUM_TESTS) throw InvalidData();

			std::vector<int> quiz;
			while (line4ss >> word) {
				try {
					int ocena = std::stoi(word);
					if (ocena < 0 || ocena > 100) throw InvalidData();
					quiz.push_back(ocena);
				}
				catch (...) {
					throw InvalidData();
				}
			}
			if (quiz.size() != Courses::NUM_QUIZZES) throw InvalidData();

			Courses cour(quiz, homework, test);
			cour.calc_final_score();
			cour.calc_letter_grade();

			StudentCourses sc(stud, cour);
			st_vec.push_back(sc);
		}
		infile.close();
		if (st_vec.size() == 0) throw InvalidData();
		gs = GroupOfStudents(st_vec);
	}

	else throw InvalidFile();
}

void Menu::read_students_binary() {
	string filename = "example.bin";
	std::ifstream bin_file(filename, std::ios_base::binary);

	if (!bin_file) throw InvalidFile();

	std::vector<StudentCourses> st_vec;
	char c;
	string word = "";
	while (bin_file.read(as_bytes(c), sizeof(char))) {
		word += c;
		int word_count = 0;
		string firstName, lastName, sID;
		while (bin_file.read(as_bytes(c), sizeof(char))) {
			if (c != ' ' && c != '\n')
				word += c;
			else {
				word_count++;
				if (word_count == 1 && c == ' ')
					firstName = word;
				else if (word_count == 2 && c == ' ')
					lastName = word;
				else if (word_count == 3 && c == '\n') {
					sID = word;
					break;
				}
				else throw InvalidData();
				word = "";
			}
		}
		if (word_count != 3 || !is_id_valid(sID)) throw InvalidData();
		Student stud(firstName, lastName, sID);

		std::vector<int> homework;
		word = "";
		while (bin_file.read(as_bytes(c), sizeof(char))) {
			if (c != ' ' && c != '\n')
				word += c;
			else {
				try {
					int ocena = std::stoi(word);
					if (ocena < 0 || ocena > 100) throw InvalidData();
					homework.push_back(ocena);
				}
				catch (...) {
					throw InvalidData();
				}
				word = "";
				if (c == '\n')
					break;
			}
		}
		if (homework.size() != Courses::NUM_HW) throw InvalidData();

		std::vector<int> test;
		word = "";
		while (bin_file.read(as_bytes(c), sizeof(char))) {
			if (c != ' ' && c != '\n')
				word += c;
			else {
				try {
					int ocena = std::stoi(word);
					if (ocena < 0 || ocena > 100) throw InvalidData();
					test.push_back(ocena);
				}
				catch (...) {
					throw InvalidData();
				}
				word = "";
				if (c == '\n')
					break;
			}
		}
		if (test.size() != Courses::NUM_TESTS) throw InvalidData();

		std::vector<int> quiz;
		word = "";
		while (bin_file.read(as_bytes(c), sizeof(char))) {
			if (c != ' ' && c != '\n')
				word += c;
			else {
				try {
					int ocena = std::stoi(word);
					if (ocena < 0 || ocena > 100) throw InvalidData();
					quiz.push_back(ocena);
				}
				catch (...) {
					throw InvalidData();
				}
				word = "";
				if (c == '\n')
					break;
			}
		}
		if (quiz.size() != Courses::NUM_QUIZZES) throw InvalidData();

		Courses cour(quiz, homework, test);
		cour.calc_final_score();
		cour.calc_letter_grade();

		StudentCourses sc(stud, cour);
		st_vec.push_back(sc);
	}
	bin_file.close();
	if (st_vec.size() == 0) throw InvalidData();
	gs = GroupOfStudents(st_vec);
}

void Menu::display_students()
{
	this->gs.display();
}

void Menu::display_student()
{
	string input;
	std::cin >> input;
	this->gs.display_student(input);
}

void Menu::display_students_sorted() 
{
	this->gs.display_sorted();
}

void Menu::display_highest_score() 
{
	this->gs.display_highest();
}