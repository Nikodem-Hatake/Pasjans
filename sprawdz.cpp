#include <iostream>
#include <vector>
#include "header.hpp"

//Sprawdzanie czy można odłożyć karte na kolumne.
bool SprawdzRuch(std::string kartaRuchJeden, std::string kartaRuchDwa)
{
    if(kartaRuchJeden[0] == 'k')
    {
        if(kartaRuchDwa[0] == 'k')
        {
            return false;
        }
    }
    else if(kartaRuchJeden[0] == 'p' || kartaRuchJeden[0] == 't')
    {
        if(kartaRuchDwa[0] == 'p' || kartaRuchDwa[0] == 't')
        {
            return false;
        }
    }

    if(kartaRuchJeden[kartaRuchJeden.length() - 1] == 'K' && kartaRuchDwa == "empty")
    {
        return true;
    }
    else if(kartaRuchJeden[kartaRuchJeden.length() - 1] == 'Q' && kartaRuchDwa[kartaRuchDwa.length() - 1] == 'K')
    {
        return true;
    }
    else if(kartaRuchJeden[kartaRuchJeden.length() - 1] == 'J' && kartaRuchDwa[kartaRuchDwa.length() - 1] == 'Q')
    {
        return true;
    }
    else if(kartaRuchJeden[kartaRuchJeden.length() - 2] == '1' && kartaRuchDwa[kartaRuchDwa.length() - 1] == 'J')
    {
        return true;
    }
    else if(kartaRuchJeden[kartaRuchJeden.length() - 1] == '9' && kartaRuchDwa[kartaRuchDwa.length() - 2] == '1')
    {
        return true;
    }
    else if(kartaRuchJeden[kartaRuchJeden.length() - 1] == kartaRuchDwa[kartaRuchDwa.length() - 1] - 1 && kartaRuchJeden[kartaRuchJeden.length() - 1] < 58)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Sprawdzanie czy można odłożyc kartę na stos końcowy.
bool SprawdzStosKoncowy(std::string kartaRuchJeden, std::string kartaRuchDwa)
{
    if(kartaRuchJeden[0] == kartaRuchDwa[0] && kartaRuchJeden[1] == kartaRuchDwa[1])
    {
        if(kartaRuchJeden[kartaRuchJeden.length() - 1] == 'K' && kartaRuchDwa[kartaRuchDwa.length() - 1] == 'Q')
        {
            return true;
        }
        else if(kartaRuchJeden[kartaRuchJeden.length() - 1] == 'Q' && kartaRuchDwa[kartaRuchDwa.length() - 1] == 'J')
        {
            return true;
        }
        else if(kartaRuchJeden[kartaRuchJeden.length() - 1] == 'J' && kartaRuchDwa[kartaRuchDwa.length() - 2] == '1')
        {
            return true;
        }
        else if(kartaRuchJeden[kartaRuchJeden.length() - 1] == '2' && kartaRuchDwa[kartaRuchDwa.length() - 1] == 'A')
        {
            return true;
        }
        else if(kartaRuchJeden[kartaRuchJeden.length() - 2] == '1' && kartaRuchDwa[kartaRuchDwa.length() - 1] == '9')
        {
            return true;
        }
        else if(kartaRuchJeden[kartaRuchJeden.length() - 1] == 'A' && kartaRuchDwa[2] == 'e')
        {
            return true;
        }
        else if(kartaRuchJeden[kartaRuchJeden.length() - 1] == kartaRuchDwa[kartaRuchDwa.length() - 1] + 1 && kartaRuchJeden[kartaRuchJeden.length() - 1] < 58)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

//Sprawdzanie czy można przełożyć kartę/karty z wybranej kolumny (ruch pierwszy).
void RuchPierwszy(bool & poprawnoscRuchu, int & ileDoPrzeniesienia, std::string & kartaRuchJeden, int ileOdkrytych, std::vector <std::string> kolumna)
{
    if(kolumna.empty())
    {
        std::cout << "Niemozesz wykonac ruchu dla tej kolumny!";
        poprawnoscRuchu = false;
    }
    else
    {
        if(ileOdkrytych == 1)
        {
            kartaRuchJeden = kolumna.back();
        }
        else
        {
            std::cout << "Ile chcesz przeniesc kart? (max " << ileOdkrytych << "): ";
            std::cin >> ileDoPrzeniesienia;
            if(ileDoPrzeniesienia < 1 || ileDoPrzeniesienia > ileOdkrytych)
            {
                std::cout << "Niemozesz przeniesc tyle kart!";
                poprawnoscRuchu = false;
            }
            else
            {
                kartaRuchJeden = kolumna[kolumna.size() - ileDoPrzeniesienia];
            }
        }
    }
    std::cout << std::endl;
}

//Przekladanie kart z kolumny/stosu rezerwowego z ruchu pierwszego na kolumnę z ruchu drugiego.
void RuchDrugi(int numerKolumnyPrzeniesienia, int ilePrzeniesc, int iloscOdkrytychKart[],
int indeksOdkrytychKart, int & licznikRezerwowego, std::vector <std::string> & kolumnaJeden, std::vector <std::string> & kolumnaDwa)
{
    if(indeksOdkrytychKart != 7)
    {
        if(numerKolumnyPrzeniesienia != 8)
        {
            for(int i = kolumnaJeden.size() - ilePrzeniesc; i < kolumnaJeden.size(); i ++)  //Przekładanie kart na wybraną kolumnę z ruchu drugiego.
            {
                kolumnaDwa.push_back(kolumnaJeden[i]);
                iloscOdkrytychKart[indeksOdkrytychKart] ++;
            }
            for(int i = 0; i < ilePrzeniesc; i ++)  //Usuwanie kart z kolumny z ruchu pierwszego.
            {
                kolumnaJeden.pop_back();
                iloscOdkrytychKart[numerKolumnyPrzeniesienia - 1] --;
            }
        }
        else
        {
            kolumnaDwa.push_back(kolumnaJeden[licznikRezerwowego]);
            iloscOdkrytychKart[indeksOdkrytychKart] ++;
            kolumnaJeden[licznikRezerwowego] = " ";
            licznikRezerwowego --;
        }
    }
    else
    {
        if(numerKolumnyPrzeniesienia != 8)
        {
            kolumnaDwa.push_back(kolumnaJeden.back());
            kolumnaJeden.pop_back();
            iloscOdkrytychKart[numerKolumnyPrzeniesienia - 1] --;
        }
        else
        {
            kolumnaDwa.push_back(kolumnaJeden[licznikRezerwowego]);
            kolumnaJeden[licznikRezerwowego] = " ";
            licznikRezerwowego --;
        }
    }
}