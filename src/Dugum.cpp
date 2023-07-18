/**
* @file        Dugum
* @description veri.txt dosyasini okuyup iki yonlu bagli liste olusturmak 
* @course      1.Ogretim A grubu
* @assignment  1.Odev
* @date        09.11.2021
* @author      Yusuf Yesin  B201210059  yusuf.yesin@ogr.sakarya.edu.tr 
*/
#include "Dugum.hpp"
#include <iostream>
#include <string>

using namespace std;

Dugum::Dugum(string isim)
{
    this->isim=isim;
    this->onceki=0;
    this->sonraki=0;
}
