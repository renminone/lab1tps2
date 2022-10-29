#include <iostream>
#include "Heroes.h"

using namespace std;

Heroes::Heroes()
{
    cout << "\nSYSTEM MESSAGE!\nHERO CONSTRUCTOR WITHOUT PARAMETRES WAS CALLED!\n\n";
}

Heroes::Heroes(const Heroes &obj)
{      
    cout << "\nSYSTEM MESSAGE!\HEROES COPY CONSTRUCTOR WAS CALLED!\n\n";
}

Heroes::~Heroes()
{
    cout << "\nSYSTEM MESSAGE!\nHERO DESTRUCTOR WAS CALLED!\n\n";
}
