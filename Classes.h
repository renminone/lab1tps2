#pragma once
#include <iostream>

using namespace std;

void cwop() { cout << "SYSTEM MESSAGE!" << endl << "CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!" << endl << endl; }
void cwp() { cout << "SYSTEM MESSAGE!" << endl << "CONSTRUCTOR WITH PARAMETRES WAS CALLED!" << endl << endl; }
void cc() {	cout << "SYSTEM MESSAGE!" << endl << "COPYING CONSTRUCTOR WAS CALLED!" << endl << endl; }
void dest() { cout << "SYSTEM MESSAGE!" << endl << "DESTRUCTOR WAS CALLED!" << endl << endl; }
class Heroes
{
public:
	string name; //Имя
	string weapon; //Оружие
	string xp; //Навыки
	int n = 0;
};

class Friends : public Heroes
{
	//name, weapon, xp
public:
	Friends() { cwop(); }
	Friends(string name, string weapon)
	{
		this->name = name;
		this->weapon = weapon;
		this->xp = xp;
		cwp();
	}
	Friends(const Friends& obj) { cc(); }
	~Friends() { dest(); }
	
	int size();
	void setsize(int s);
	void get();
	void set(string h, string w, string x);
	void add();
	void edit();

};

class Enemies : public Heroes
{
	string crime;
	string home;
	//name, weapon, xp
public:
	Enemies() { cwop(); }
	Enemies(string name, string weapon, string crime, string home, string xp)
	{
		this->name = name;
		this->weapon = weapon;
		this->crime = crime;
		this->home = home;
		this->xp = xp;
		cwp();
	}
	Enemies(const Enemies& obj) { cc(); }
	~Enemies() { dest(); }
	
	int size();
	void setsize(int s);
	void get();
	void set(string n, string w, string c, string h, string x);
	void add();
	void edit();
};

class Monsters : public Heroes
{
	string desc;
	//name
public:
	Monsters() { cwop(); }
	Monsters(string name, string desc)
	{
		this->name = name;
		this->desc = desc;
		cwp();
	}
	Monsters(const Monsters& obj) { cc(); }
	~Monsters() { dest(); }

	int size();
	void setsize(int s);
	void get();
	void set(string n, string d);
	void add();
	void edit();
};
