#pragma once
#include <iostream>
#include "Heroes.h"
#include "Friends.h"
#include "Enemies.h"
#include "Monsters.h"
#include <fstream>
#include <string>
#include <limits>
using std::stoi;
using std::getline;
using namespace std;

struct Node
{
	Heroes* heroes;
	Node* next;
};

class Keeper
{
	Node* head = NULL;
	Node* tail = NULL;
	int n;
public:
	Keeper();
	~Keeper();
	void add(Heroes* new_hero);
	void print();
	void remove(int num);
	void upload();
	void load();
	void free();
	void clear_file();
	void edit(int num);
	Heroes* get(int num);
	int get_count_arguments(string str, string delimiter);
	string* split(string str, string delimiter, int count);
	int input_int(string prompt);
	bool is_int(string str);

};
