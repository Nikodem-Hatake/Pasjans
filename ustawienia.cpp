#include <iostream>
#include <windows.h>
#include "header.hpp"

//Ustawienia dotyczące kolorów kart, maksymalnej ilości ruchów oraz znaku zakańczającego gre.
void Ustawienia(int & iloscRuch, int & kolorKierKaro, int & kolorPikTrefl, char & znakKoniec, char & znakCofniecia)
{
    for(int i = 0; i < 25; i ++)    //Wyczyszczenie ekranu terminala.
    {
        std::cout << std::endl;
    }

    HANDLE kolorKart = GetStdHandle(STD_OUTPUT_HANDLE);     //Zmienna do obsługi kolorów (uchwyt).
    int wybor = 0;
    while(wybor != 4)
    {
        std::cout << "-------------Ustawienia-------------" << std::endl;
        std::cout << "1.Zmien maksymalna ilosc ruchow." << std::endl;
        std::cout << "2.Zmien kolory kart." << std::endl;
        std::cout << "3.Zmien przycisk do zakonczenia gry oraz cofniecia ruchu." << std::endl;
        std::cout << "4.Powrot do menu." << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cin >> wybor;
        if(wybor < 1 || wybor > 4)
        {
            std::cout << "Zla opcja!!" << std::endl;
        }
        else
        {
            int opcja[3];           //Tablica do wprowadzenia nowych ustawień i późniejszego sprawdzenia ich przed zapisaniem.
            char opcjaZnaku[2];     //Tablica do wpisania nowego znaku zakończenia gry/cofnięcia ruchu i późniejszego sprawdzenia go przed zapisem.
            switch(wybor)
            {
                case 1:
                {
                    std::cout << std::endl << "Domyslna maksymalna ilosc ruchow: " << INT_MAX << std::endl;
                    std::cout << "Podaj nowa ilosc maksymalnych ruchow (maksymalnie " << INT_MAX << "): ";
                    std::cin >> opcja[0];
                    if(opcja[0] < 1 || opcja[0] > 100000)
                    {
                        std::cout << "Zla wartosc" << std::endl;
                    }
                    else
                    {
                        iloscRuch = opcja[0];
                    }
                    break;
                }
                case 2:
                {
                    std::cout << std::endl << "Mozliwe kolory:" << std::endl;   //Wypisanie dostępnych kolorów.
                    SetConsoleTextAttribute(kolorKart, 1);
                    std::cout << "1.Niebieski" << std::endl;
                    SetConsoleTextAttribute(kolorKart, 2);
                    std::cout << "2.Limonkowy" << std::endl;
                    SetConsoleTextAttribute(kolorKart, 3);
                    std::cout << "3.Cyjanowy" << std::endl;
                    SetConsoleTextAttribute(kolorKart, 4);
                    std::cout << "4.Czerwony (domyslny dla kier i karo)" << std::endl;
                    SetConsoleTextAttribute(kolorKart, 5);
                    std::cout << "5.Fioletowy" << std::endl;
                    SetConsoleTextAttribute(kolorKart, 6);
                    std::cout << "6.Zolty" << std::endl;
                    SetConsoleTextAttribute(kolorKart, 7);
                    std::cout << "7.Bialy (domyslny dla pik i trefl)" << std::endl;
                    SetConsoleTextAttribute(kolorKart, 8);
                    std::cout << "8.Szary" << std::endl;
                    SetConsoleTextAttribute(kolorKart, 7);
                    std::cout << std::endl << "Kolory obu rodzaji kart nie moga byc takie same!!" << std::endl;
                    std::cout << "Zmien kolor dla kier i karo: ";
                    std::cin >> opcja[1];
                    std::cout << "Zmien kolor dla pik i trefl: ";
                    std::cin >> opcja[2];
                    if(opcja[1] == opcja[2] || (opcja[1] < 0 || opcja[1] > 8) || (opcja[2] < 0 || opcja[2] > 8))
                    {
                        std::cout << "Zly wybor kolorow" << std::endl;
                    }
                    else
                    {
                        kolorKierKaro = opcja[1];
                        kolorPikTrefl = opcja[2];
                    }
                    break;
                }
                case 3:
                {
                    char wyborOpcjiZmianyZnaku;
                    std::cout << std::endl << "1.Znak zakonczenia gry." << std::endl;
                    std::cout << "2.Znak cofniecia ruchu." << std::endl;
                    std::cout << "Ktory znak chcesz zmienic? ";
                    std::cin >> wyborOpcjiZmianyZnaku;
                    if(wyborOpcjiZmianyZnaku < 49 || wyborOpcjiZmianyZnaku > 50)
                    {
                        std::cout << "Zly wybor" << std::endl;
                    }
                    else
                    {
                        if(wyborOpcjiZmianyZnaku == '1')
                        {
                            std::cout << std::endl << "Zmiana znaku zakonczenia gry. Nie moze on byc z przedzialu cyfr od 1 do 9 ";
                            std::cout << "oraz nie moze byc taki sa, jak znak cofniecia ruchu.";
                            std::cout << std::endl << "Wprowadz nowy znak do zakonczenia gry (domyslne 'x'): ";
                            std::cin >> opcjaZnaku[0];
                            if((opcjaZnaku[0] > 48 && opcjaZnaku[0] < 58) || opcjaZnaku[0] == znakCofniecia)
                            {
                                std::cout << "Zly znak!" << std::endl;
                            }
                            else
                            {
                                znakKoniec = opcjaZnaku[0];
                            }
                        }
                        else if(wyborOpcjiZmianyZnaku == '2')
                        {
                            std::cout << std::endl << "Zmiana znaku cofniecia ruchu. Nie moze on byc z przedzialu cyfr od 1 do 9 ";
                            std::cout << "oraz nie moze byc taki sa, jak znak zakonczenia gry.";
                            std::cout << std::endl << "Wprowadz nowy znak do zakonczenia gry (domyslne 'c'): ";
                            std::cin >> opcjaZnaku[1];
                            if((opcjaZnaku[1] > 48 && opcjaZnaku[1] < 58) || opcjaZnaku[1] == znakKoniec)
                            {
                                std::cout << "Zly znak!" << std::endl;
                            }
                            else
                            {
                                znakCofniecia = opcjaZnaku[1];
                            }
                        }
                        
                    }
                    break;
                }
                case 4:
                {
                    return;
                    break;
                }
            }
            std::cout << std::endl;
        }
    }
}