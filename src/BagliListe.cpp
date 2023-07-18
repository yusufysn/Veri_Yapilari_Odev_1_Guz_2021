/**
* @file        BagliListe
* @description veri.txt dosyasini okuyup iki yonlu bagli liste olusturmak 
* @course      1.Ogretim A grubu
* @assignment  1.Odev
* @date        09.11.2021
* @author      Yusuf Yesin  B201210059  yusuf.yesin@ogr.sakarya.edu.tr 
*/
#include "BagliListe.hpp"
#include "Dugum.hpp"
#include <iostream>
#include <string>

using namespace std;

BagliListe::BagliListe()
{
    ilk = 0;
    dugumSayisi = 0;
}
void BagliListe::ekle(string isim ,int index)
{
    Dugum* yeni = new Dugum(isim);
    if(ilk==0)
    {
        dugumSayisi++;
        ilk=yeni;
        return;
    }
    Dugum* gecici = ilk;
    while(gecici->sonraki!=0)
    {
        gecici=gecici->sonraki;
    }
    gecici->sonraki=yeni;
    yeni->onceki=gecici;
    dugumSayisi++;
    Dugum* gec = yeni;
    if(index<dugumSayisi && index>=0)
    {
        for(int i=0;i<(dugumSayisi-index-1);i++)
        {
            gec->isim=gec->onceki->isim;
            gec=gec->onceki;
        }
    }
    gec->isim = isim;
}
void BagliListe::yazdir()
{
    if(ilk == 0)
    {
        return;
    }
    Dugum* gecici = ilk;
    for(int i=0;i<dugumSayisi;i++)
    {
        cout<<gecici->isim;
        if(gecici->sonraki!=0)
            cout<<" <--> ";
        gecici=gecici->sonraki;
    }
}
void BagliListe::cikar(int index)
{
    if(ilk==0) return;
    if(ilk->sonraki==0)
    {
        delete ilk;
        ilk=0;
        dugumSayisi--;
        return;
    }
    Dugum* gecici=ilk;
    if(index<dugumSayisi && index>=0)
    {
        for(int i=0;i<index;i++)
        {
            gecici=gecici->sonraki;
        }
        for(int i=0;i<dugumSayisi-index-1;i++)
        {
            gecici->isim=gecici->sonraki->isim;
        }
    }
    while(gecici->sonraki!=0)
    {
        gecici=gecici->sonraki;
    }
    gecici->onceki->sonraki=0;
    delete gecici;
    dugumSayisi--;
}