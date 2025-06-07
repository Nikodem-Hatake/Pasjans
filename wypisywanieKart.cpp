#include <iostream>
#include <vector>
#include <windows.h>
#include "header.hpp"

HANDLE kolor = GetStdHandle(STD_OUTPUT_HANDLE);     //Zmienna do obsługi kolorów (uchwyt) (zasięg globalny ze wzgledu na wystąpienie w wielu funkcjach).

//Wypisywanie kart dla poszczególnej kolumny.
void Wypisywanie(std::vector <std::string> kolumna, int & odkryte, int numerKolumny, int kolorKierOrazKaro, int kolorPikOrazTrefl)
{
    std::cout << "Kolumna " << numerKolumny << ": ";
    if(kolumna.empty())
    {
        std::cout << "Brak!";
    }
    else
    {
        if(odkryte == 0)
        {
            odkryte = 1;
        }
        if(kolumna.size() == odkryte)
        {
            for(int i = kolumna.size() - 1; i >= 0; i --)
            {
                WypiszZKolorem(kolorKierOrazKaro, kolorPikOrazTrefl, kolumna[i]);
            }
        }
        else
        {
            for(int i = kolumna.size() - 1; i > kolumna.size() - 1 - odkryte; i --)
            {
                WypiszZKolorem(kolorKierOrazKaro, kolorPikOrazTrefl, kolumna[i]);
            }
            for(int i = odkryte; i < kolumna.size(); i ++)
            {
                std::cout << "x ";
            }
        }
    }
    std::cout << std::endl;
}

//Wypisywanie poszczególnego stosu.
void WypisywanieStosu(std::vector <std::string> stos, std::string nazwaStosu, int kolorKierOrazKaro, int kolorPikOrazTrefl)
{
    WypiszZKolorem(kolorKierOrazKaro, kolorPikOrazTrefl, nazwaStosu);
    if(stos.empty())
    {
        std::cout << "Brak!";
    }
    else
    {
        WypiszZKolorem(kolorKierOrazKaro, kolorPikOrazTrefl, stos.back());
    }
    std::cout << std::endl;
}

//Wypisanie pierwszej karty/kart ze stosu rezerwowego.
void WypisywanieRezerwowy(std::vector <std::string> rezerwowy, int & licznik, bool czyPusty, int kolorKierOrazKaro, 
int kolorPikOrazTrefl, int poziom)
{
    std::cout << std::endl << "Pierwsza karta stosu rezerwowego: ";
    if(czyPusty == true)
    {
        std::cout << "Brak!";
    }
    else
    {
        if(licznik < 0)
        {
            licznik = 23;
        }
        while(rezerwowy[licznik] == " ")
        {
            licznik --;
            if(licznik == -1)
            {
                licznik = 23;
            }
        }
        WypiszZKolorem(kolorKierOrazKaro, kolorPikOrazTrefl, rezerwowy[licznik]);
        if(poziom == 2) //Wypisywanie dwóch kolejnych kart w przypadku poziomu trudnego.
        {
            int kopiaLicznika = licznik;
            for(int i = 0; i < 2; i ++)
            {
                kopiaLicznika --;
                while(rezerwowy[kopiaLicznika] == " " || kopiaLicznika < 0)
                {
                    kopiaLicznika --;
                    if(kopiaLicznika < 0)
                    {
                        kopiaLicznika = 23;
                    }
                }
                if(licznik != kopiaLicznika)
                {
                    WypiszZKolorem(kolorKierOrazKaro, kolorPikOrazTrefl, rezerwowy[kopiaLicznika]);
                }
            }
        }
    }
    std::cout << std::endl;
}

void WypiszZKolorem(int kolorKierKaro, int kolorPikTrefl, std::string karta)    //Sprawdzenie jaki kolor powinien być wypisany dla karty.
{
    if(karta[0] == 'k' || karta[0] == 'K')
    {
        SetConsoleTextAttribute(kolor, kolorKierKaro);
    }
    else
    {
        SetConsoleTextAttribute(kolor, kolorPikTrefl);
    }
    std::cout << karta;
    if(karta == "Kier" || karta == "Karo" || karta == "Pik" || karta == "Trefl")    //Sprawdzanie czy do wypisania jest nazwa stosu końcowego czy sama karta.
    {
        std::cout << ": ";
    }
    else
    {
        std::cout << " ";
    }
    SetConsoleTextAttribute(kolor, 7);  //Przywrócenie domyślnego koloru dla konsoli (biały).
}