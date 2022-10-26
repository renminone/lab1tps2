#include <iostream>
#include <conio.h>
#include "classes.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int l = 1;
	int i, j;
	Friends* hero = new Friends;

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

			break;
		case '2':

			break;
		case '3':

			break;
		case '4':

			break;
		case '0': l = 0; break;
		}
	}
}
