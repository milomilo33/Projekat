//============================================================================
// File Name   : Menu.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================
#include "Menu.h"
#include <iostream>

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