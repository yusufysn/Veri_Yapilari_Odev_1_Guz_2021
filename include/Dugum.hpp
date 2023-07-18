#ifndef Dugum_hpp
#define Dugum_hpp
#include <string>
#include <iostream>

using namespace std;

class Dugum
{
public:
    Dugum(string isim);

    string isim;
    Dugum* onceki;
    Dugum* sonraki;
};

#endif