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
	~Friends() { }
	
	void get()
	{
		cout << "Имя: " << name << endl;
		cout << "Оружие: " << weapon << endl;
		cout << "Навыки: " << xp << endl;
	}
	
	void put(string h, string w, string x)
	{
		name = h;
		weapon = w;
		xp = x;
	}

	void add()
	{
		string h, w, x;
		cout << "Имя: ";
		cin >> h;
		cout << "Оружие: ";
		cin >> w;
		cout << "Навыки: ";
		cin >> x;
		put(h, w, x);
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
	~Enemies() { }
	
	void get()
	{
		cout << "Имя: " << name << endl;
		cout << "Оружие: " << weapon << endl;
		cout << "Преступление: " << crime << endl;
		cout << "Локация: " << home << endl;
		cout << "Навыки: " << xp << endl;
	}

	void put(string n, string w, string c, string h, string x)
	{
		name = n;
		weapon = w;
		crime = x;
		home = h;
		xp = x;
	}

	void add()
	{
		string n, w, c, h, x;
		cout << "Имя: "; cin >> h;
		cout << "Оружие: ";	cin >> w;
		cout << "Преступление: "; cin >> c;
		cout << "Локация: "; cin >> h;
		cout << "Навыки: "; cin >> x;
		put(h, w, c, h, x);
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
	~Monsters() { }

	void get()
	{
		cout << "Имя: " << name << endl;
		cout << "Описание: " << desc << endl;
	}

	void put(string n, string d)
	{
		name = n;
		desc = d;
	}

	void add()
	{
		string n, d;
		cout << "Имя: "; cin >> n;
		cout << "Описание: "; cin >> d;
		put(n, d);
	}
};
