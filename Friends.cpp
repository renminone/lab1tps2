#include <iostream>
#include "Friends.h"

using namespace std;

Friends::Friends()
{
	cout << "\nSYSTEM MESSAGE!\nFRIENDS CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!\n\n";
}

Friends::Friends(string name, string weapon, string xp)
{
	this->name = name;
	this->weapon = weapon;
	this->xp = xp;
	cout << "\nSYSTEM MESSAGE!\nFRIENDS CONSTRUCTOR WAS CALLED!\n\n";
};

Friends::~Friends()
{
	cout << "\nSYSTEM MESSAGE!\nFRIENDS DESTRUCTOR WAS CALLED!\n\n";
}

void Friends::set_name(string name) { this->name = name; }
string Friends::get_name() { return name; }

void Friends::set_weapon(string weapon) { this->weapon = weapon; }
string Friends::get_weapon() { return weapon; }

void Friends::set_xp(string xp) { this->xp = xp; }
string Friends::get_xp() { return xp; }

string Friends::describe()
{
	std::stringstream ss;
	ss << "Friends, " << name << ", " << weapon << ", " << xp;
	return ss.str();
}

Heroes::HeroesTypes Friends::get_type()
{
	return HeroesTypes::FRIENDS;
}

std::istream& operator>> (std::istream& in, Friends& friends)
{
	cout << "Имя: "; in >> friends.name;
	cout << "Оружие: "; in >> friends.weapon;
	cout << "Навыки: "; in >> friends.xp;
	return in;
}
