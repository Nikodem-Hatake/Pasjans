#include <iostream>
#include <vector>
#include <fstream>

void Ranking()  //Wyswietlanie rankingu graczy.
{
    for(int i = 0; i < 10; i ++)    //Wyczyszczenie ekranu.
    {
        std::cout << std::endl;
    }
    std::fstream plik;
    plik.open("ranking.txt", std::ios::in | std::ios::binary);
    if(plik.good())
    {
        std::string nick;
        int ruch;
        int max;                    //Zmienna do sortowania.
        int pozycjaMax;             //Zmienna do zmiany liczb w vectorze w sortowaniu.
        int tymczasowaWartoscRuchu; //Zmienna do sortowania (do zmiany miejsc w vectorze).
        std::string tymczasowyNick; //Zmienna do sortowania (do zmiany miejsc w vectorze).
        std::vector <std::string> nicki;
        std::vector <int> ruchy;
        std::cout << "--------------RANKING--------------" << std::endl;
        std::cout << "nr nazwa gracza   " << "ilosc ruchow" << std::endl;
        while(plik >> nick >> ruch) //Zapis do zmiennych a pozniej do vectora.
        {
            nicki.push_back(nick);
            ruchy.push_back(ruch);
        }
        for(int i = 0; i < ruchy.size(); i ++)  //Sortowanie (poprzez zmiane miejsc miedzy maksymalna wartoscia ruchu a i-tym elementem).
        {
            max = 0;
            pozycjaMax = i;
            for(int j = i; j < ruchy.size(); j ++)
            {
                if(ruchy[j] > max)
                {
                    max = ruchy[j];
                    pozycjaMax = j;
                }
            }
            tymczasowaWartoscRuchu = ruchy[i];
            ruchy[i] = ruchy[pozycjaMax];
            ruchy[pozycjaMax] = tymczasowaWartoscRuchu;
            tymczasowyNick = nicki[i];
            nicki[i] = nicki[pozycjaMax];
            nicki[pozycjaMax] = tymczasowyNick;
        }
        for(int i = ruchy.size() - 1; i >= 0; i --) //Pętla do wypisania posortowanego rankingu.
        {
            std::cout << (i - ruchy.size()) * -1 << ". " << nicki[i];
            for(int j = 15 - nicki[i].size(); j > 0; j --)  //Petla do dopisywania spacji podczas wypisywania (zeby wyniki ladnie wygladaly :) ).
            {
                std::cout << " ";
            }
            std::cout << ruchy[i] << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
        plik.close();
    }
    else
    {
        std::cout << "Nieudalo sie wczytac rankingu :(" << std::endl;
    }
    for(int i = 0; i < 10; i ++)    //Wyczyszczenie ekranu.
    {
        std::cout << std::endl;
    }
}

void ZapiszDoRankingu(std::string nazwaGracza, int iloscRuchow) //Zapis wyniku gracza do rankingu.
{
    std::fstream plik;
    plik.open("ranking.txt", std::ios::app);
    if(plik.good())
    {
        plik << nazwaGracza << " " << iloscRuchow << std::endl;     //Oddzielanie nazwy od ruchow spacja ulatwia pozniejszy odczyt z pliku.
        plik.close();
    }
    else
    {
        std::cout << "Nieudalo sie zapisac wynikow do rankingu!" << std::endl;
    }
}