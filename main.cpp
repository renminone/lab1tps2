#include <iostream>
#include <conio.h>
#include "classes.h"

using namespace std;

void info() { cout << "Все объекты задаются основной латиницей, пробелы - нижнее подчёркивание." << endl; }
void menu()
{
	cout << endl;
	cout << "1 - Добавление элемента." << endl;
	cout << "2 - Удаление." << endl;
	cout << "3 - Изменение." << endl;
	cout << "4 - Вывод элемента." << endl;
	cout << "5 - Важная информация" << endl;
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
	Enemies* enemy = new Enemies[0];
	Enemies* re;
	Monsters* monster = new Monsters[0];
	Monsters* rm;

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
					cout << "Успешно добавлено!" << endl;
					break;
				case '2':
					i = a.size();
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
						cout << "Успешно удалено!" << endl;
					}
					else cout << "Пусто!" << endl;
					break;
				case '3':
					i = a.size();
					cout << "Выберите элемент для редактирования: ";
					cin >> j;
					if (j >= i)	hero[j].edit();
					else cout << "Данного объекта не существует!" << endl;
					break;
				case '4':
					i = a.size();
					cout << "Выберите элемент для вывода: ";
					cin >> j;
					if (j >= i) hero[j].get();
					else cout << "Данного объекта не существует!" << endl;
					break;
				case '0': o = 0; break;
				}
			}
			o = 1; system("cls"); break;
		case '2':
			menu();
			while (o == 1)
			{
				switch (_getch())
				{
				case '1':
					i = b.size();
					re = new Enemies[i + 1];
					for (j = 0; j < i; j++)
						re[j] = enemy[j];
					re[i].add();
					delete[] enemy;
					enemy = new Enemies[i + 1];
					for (j = 0; j < i + 1; j++)
						enemy[j] = re[j];
					b.setsize(i + 1);
					cout << "Успешно добавлено!" << endl;
					break;
				case '2':
					i = b.size();
					if (i > 0)
					{
						re = new Enemies[i - 1];
						for (j = 0; j < i - 1; j++)
							re[j] = enemy[j];
						delete[] enemy;
						enemy = new Enemies[i - 1];
						for (j = 0; j < i - 1; j++)
							enemy[j] = re[j];
						delete[] re;
						b.setsize(i - 1);
						cout << "Успешно удалено!" << endl;
					}
					else cout << "Пусто!" << endl;
					break;
				case '3':
					i = b.size();
					cout << "Выберите элемент для вывода: ";
					cin >> j;
					if (j >= i) enemy[j].edit();
					else cout << "Данного объекта не существует!" << endl;
					break;
				case '4':
					i = b.size();
					cout << "Выберите элемент для вывода: ";
					cin >> j;
					if (j >= i) enemy[j].get();
					else cout << "Данного объекта не существует!" << endl;
					break;
				case '0': o = 0; break;
				}
			}
			o = 1; system("cls"); break;
		case '3':
			menu();
			while (o == 1)
			{
				switch (_getch())
				{
				case '1':
					i = c.size();
					rm = new Monsters[i + 1];
					for (j = 0; j < i; j++)
						rm[j] = monster[j];
					rm[i].add();
					delete[] monster;
					monster = new Monsters[i + 1];
					for (j = 0; j < i + 1; j++)
						monster[j] = rm[j];
					c.setsize(i + 1);
					cout << "Успешно добавлено!" << endl;
					break;
				case '2':
					i = c.size();
					if (i > 0)
					{
						rm = new Monsters[i - 1];
						for (j = 0; j < i - 1; j++)
							rm[j] = monster[j];
						delete[] monster;
						monster = new Monsters[i - 1];
						for (j = 0; j < i - 1; j++)
							monster[j] = rm[j];
						delete[] rm;
						c.setsize(i - 1);
						cout << "Успешно удалено!" << endl;
					}
					else cout << "Пусто!" << endl;
					break;
				case '3':
					i = c.size();
					cout << "Выберите элемент для вывода: ";
					cin >> j;
					if (j >= i) monster[j].edit();
					else cout << "Данного объекта не существует!" << endl;
					break;
				case '4':
					i = c.size();
					cout << "Выберите элемент для вывода: ";
					cin >> j;
					if (j >= i) monster[j].get();
					else cout << "Данного объекта не существует!" << endl;
					break;
				case '0': o = 0; break;
				}
			}
			o = 1; system("cls"); break;
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
			else cout << "Пусто!" << endl << endl;
			i = c.size();
			if (i > 0)
			{
				cout << "Список героев: " << endl;
				for (j = 0; j < i; j++)
					hero[j].get();
				cout << endl;
			}
			else cout << "Пусто!" << endl << endl;
			break;
		case '5': info();
		case '0': l = 0; break;
		}
	}
}
