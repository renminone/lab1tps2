#pragma once
#pragma once
#include "Heroes.h"

class Friends : public Heroes
{
private:
	// Имя, оружие, навыки
public:
	Friends();
	Friends(string name, string weapon, string xp);
	~Friends();

	void set_name(string name);
	string get_name();

	void set_weapon(string weapon);
	string get_weapon();

	void set_xp(string xp);
	string get_xp();

	string describe() override;
	HeroesTypes get_type() override;

	friend std::istream& operator>> (std::istream& in, Friends& plane);
};
