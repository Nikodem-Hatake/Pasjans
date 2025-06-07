#include <iostream>
#include <cstdlib>
#include "header.hpp"

int kolorKartJeden = 4;                 //Kolory dla Kier i Karo.
int kolorKartDwa = 7;                   //Kolory dla Pik i Trefl.
int maksymalnaIloscRuchow = INT_MAX;    //Maksymalna ilość ruchów jakie można wykonać w jednej grze.
char znakZakonczeniaGry = 'x';          //Znak którym można zakoćczym gre.
char cofniecieRuchu = 'c';              //Znak którym można cofnąć ruch.

int main()
{
    char znak = '0';
    //Pętla do while do wyświetlania menu oraz wyboru dostępnych opcji dopóki niewyłączy się gry.
    do
    {
        Menu();
        znak = getchar();
        switch (znak)
        {
            case '1':
            {
                Gra(kolorKartJeden, kolorKartDwa, maksymalnaIloscRuchow, znakZakonczeniaGry, cofniecieRuchu);
                break;
            }
            case '2':
            {
                Ustawienia(maksymalnaIloscRuchow, kolorKartJeden, kolorKartDwa, znakZakonczeniaGry, cofniecieRuchu);
                break;
            }
            case '3':
            {
                Ranking();
                break;
            }
            case '4':
            {
                return 0;
                break;
            }
        }
    }
    while(znak != '4');
}