#pragma once
#include "Heroes.h"

class Enemies : public Heroes
{
private:
	//Имя, оружие, преступление, локация, основные навыки.
	string crime, home;
public:
	Enemies();
	Enemies(string name, string weapon, string crime, string home, string xp);
	Enemies(const Enemies &obj);
	~Enemies();

	void set_name(string name);
	string get_name();

	void set_weapon(string weapon);
	string get_weapon();

	void set_crime(string crime);
	string get_crime();

	void set_home(string home);
	string get_home();

	void set_xp(string xp);
	string get_xp();

	string describe() override;
	HeroesTypes get_type() override;

	friend std::istream& operator>> (std::istream& in, Enemies& enemies);
};
