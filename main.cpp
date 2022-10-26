#include <iostream>
#include <conio.h>
#include "classes.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int l = 1;
	int i, j;
	Friends hero;
	Enemies enemy;
	Monsters monster;

	cout << "Меню:" << endl;
	cout << "1 - Положительные герои." << endl;
	cout << "2 - Злодеи." << endl;
	cout << "3 - Монстры." << endl;
	cout << "4 - Вывод." << endl;
	while (l == 1)
	{
		switch (_getch())
		{
		case '1':
			hero.add();
			break;
		case '2':
			enemy.add();
			break;
		case '3':
			monster.add();
			break;
		case '4':
			cout << "Список героев: " << endl;
			hero.get();
			cout << endl;
			cout << "Список злодеев: " << endl;
			enemy.get();
			cout << endl;
			cout << "Список монстров: " << endl;
			monster.get();
			cout << endl;
			break;
		case '0': l = 0; break;
		}
	}
}
