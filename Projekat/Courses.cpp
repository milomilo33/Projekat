//============================================================================
// File Name   : Courses.cpp
// Authors     : Milovan Milovanovic
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts here
#include "Courses.h"
static const double QUIZ_WEIGHT = 0.05;
static const double HOMEWORK_WEIGHT = 0.5;
static const double TEST_WEIGHT = 0.45;

double Courses::get_final_score() const { return final_score; }

void Courses::calc_final_score() {
	double quiz_sum = 0, homework_sum = 0, test_sum = 0;
	for (int i = 0; i < NUM_QUIZZES; ++i)
		quiz_sum += quiz[i];
	double quiz_percentage = quiz_sum / NUM_QUIZZES;
	for (int i = 0; i < NUM_HW; ++i)
		homework_sum += homework[i];
	double homework_percentage = homework_sum / NUM_HW;
	for (int i = 0; i < NUM_TESTS; ++i)
		test_sum += test[i];
	double test_percentage = test_sum / NUM_TESTS;

	final_score = quiz_percentage + homework_percentage + test_percentage;
}

void Courses::calc_letter_grade() {
	if (final_score >= 91.0)
		letter_grade = 'A';
	else if (final_score < 91.0 && final_score >= 81.0)
		letter_grade = 'B';
	else if (final_score < 81.0 && final_score >= 71.0)
		letter_grade = 'C';
	else if (final_score < 71.0 && final_score >= 61.0)
		letter_grade = 'D';
	else if (final_score < 61.0)
		letter_grade = 'F';
}

void Courses::display() const {
	std::cout << "Broj bodova: " << final_score << " Ocena: " << letter_grade << std::endl;
}