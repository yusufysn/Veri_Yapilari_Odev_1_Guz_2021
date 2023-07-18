#ifndef BagliListe_hpp
#define BagliListe_hpp
#include <string>
#include <iostream>
#include "Dugum.hpp"

using namespace std;

class BagliListe 
{
public:
    BagliListe();
    ~BagliListe();
    void ekle(string veri ,int index);
    void yazdir();
    void cikar(int index);
private:
    int dugumSayisi;
    Dugum* ilk;
};
#endif