#include <iostream>
#include <vector>
#include "header.hpp"

//Funkcja obsługująca cofanie ruchu (robi odwrotność funkcji "RuchDrugi").
void CofnijRuch(int numerKolumnyPrzeniesienia, int ilePrzeniesc, int iloscOdkrytychKart[], int indeksOdkrytychKart, int numerLicznikaCofniecie, 
int & licznikStosu, std::string kartaStosuRezerwowego, std::vector <std::string> & kolumnaJeden, std::vector <std::string> & kolumnaDwa)
{
    if(indeksOdkrytychKart == 11)   //Cofnięcie ruchu który sprawdzał kolejną/kolejne kartę/karty na stosie rezerwowym.
    {
        licznikStosu = numerLicznikaCofniecie;
    }
    else
    {
        if(numerKolumnyPrzeniesienia != 8)  //Od 1 do 7 - Ruch kolumna - kolumna/stos końcowy.
        {
            for(int i = kolumnaDwa.size() - ilePrzeniesc; i < kolumnaDwa.size(); i ++)
            {
                kolumnaJeden.push_back(kolumnaDwa[i]);
                iloscOdkrytychKart[numerKolumnyPrzeniesienia - 1] ++;
            }
            iloscOdkrytychKart[numerKolumnyPrzeniesienia - 1] --;
            for(int i = 0; i < ilePrzeniesc; i ++)
            {
                kolumnaDwa.pop_back();
                if(indeksOdkrytychKart < 7)
                {
                    iloscOdkrytychKart[indeksOdkrytychKart] --;
                }
            }
        }
        else    //Ruch stos rezerwowy - kolumna/stos końcowy.
        {
            licznikStosu = numerLicznikaCofniecie;
            kolumnaJeden[licznikStosu] = kartaStosuRezerwowego;
            kolumnaDwa.pop_back();
            if(indeksOdkrytychKart < 7)
            {
                iloscOdkrytychKart[indeksOdkrytychKart] --;
            }
        }
    }
}