#include <iostream>
#include "Monsters.h"

using namespace std;

Monsters::Monsters()
{
	cout << "\nSYSTEM MESSAGE!\nMONSTERS CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!\n\n";
}

Monsters::Monsters(string name, string desc)
{
	this->name = name;
	this->desc = desc;
	cout << "\nSYSTEM MESSAGE!\nMONSTERS CONSTRUCTOR WAS CALLED!\n\n";
};

Monsters::Monsters(const Monsters &obj)
{      
    cout << "\nSYSTEM MESSAGE!\nMONSTERS COPY CONSTRUCTOR WAS CALLED!\n\n";
}

Monsters::~Monsters()
{
	cout << "\nSYSTEM MESSAGE!\nMONSTERS DESTRUCTOR WAS CALLED!\n\n";
}

void Monsters::set_name(string name) { this->name = name; }
string Monsters::get_name() { return name; }

void Monsters::set_desc(string desc) { this->desc = desc; }
string Monsters::get_desc() { return desc; }

string Monsters::describe()
{
	std::stringstream ss;
	ss << "Имя: " << name << endl << "Описание: " << desc << endl;
	ss << "Тип - монстр." << endl;
	return ss.str();
}

Heroes::HeroesTypes Monsters::get_type()
{
	return HeroesTypes::MONSTERS;
}

std::istream& operator>> (std::istream& in, Monsters& monsters)
{
	cout << "Имя: "; in >> monsters.name;
	cout << "Описание: "; in >> monsters.desc;
	return in;
}
