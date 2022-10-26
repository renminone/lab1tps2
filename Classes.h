#pragma once
#include <iostream>

using namespace std;

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
	Friends() { cout << "SYSTEM MESSAGE!" << endl << "CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!" << endl << endl; }
	Friends(string name, string weapon)
	{
		this->name = name;
		this->weapon = weapon;
		this->xp = xp;
		cout << "SYSTEM MESSAGE!" << endl << "CONSTRUCTOR WITH PARAMETRES WAS CALLED!" << endl << endl;
	}
	Friends(const Friends& obj) { cout << "SYSTEM MESSAGE!" << endl << "COPYING CONSTRUCTOR WAS CALLED!" << endl << endl; }
	~Friends() { cout << "SYSTEM MESSAGE!" << endl << "DESTRUCTOR WAS CALLED!" << endl << endl; }
	
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
	Enemies() { cout << "SYSTEM MESSAGE!" << endl << "CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!" << endl << endl; }
	Enemies(string name, string weapon, string crime, string home, string xp)
	{
		this->name = name;
		this->weapon = weapon;
		this->crime = crime;
		this->home = home;
		this->xp = xp;
		cout << "SYSTEM MESSAGE!" << endl << "CONSTRUCTOR WITH PARAMETRES WAS CALLED!" << endl << endl;
	}
	Enemies(const Enemies& obj) { cout << "SYSTEM MESSAGE!" << endl << "COPYING CONSTRUCTOR WAS CALLED!" << endl << endl; }
	~Enemies() { cout << "SYSTEM MESSAGE!" << endl << "DESTRUCTOR WAS CALLED!" << endl << endl; }
	
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
	Monsters() { cout << "SYSTEM MESSAGE!" << endl << "CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!" << endl << endl; }
	Monsters(string name, string desc)
	{
		this->name = name;
		this->desc = desc;
		cout << "SYSTEM MESSAGE!" << endl << "CONSTRUCTOR WITH PARAMETRES WAS CALLED!" << endl << endl;
	}
	Monsters(const Monsters& obj) { cout << "SYSTEM MESSAGE!" << endl << "COPYING CONSTRUCTOR WAS CALLED!" << endl << endl; }
	~Monsters() { cout << "SYSTEM MESSAGE!" << endl << "DESTRUCTOR WAS CALLED!" << endl << endl; }

	int size();
	void setsize(int s);
	void get();
	void set(string n, string d);
	void add();
	void edit();
};
