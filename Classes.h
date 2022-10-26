#pragma once
#include <iostream>

using namespace std;

class Heroes
{
public:
	string name; //Имя
	string weapon; //Оружие
	string xp; //Навыки
};

class Friends : public Heroes
{
	//name, weapon, xp
public:
	Friends() { }
	Friends(string name, string weapon)
	{
		this->name = name;
		this->weapon = weapon;
		this->xp = xp;
	}
	~Friends()
	{
		cout << "Очищено." << std::endl;
	}

};

class Enemies : public Heroes
{
	string crime;
	string home;
	//name, weapon, xp
public:
	Enemies() { }
	Enemies(string name, string weapon, string crime, string home, string xp)
	{
		this->name = name;
		this->weapon = weapon;
		this->crime = crime;
		this->home = home;
		this->xp = xp;
	}
	~Enemies()
	{
		cout << "Очищено." << std::endl;
	}
	
};

class Monsters : public Heroes
{
	string desc;
	//name
public:
	Monsters() { }
	Monsters(string name, string desc)
	{
		this->name = name;
		this->desc = desc;
	}
	~Monsters()
	{
		cout << "Очищено." << std::endl;
	}

};
