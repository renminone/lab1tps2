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
	Friends()
	{
		cout << "SYSTEM MESSAGE!" << endl;
		cout << "CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!" << endl << endl;
	}
	Friends(string name, string weapon)
	{
		this->name = name;
		this->weapon = weapon;
		this->xp = xp;

		cout << "SYSTEM MESSAGE!" << endl;
		cout << "CONSTRUCTOR WITH PARAMETRES WAS CALLED!" << endl << endl;
	}
	Friends(const Friends& obj)
	{
		cout << "SYSTEM MESSAGE!" << endl;
		cout << "COPYING CONSTRUCTOR WAS CALLED!" << endl << endl;
	}
	~Friends()
	{
		cout << "SYSTEM MESSAGE!" << endl;
		cout << "DESTRUCTOR WAS CALLED!" << endl << endl;
	}
	
	int size() { return n; }
	void setsize(int s) { n = s; }

	void get()
	{
		cout << "Имя: " << name << endl;
		cout << "Оружие: " << weapon << endl;
		cout << "Навыки: " << xp << endl;
	}
	
	void set(string h, string w, string x)
	{
		name = h;
		weapon = w;
		xp = x;
	}

	void add()
	{
		n++;
		string h, w, x;
		cout << "Имя: ";
		cin >> h;
		cout << "Оружие: ";
		cin >> w;
		cout << "Навыки: ";
		cin >> x;
		set(h, w, x);
	}

	void edit()
	{
		string h, w, x;
		cout << "Имя: ";
		cin >> h;
		cout << "Оружие: ";
		cin >> w;
		cout << "Навыки: ";
		cin >> x;
		set(h, w, x);
	}

};

class Enemies : public Heroes
{
	string crime;
	string home;
	//name, weapon, xp
public:
	Enemies()
	{
		cout << "SYSTEM MESSAGE!" << endl;
		cout << "CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!" << endl << endl;
	}
	Enemies(string name, string weapon, string crime, string home, string xp)
	{
		this->name = name;
		this->weapon = weapon;
		this->crime = crime;
		this->home = home;
		this->xp = xp;

		cout << "SYSTEM MESSAGE!" << endl;
		cout << "CONSTRUCTOR WITH PARAMETRES WAS CALLED!" << endl << endl;
	}
	Enemies(const Enemies& obj)
	{
		cout << "SYSTEM MESSAGE!" << endl;
		cout << "COPYING CONSTRUCTOR WAS CALLED!" << endl << endl;
	}
	~Enemies()
	{
		cout << "SYSTEM MESSAGE!" << endl;
		cout << "DESTRUCTOR WAS CALLED!" << endl << endl;
	}
	
	int size() { return n; }
	void setsize(int s) { n = s; }

	void get()
	{
		cout << "Имя: " << name << endl;
		cout << "Оружие: " << weapon << endl;
		cout << "Преступление: " << crime << endl;
		cout << "Локация: " << home << endl;
		cout << "Навыки: " << xp << endl;
	}

	void set(string n, string w, string c, string h, string x)
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
		set(h, w, c, h, x);
	}

	void edit()
	{
		string n, w, c, h, x;
		cout << "Имя: "; cin >> h;
		cout << "Оружие: ";	cin >> w;
		cout << "Преступление: "; cin >> c;
		cout << "Локация: "; cin >> h;
		cout << "Навыки: "; cin >> x;
		set(h, w, c, h, x);
	}
};

class Monsters : public Heroes
{
	string desc;
	//name
public:
	Monsters()
	{
		cout << "SYSTEM MESSAGE!" << endl;
		cout << "CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!" << endl << endl;
	}
	Monsters(string name, string desc)
	{
		this->name = name;
		this->desc = desc;

		cout << "SYSTEM MESSAGE!" << endl;
		cout << "CONSTRUCTOR WITH PARAMETRES WAS CALLED!" << endl << endl;
	}
	Monsters(const Monsters& obj)
	{
		cout << "SYSTEM MESSAGE!" << endl;
		cout << "COPYING CONSTRUCTOR WAS CALLED!" << endl << endl;
	}
	~Monsters()
	{
		cout << "SYSTEM MESSAGE!" << endl;
		cout << "DESTRUCTOR WAS CALLED!" << endl << endl;
	}

	int size() { return n; }
	void setsize(int s) { n = s; }

	void get()
	{
		cout << "Имя: " << name << endl;
		cout << "Описание: " << desc << endl;
	}

	void set(string n, string d)
	{
		name = n;
		desc = d;
	}

	void add()
	{
		string n, d;
		cout << "Имя: "; cin >> n;
		cout << "Описание: "; cin >> d;
		set(n, d);
	}
};
