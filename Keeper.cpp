#include <iostream>
#include "Keeper.h"

using namespace std;
Keeper::Keeper()
{
    cout << "\nSYSTEM MESSAGE!\nKEEPER CONSTRUCTOR WAS CALLED!\n\n";
};

Keeper::~Keeper()
{
    cout << "\nSYSTEM MESSAGE!\nKEEPER DESTRUCTOR WAS CALLED!\n\n";
};

void Keeper::add(Heroes* new_hero)
{
    Node* temp = new Node;
    temp->heroes = new_hero;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    n++;
}

void Keeper::print()
{
    if (!n) throw std::runtime_error("Пусто!");
    Node* temp = new Node;
    temp = head;
    int counter = 1;
    while (temp != NULL)
    {
        std::cout << counter++ << ". " << temp->heroes->describe() << "\n";
        temp = temp->next;
    }
}

void Keeper::remove(int num)
{
    if (!n) throw std::runtime_error("Пусто!");
    if (num > n || num < 1)
    {
        throw std::runtime_error("Необходимо ввести число от 1 до " + std::to_string(n));
    }

    Node* cur = new Node;
    Node* prev = new Node;
    cur = head;
    if (num == 1) head = head->next;

    for (int i = 1; i < num; i++)
    {
        prev = cur;
        cur = cur->next;
    }
    if (num == n)
    {
        tail = prev;
        prev->next = NULL;
        tail->next = NULL;
    }
    else
    {
        prev->next = cur->next;
    }
    n--;
    delete cur->heroes;
}

void Keeper::free()
{
    if (!n) return;

    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        delete curr->heroes;
        delete curr;
        curr = next;
    }
    head = NULL;
    tail = NULL;
    n = 0;
}

Heroes* Keeper::get(int num)
{
    if (!n) throw std::runtime_error("Пусто!");
    if (num > n || num < 1) {
        throw std::runtime_error("Необходимо ввести число от 1 до " + std::to_string(n));
    }
    Node* cur = new Node;
    Node* prev = new Node;
    cur = head;
    if (num == 1) return head->heroes;

    for (int i = 1; i < num; i++)
    {
        prev = cur;
        cur = cur->next;
    }
    return cur->heroes;
}

int Keeper::get_count_arguments(string str, string delimiter)
{
    int str_len = str.length();
    int count = 0;
    if (str_len == 0) return 0;
    for (size_t i = 0; i < str_len - 1; i++)
    {
        if (str[i] == delimiter[0] && str[i + 1] == delimiter[1]) count++;
    }
    return count + 1;
}

string* Keeper::split(string str, string delimiter, int count)
{
    int pos, i = 0;
    string* strings = new string[count];
    strings[0] = "";

    while ((pos = str.find(delimiter)) != string::npos) {
        strings[i++] = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
    }
    if (i <= 1) return strings;
    strings[i] = str;
    return strings;
}

bool Keeper::is_int(string str) {
    std::stringstream ss(str);
    float i;
    if ((ss >> i).fail()) return false;
    else if (int(i) == i) return true;
    return false;
}

void Keeper::load() {
    string line, type;
    string* s;
    string* cities;
    std::fstream in;
    string path = "cargoes.txt";
    int count_arg;

    cout << "Enter path to the file: "; cin >> path;
    in.open(path, std::ios::in);
    while (!in.is_open()) {
        cout << "failed to open the file" << "\n";
        cout << "Enter path to the file: "; cin >> path;
        in.open(path, std::ios::in);
    }

    while (std::getline(in, line)) {
        count_arg = get_count_arguments(line, ", ");
        s = split(line, ", ", count_arg);
        type = s[0];
        Heroes* heroes;
        if (type == "Friends") {
            if (count_arg != 6 || !(is_int(s[2]) && is_int(s[4]) && is_int(s[5]))) continue;
            try {
                heroes = (Heroes*)(new Friends(s[1], s[2], s[3]));
                add(heroes);
            }
            catch (const std::exception& e)
            {
                continue;
            }
        }
        else if (type == "Enemies") {
            if (count_arg != 7 || !(is_int(s[3]) && is_int(s[4]) && is_int(s[5]))) continue;
            try
            {
                heroes = (Heroes*)(new Enemies(s[1], s[2], s[3], s[4], s[5]));
                add(heroes);
            }
            catch (const std::exception& e)
            {
                continue;
            }
        }
        else if (type == "Monsters") {
            if (count_arg != 6 || !(is_int(s[1]) && is_int(s[4]))) continue;
            try {
                heroes = (Heroes*)(new Monsters(s[1], s[2]));
                add(heroes);
            }
            catch (const std::exception& e)
            {
                continue;
            }
        }
    }
    in.close();
}

