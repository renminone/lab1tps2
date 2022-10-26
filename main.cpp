#include <iostream>
#include <conio.h>
#include "classes.h"

using namespace std;

void menu()
{
	cout << endl;
	cout << "1 - Добавление элемента." << endl;
	cout << "2 - Удаление." << endl;
	cout << "3 - Изменение." << endl;
	cout << "4 - Вывод элемента." << endl;
	cout << "0 - выход в главное меню." << endl;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int l = 1, o = 1;
	int i, j;
	Friends a;
	Enemies b;
	Monsters c;
	Friends* hero = new Friends[0];
	Friends* rf;
	Enemies enemy[2];
	Monsters monster[2];

	while (l == 1)
	{
		cout << "Меню:" << endl;
		cout << "1 - Положительные герои." << endl;
		cout << "2 - Злодеи." << endl;
		cout << "3 - Монстры." << endl;
		cout << "4 - Вывод." << endl;
		switch (_getch())
		{
		case '1':
			menu();
			while (o == 1)
			{
				switch (_getch())
				{
				case '1':
					i = a.size();
					rf = new Friends[i + 1];
					for (j = 0; j < i; j++)
						rf[j] = hero[j];
					rf[i].add();
					delete[] hero;
					hero = new Friends[i+1];
					for (j = 0; j < i + 1; j++)
						hero[j] = rf[j];
					a.setsize(i + 1);
					break;
				case '2':
					i = a.size();
					cout << i;
					if (i > 0)
					{
						rf = new Friends[i - 1];
						for (j = 0; j < i - 1; j++)
							rf[j] = hero[j];
						delete[] hero;
						hero = new Friends[i - 1];
						for (j = 0; j < i - 1; j++)
							hero[j] = rf[j];
						delete[] rf;
						a.setsize(i - 1);
					}
					else cout << "Пусто!" << endl;
					break;
				case '3':
					cin >> j;
					hero[j].edit();
					break;
				case '4':
					cin >> j;
					hero[j].get();
					break;
				case '0': o = 0; break;
				}
			}
			o = 1; break;
			system("cls");
		case '2':
			for (i = 0; i < 2; i++)
				enemy[i].add();
			break;
		case '3':
			for (i = 0; i < 2; i++)
				monster[i].add();
			break;
		case '4':
			i = a.size();
			if (i > 0)
			{
				cout << "Список героев: " << endl;
				for (j = 0; j < i; j++)
					hero[j].get();
				cout << endl;
			}
			else cout << "Пусто!" << endl << endl;
			i = b.size();
			if (i > 0)
			{
				cout << "Список героев: " << endl;
				for (j = 0; j < i; j++)
					hero[j].get();
				cout << endl;
			}
			i = c.size();
			if (i > 0)
			{
				cout << "Список героев: " << endl;
				for (j = 0; j < i; j++)
					hero[j].get();
				cout << endl;
			}
			break;
		case '0': l = 0; break;
		}
	}
}
