#pragma once
#include "Heroes.h"

class Monsters : public Heroes
{
private:
	//Имя, описание.
	string desc;
public:
	Monsters();
	Monsters(string name, string desc);
	~Monsters();

	void set_name(string name);
	string get_name();

	void set_desc(string desc);
	string get_desc();

	string describe() override;
	HeroesTypes get_type() override;

	friend std::istream& operator>> (std::istream& in, Monsters& monsters);
};