void Keeper::edit(int num) {
    int property_int;
    string property_str;
    Heroes::HeroesTypes type;

    type = this->get(num)->get_type();
    cout << this->get(num)->describe() << "\n";

    if (type == Heroes::FRIENDS)
    {
        Friends* friends = (Friends*)this->get(num);
        num = input_int("Выберите данные (1 - Имя, 2 - Оружие, 3 - Навыки): ");

        if (num == 1)
        {
            cout << "Введите новое имя: "; getline(cin >> std::ws, property_str);
            friends->set_name(property_str);
        }
        else if (num == 2)
        {
            cout << "Введите новое оружие: "; getline(cin >> std::ws, property_str);
            friends->set_weapon(property_str);
        }
        else if (num == 3)
        {
            cout << "Введите новые навыки: "; getline(cin >> std::ws, property_str);
            friends->set_xp(property_str);
        }
    }
    else if (type == Heroes::ENEMIES) {
        Enemies* enemies = (Enemies*)this->get(num);
        num = input_int("Выберите данные (1 - Имя, 2 - Оружие, 3 - Преступление, 4 - Локация, 5 - Навыки): ");

        if (num == 1)
        {
            cout << "Введите новое имя: "; getline(cin >> std::ws, property_str);
            enemies->set_name(property_str);
        }
        else if (num == 2)
        {
            cout << "Введите новое оружие: "; getline(cin >> std::ws, property_str);
            enemies->set_weapon(property_str);
        }
        else if (num == 3)
        {
            cout << "Введите новое преступление: "; getline(cin >> std::ws, property_str);
            enemies->set_crime(property_str);
        }
        else if (num == 4)
        {
            cout << "Введите новую локация: "; getline(cin >> std::ws, property_str);
            enemies->set_home(property_str);
        }
        else if (num == 5)
        {
            cout << "Введите новые навыки: "; getline(cin >> std::ws, property_str);
            enemies->set_xp(property_str);
        }
    }
    else if (type == Heroes::MONSTERS)
    {
        Monsters* monsters = (Monsters*)this->get(num);
        num = input_int("Выберите данные (1 - Имя, 2 - Описание: ");

        if (num == 1)
        {
            cout << "Введите новое имя: "; getline(cin >> std::ws, property_str);
            monsters->set_name(property_str);
        }
        else if (num == 2) {
            cout << "Введите новое описание: "; getline(cin >> std::ws, property_str);
            monsters->set_desc(property_str);
        }
    }
}

int Keeper::input_int(string prompt)
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

void Keeper::clear_file() {
    std::ofstream in;
    string path = "cargoes.txt";

    cout << "Enter path to the file: "; cin >> path;
    in.open(path, std::ofstream::out, std::ofstream::trunc);
    while (!in.is_open()) {
        cout << "Failed to open the file" << "\n";
        cout << "Enter path to the file: "; cin >> path;
        in.open(path, std::ofstream::out, std::ofstream::trunc);
    }

    in.close();
}
void Keeper::upload() {
    std::fstream in;
    string path = "cargoes.txt";

    cout << "Enter path to the file: "; cin >> path;
    in.open(path, std::ios::out);
    while (!in.is_open()) {
        cout << "Failed to open the file" << "\n";
        cout << "Enter path to the file: "; cin >> path;
        in.open(path, std::ios::in);
    }

    Node* temp = new Node;
    temp = head;
    while (temp != NULL) {
        in << temp->heroes->describe() << "\n";
        temp = temp->next;
    }
    in.close();
}
