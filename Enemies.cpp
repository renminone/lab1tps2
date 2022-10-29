#include <iostream>
#include "Enemies.h"

using namespace std;

Enemies::Enemies()
{
	cout << "\nSYSTEM MESSAGE!\nMONSTERS CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!\n\n";
}

Enemies::Enemies(string name, string weapon, string crime, string home, string xp)
{
	this->name = name;
	this->weapon = weapon;
	this->crime = crime;
	this->home = home;
	this->xp = xp;
	cout << "\nSYSTEM MESSAGE!\nMONSTERS CONSTRUCTOR WAS CALLED!\n\n";
}

Enemies::~Enemies()
{
	cout << "\nSYSTEM MESSAGE!\nENEMIES DESTRUCTOR WAS CALLED!\n\n";
}

void Enemies::set_name(string name) { this->name = name; }
string Enemies::get_name() { return name; }

void Enemies::set_weapon(string route) { this->weapon = weapon; }
string Enemies::get_weapon() { return weapon; }

void Enemies::set_crime(string year) { this->crime = year; }
string Enemies::get_crime() { return crime; }

void Enemies::set_home(string count_car) { this->home = home; }
string Enemies::get_home() { return home; }

void Enemies::set_xp(string xp) { this->xp = xp; }
string Enemies::get_xp() { return xp; }

string Enemies::describe() {
	std::stringstream ss;
	ss << "Имя: " << name << endl << "Оружие: " << weapon << endl << "Преступление: " << crime << endl << "Локация: " << home << endl << "Преступление: " << xp << endl;
	ss << "Тип - злодей." << endl;
	return ss.str();
}

Enemies::HeroesTypes Enemies::get_type()
{
	return HeroesTypes::ENEMIES;
}

std::istream& operator>> (std::istream& in, Enemies& enemies)
{
	cout << "Имя: "; in >> enemies.name;
	cout << "Оружие: "; in >> enemies.weapon;
	cout << "Преступление: "; in >> enemies.crime;
	cout << "Дворец: "; in >> enemies.home;
	cout << ": "; in >> enemies.xp;
	return in;
}
