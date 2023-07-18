/**
* @file        DosyaOku
* @description veri.txt dosyasini okuyup iki yonlu bagli liste olusturmak 
* @course      1.Ogretim A grubu
* @assignment  1.Odev
* @date        09.11.2021
* @author      Yusuf Yesin  B201210059  yusuf.yesin@ogr.sakarya.edu.tr 
*/
#include "DosyaOku.hpp"
#include "BagliListe.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

DosyaOku::DosyaOku()
{
    ifstream dosyaoku("./doc/Veri.txt");
    if(!dosyaoku.is_open())
    {
	cout<<"Veri.txt dosyasi bulunamadi."<<endl;
	system("pause");
	exit(0);
    }
    else
    {
        BagliListe* b = new BagliListe();

        string satir = " ";
        while(getline(dosyaoku ,satir))
        {
            int index1 ,index2;
            if(satir[0]=='E')
            {
                index1 = 1;
                index2 = satir.find("#");
                char str2[10];
                size_t length2 = satir.copy(str2, index2-index1-1 , index1+1 );
                str2[length2] = '\0';
                int eklenecekSira = stoi(str2);

                index1 = satir.find("#");
                index2 = satir.find(")");
                char str1[10];
                size_t length = satir.copy(str1, index2-index1-1, index1+1);
                str1[length] = '\0';

                b->ekle(str1 ,eklenecekSira);
            }
            else if(satir[0]=='S')
            {
                index1 = 1;
                index2 = satir.find(")");
                char str3[10];
                size_t length3 = satir.copy(str3, index2-index1-1, index1+1);
                str3[length3] = '\0';
                int silinecekSira = stoi(str3);
                b->cikar(silinecekSira);
            }
        }
        b->yazdir();
    }
}