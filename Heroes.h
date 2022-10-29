#pragma once
#include <iostream>
#include <sstream>

using std::string;
using std::cin;
using std::cout;

class Heroes
{
private:

public:
    string name, weapon, xp;
    enum HeroesTypes
    {
        FRIENDS = 1,
        ENEMIES,
        MONSTERS
    };
    Heroes();
    Heroes(const Heroes &obj);
    ~Heroes();

    virtual HeroesTypes get_type() = 0;
    virtual string describe() = 0;
};
