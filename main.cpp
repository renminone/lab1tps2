#include <iostream>
#include "Keeper.h"

void show_menu();
int input_int(string prompt);

enum commands { ADD = 1, PRINT = 2, EDIT = 3, REMOVE = 4, LOAD = 5, UPLOAD = 6, EXIT = 0};

int main()
{
    setlocale(LC_ALL, "Rus");
    Keeper keeper;
    bool is_quit = false;
    int com, num, num2;
    string str;
    show_menu();
    while (!is_quit) {
        com = input_int("\nВыберите команду: ");
        system("cls");
        show_menu();

        if (com == commands::ADD) {
            try {
                num = input_int("Выберите тип героя: 1 - Герои, 2 - Злодеи, 3 - Монстры): ");
                if (num == Heroes::FRIENDS) {
                    Friends* friends = new Friends();
                    cin >> *friends;
                    keeper.add(friends);
                }
                else if (num == Heroes::ENEMIES)
                {
                    Enemies* enemies = new Enemies();
                    cin >> *enemies;
                    keeper.add(enemies);
                }
                else if (num == Heroes::MONSTERS) {
                    Monsters* monsters = new Monsters();
                    cin >> *monsters;
                    keeper.add(monsters);
                }
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << '\n';
            }
        }
        else if (com == commands::PRINT) {
            try {
                keeper.print();
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << '\n';
            }
        }
        else if (com == commands::REMOVE) {
            try {
                num = input_int("Введите номер элемента: ");
                keeper.remove(num);
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << '\n';
            }
        }
        else if (com == commands::EDIT) {
            try {
                num = input_int("Введите номер элемента: ");
                keeper.edit(num);
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << '\n';
            }
        }
        else if (com == commands::LOAD) keeper.load();
        else if (com == commands::UPLOAD) keeper.upload();
        else if (com == commands::EXIT) {
            is_quit = true;
            keeper.free();
        }
    }

    return 0;
}

void show_menu() {
    cout << "1 - Добавить элемент.\n2 - Вывести.\n3 - Изменить.\n4 - Удалить.\n5 - Загрузить из файла.\n6 - Загрузить в файл.\n" << "0 - Выход.\n\n";
}

int input_int(string prompt)
{
    int value;
    cout << prompt;
    cin >> value;
    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Неверное значение!" << std::endl;
            cin >> value;
        }
        if (!std::cin.fail()) break;
    }
    return value;
}
