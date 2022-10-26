#include <iostream>
#include "Classes.h"

using namespace std;

int Friends::size() { return n; }
void Friends::setsize(int s) { n = s; }
void Friends::get()
{
	cout << "Имя: " << name << endl;
	cout << "Оружие: " << weapon << endl;
	cout << "Навыки: " << xp << endl;
}
void Friends::set(string h, string w, string x)
{
	name = h;
	weapon = w;
	xp = x;
}
void Friends::add()
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
void Friends::edit()
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


int Enemies::size() { return n; }
void Enemies::setsize(int s) { n = s; }
void Enemies::get()
{
	cout << "Имя: " << name << endl;
	cout << "Оружие: " << weapon << endl;
	cout << "Преступление: " << crime << endl;
	cout << "Локация: " << home << endl;
	cout << "Навыки: " << xp << endl;
}
void Enemies::set(string n, string w, string c, string h, string x)
{
	name = n;
	weapon = w;
	crime = x;
	home = h;
	xp = x;
}
void Enemies::add()
{
	string n, w, c, h, x;
	cout << "Имя: "; cin >> h;
	cout << "Оружие: ";	cin >> w;
	cout << "Преступление: "; cin >> c;
	cout << "Локация: "; cin >> h;
	cout << "Навыки: "; cin >> x;
	set(h, w, c, h, x);
}
void Enemies::edit()
{
	string n, w, c, h, x;
	cout << "Имя: "; cin >> h;
	cout << "Оружие: ";	cin >> w;
	cout << "Преступление: "; cin >> c;
	cout << "Локация: "; cin >> h;
	cout << "Навыки: "; cin >> x;
	set(h, w, c, h, x);
}


int Monsters::size() { return n; }
void Monsters::setsize(int s) { n = s; }
void Monsters::get()
{
	cout << "Имя: " << name << endl;
	cout << "Описание: " << desc << endl;
}
void Monsters::set(string n, string d)
{
	name = n;
	desc = d;
}
void Monsters::add()
{
	n++;
	string n, d;
	cout << "Имя: "; cin >> n;
	cout << "Описание: "; cin >> d;
	set(n, d);
}

void Monsters::edit()
{
	string n, d;
	cout << "Имя: "; cin >> n;
	cout << "Описание: "; cin >> d;
	set(n, d);
}
