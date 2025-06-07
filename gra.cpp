#include <iostream>
#include <time.h>       //Obsługa pseudolosowania kart
#include <cstdlib>      
#include <vector>
#include "header.hpp"

void Gra(int kolorKierKaro, int kolorPikTrefl, int maxIloscRuchow, char znakZakonczeniaRozgrywki, char znakCofnieciaRuchu)  //Po prostu gra :).
{
    srand(time(NULL));                                  //Funkcja do prawidłowego działania pseudolosowania kart na początku gry.
    //Zmienne na potrzeby gry.
    bool czyStosRezerwowyPusty = false;                 //false = niema kart w stosie rezerwowym, true = istnieje jedna lub więcej kart w stosie rezerwowym.
    bool wynik = false;                                 //false = przegrana, true = wygrana.
    bool zakonczenieGry = false;                        //false = gra dalej trwa, true = koniec gry (można sprawdzic wtedy zmienną wynik).
    int tablicaNumeryIndeksu[52];                       //Pseudolosowe indeksy tablicy z kartami.
    int ileOdkrytychKart[7] = {1, 1, 1, 1, 1, 1, 1};    //Sprawdzanie ilości możliwych kart w kolumnach do przenoszenia.
    int licznikStosuRezerwowego = 23;                   //Zmienna do poprawnego działania stosu rezerwowego(wskazuje na obecny indeks stosu).
    int kopiaLicznikaStosuRezerwowego;                  //Kopia licznika stosu rezerwowego.
    int licznikPelnychRuchow = 0;                       //Zmienna do zliczania ruchów.
    int poziomTrudnosci = 0;                            //Zmienna do wybrania poziomu trudności.
    int licznikCofniec = 0;                             //Zlicza ile razy mozna cofnąć ruch (maksymalnie 3 wedlug zasad).
    int numerKolumnyCofniecia[3];                       //Tablica przechowująca numer kolumny dla której jest wykonywane cofnięcie ruchu.
    int ilePrzeniescCofniecia[3];                       //Tablica przechowująca ile kart było przeniesionych podczas ruchu który chce się cofnąć.
    int indeksOdkrytychKartCofniecia[3];                //Tablica przechowująca indeksy tablicy "ileOdkrytychKart" z ruchów.
    int numerLicznikaRezerwowegoCofniecia[3];           //Tablica przechowująca indeks poprzedniej karty na stosie rezerwowym.
    std::string kartyStosuRezerwowegoCofniecie[3];      //Tablica przechowująca jakie karty były w stosie rezerwowym.
    std::vector <std::string> * wskaznikCofniecie[3];   //Tablica przechowująca wskaźniki na kolumny z ruchu pierwszego.
    std::vector <std::string> * wskaznikCofniecieDwa[3];//Tablica przechowująca wskaźniki na kolumny z ruchu drugiego.
    //Kolumny i stosy.
    std::vector <std::string> kolumna1;
    std::vector <std::string> kolumna2;
    std::vector <std::string> kolumna3;
    std::vector <std::string> kolumna4;
    std::vector <std::string> kolumna5;
    std::vector <std::string> kolumna6;
    std::vector <std::string> kolumna7;
    std::vector <std::string> stosKoncowyKier;
    std::vector <std::string> stosKoncowyKaro;
    std::vector <std::string> stosKoncowyPik;
    std::vector <std::string> stosKoncowyTrefl;
    std::vector <std::string> stosRezerwowy;
    int sprawdzanieDoLosowania[52] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    , 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};   //Tablica do sprawdzania czy niema dwóch tych samych pseudowylosowanych indeksów.
    std::string karty[52] = {"kierA" , "kier2", "kier3", "kier4", "kier5", "kier6", "kier7", "kier8", "kier9", "kier10", "kierJ", "kierQ", "kierK"
    , "karoA" , "karo2", "karo3", "karo4", "karo5", "karo6", "karo7", "karo8", "karo9", "karo10", "karoJ", "karoQ", "karoK"
    , "pikA" , "pik2", "pik3", "pik4", "pik5", "pik6", "pik7", "pik8", "pik9", "pik10", "pikJ", "pikQ", "pikK"
    , "treflA" , "trefl2", "trefl3", "trefl4", "trefl5", "trefl6", "trefl7", "trefl8", "trefl9", "trefl10", "treflJ", "treflQ", "treflK"};

    //Pseudolsowanie kolejności kart.
    for(int i = 0; i < 52; i ++)
    {
        int losowaLiczba = rand() % 52;
        while(sprawdzanieDoLosowania[losowaLiczba] == 0)    //Pętla działa dopóki nie wylosuje inndeksu którego nie było.
        {
            losowaLiczba = rand() % 52;
        }
        sprawdzanieDoLosowania[losowaLiczba] = 0;
        tablicaNumeryIndeksu[i] = losowaLiczba;
    }

    //Początkowe dodawanie kart do kolumn.
    kolumna1.push_back(karty[tablicaNumeryIndeksu[0]]);
    kolumna2.push_back(karty[tablicaNumeryIndeksu[1]]);
    kolumna2.push_back(karty[tablicaNumeryIndeksu[2]]);
    kolumna3.push_back(karty[tablicaNumeryIndeksu[3]]);
    kolumna3.push_back(karty[tablicaNumeryIndeksu[4]]);
    kolumna3.push_back(karty[tablicaNumeryIndeksu[5]]);
    kolumna4.push_back(karty[tablicaNumeryIndeksu[6]]);
    kolumna4.push_back(karty[tablicaNumeryIndeksu[7]]);
    kolumna4.push_back(karty[tablicaNumeryIndeksu[8]]);
    kolumna4.push_back(karty[tablicaNumeryIndeksu[9]]);
    kolumna5.push_back(karty[tablicaNumeryIndeksu[10]]);
    kolumna5.push_back(karty[tablicaNumeryIndeksu[11]]);
    kolumna5.push_back(karty[tablicaNumeryIndeksu[12]]);
    kolumna5.push_back(karty[tablicaNumeryIndeksu[13]]);
    kolumna5.push_back(karty[tablicaNumeryIndeksu[14]]);
    kolumna6.push_back(karty[tablicaNumeryIndeksu[15]]);
    kolumna6.push_back(karty[tablicaNumeryIndeksu[16]]);
    kolumna6.push_back(karty[tablicaNumeryIndeksu[17]]);
    kolumna6.push_back(karty[tablicaNumeryIndeksu[18]]);
    kolumna6.push_back(karty[tablicaNumeryIndeksu[19]]);
    kolumna6.push_back(karty[tablicaNumeryIndeksu[20]]);
    kolumna7.push_back(karty[tablicaNumeryIndeksu[21]]);
    kolumna7.push_back(karty[tablicaNumeryIndeksu[22]]);
    kolumna7.push_back(karty[tablicaNumeryIndeksu[23]]);
    kolumna7.push_back(karty[tablicaNumeryIndeksu[24]]);
    kolumna7.push_back(karty[tablicaNumeryIndeksu[25]]);
    kolumna7.push_back(karty[tablicaNumeryIndeksu[26]]);
    kolumna7.push_back(karty[tablicaNumeryIndeksu[27]]);
    //Początkowe zapełnienie stosu rezerwowego.
    for(int i = 28; i < 52; i ++)
    {
        stosRezerwowy.push_back(karty[tablicaNumeryIndeksu[i]]);
    }

    //Wybór poziomu trudności.
    while(poziomTrudnosci < 1 || poziomTrudnosci > 2)
    {
        std::cout << std::endl<< "Poziomy trudnosci" << std::endl;
        std::cout << "1.Latwy" << std::endl;
        std::cout << "2.Trudny" << std::endl;
        std::cout << "Wybierz poziom trudnosci: " << std::endl;
        std::cin >> poziomTrudnosci;
        if(poziomTrudnosci < 0 || poziomTrudnosci > 2)
        {
            std::cout << std::endl << "Zly poziom trudnosci" << std::endl << std::endl;
        }
    }

    //Rozpoczęcie gry.
    while(zakonczenieGry == false && licznikPelnychRuchow < maxIloscRuchow)
    {
        for(int i = 0; i < 20; i ++)    //Wyczyszczenie ekranu terminala (zostaje wtedy możliwosc podejrzenia poprzednich ruchów poprzez scrollowanie w góre).
        {
            std::cout << std::endl;
        }

        //Wypisanie kart z każdej kolumny oraz ilości ruchów.
        std::cout << "Ilosc wykonanych ruchow: " << licznikPelnychRuchow << "   ";
        if(maxIloscRuchow - licznikPelnychRuchow <= 100)
        {
            std::cout << "Zostalo ci: " << maxIloscRuchow - licznikPelnychRuchow << " ruchow!!!";
        }
        std::cout << std::endl << "Mozesz cofnac " << licznikCofniec;
        if(licznikCofniec == 1)
        {
            std::cout << " raz.";
        }
        else
        {
            std::cout << " razy.";
        }
        std::cout << std::endl << std::endl << "Twoje karty:" << std::endl;
        Wypisywanie(kolumna1, ileOdkrytychKart[0], 1, kolorKierKaro, kolorPikTrefl);
        Wypisywanie(kolumna2, ileOdkrytychKart[1], 2, kolorKierKaro, kolorPikTrefl);
        Wypisywanie(kolumna3, ileOdkrytychKart[2], 3, kolorKierKaro, kolorPikTrefl);
        Wypisywanie(kolumna4, ileOdkrytychKart[3], 4, kolorKierKaro, kolorPikTrefl);
        Wypisywanie(kolumna5, ileOdkrytychKart[4], 5, kolorKierKaro, kolorPikTrefl);
        Wypisywanie(kolumna6, ileOdkrytychKart[5], 6, kolorKierKaro, kolorPikTrefl);
        Wypisywanie(kolumna7, ileOdkrytychKart[6], 7, kolorKierKaro, kolorPikTrefl);

        //Wypisanie kart z każdego stosu końcowego.
        std::cout << std::endl << "Pierwsze karty na stosie koncowym:" << std::endl;
        WypisywanieStosu(stosKoncowyKier, "Kier", kolorKierKaro, kolorPikTrefl);
        WypisywanieStosu(stosKoncowyKaro, "Karo", kolorKierKaro, kolorPikTrefl);
        WypisywanieStosu(stosKoncowyPik, "Pik", kolorKierKaro, kolorPikTrefl);
        WypisywanieStosu(stosKoncowyTrefl, "Trefl", kolorKierKaro, kolorPikTrefl);

        //Sprawdzanie czy stos rezerwowy jest pusty oraz wypisanie pierwszej dostepnej karty z niego.
        czyStosRezerwowyPusty = true;
        for(int i = 0; i < 24; i ++)
        {
            if(stosRezerwowy[i] != " ")
            {
                czyStosRezerwowyPusty = false;
                i += 24;                            //Zakoćczenie działania pętli.
            }
        }
        WypisywanieRezerwowy(stosRezerwowy, licznikStosuRezerwowego, czyStosRezerwowyPusty, kolorKierKaro, kolorPikTrefl, poziomTrudnosci);
        
        //Wykonywanie ruchu.
        std::cout << std::endl << "Wykonaj ruch! (wybierz kolumne od 1 do 7, stos rezerwowy wpisujac 8, zakoncz gre wpisujac znak '";
        std::cout << znakZakonczeniaRozgrywki << "' lub cofnij ruch wpisujac znak '" << znakCofnieciaRuchu << "'): ";
        char ruchPierwszyWybor;
        bool poprawnyRuch = true;   //Zmienna która przechowa informacje, czy ruch jest wykonywany prawidłowo.
        int ilePrzeniescKart = 1;
        int numerKolumnyDoPrzeniesienia;
        std::cin >> ruchPierwszyWybor;
        if(ruchPierwszyWybor == znakZakonczeniaRozgrywki)   //Zakończenie rozgrywki (przegrana).
        {
            zakonczenieGry = true;
        }
        else if(ruchPierwszyWybor == znakCofnieciaRuchu)    //Cofnięcie ruchu.
        {
            if(licznikCofniec > 0)
            {
                licznikCofniec --;
                CofnijRuch(numerKolumnyCofniecia[licznikCofniec], ilePrzeniescCofniecia[licznikCofniec], ileOdkrytychKart, 
                indeksOdkrytychKartCofniecia[licznikCofniec], numerLicznikaRezerwowegoCofniecia[licznikCofniec], licznikStosuRezerwowego,
                kartyStosuRezerwowegoCofniecie[licznikCofniec], (* wskaznikCofniecie[licznikCofniec]), (* wskaznikCofniecieDwa[licznikCofniec]));
            }
            else
            {
                std::cout << "Nie mozna cofnac ruchu!";
            }
        }
        else if(ruchPierwszyWybor < 49 || ruchPierwszyWybor > 56)
        {
            std::cout << "Wykonano zly ruch!" << std::endl;
        }
        else
        {
            int ruchPierwszyCyfra;                                      //Zmienna która będzie przechowywać wartość ruchu pierwszego jako cyfrę.
            std::string kartaZRuchuPierwszego;                          //Zmienna do zapamiętania karty wybranej w pierwszym ruchu.
            std::vector <std::string> * tymczasowyWskaznikJeden;        //Wskaznik na kolumnę z ruchu pierwszego.
            for(int i = 1; i < 9; i ++)     //Zamiana chara (wartości ruchu pierwszego) na inta (cyfrę).
            {
                if(ruchPierwszyWybor == 48 + i)
                {
                    ruchPierwszyCyfra = i;
                    i += 9;     //Zakończenie działania pętli.
                }
            }
            numerKolumnyDoPrzeniesienia = ruchPierwszyCyfra;
            switch(ruchPierwszyWybor)
            {
                case '1':
                {
                    tymczasowyWskaznikJeden = & kolumna1;
                    break;
                }
                case '2':
                {
                    tymczasowyWskaznikJeden = & kolumna2;
                    break;
                }
                case '3':
                {
                    tymczasowyWskaznikJeden = & kolumna3;
                    break;
                }
                case '4':
                {
                    tymczasowyWskaznikJeden = & kolumna4;
                    break;
                }
                case '5':
                {
                    tymczasowyWskaznikJeden = & kolumna5;
                    break;
                }
                case '6':
                {
                    tymczasowyWskaznikJeden = & kolumna6;
                    break;
                }
                case '7':
                {
                    tymczasowyWskaznikJeden = & kolumna7;
                    break;
                }
                case '8':
                {
                    //Sprawdzanie czy można wybrać kartę ze stosu rezerwowego.
                    if(czyStosRezerwowyPusty == true)
                    {
                        std::cout << "Niemozesz wykonac ruchu dla stosu rezerwowego!" << std::endl;
                        poprawnyRuch = false;
                    }
                    else
                    {

                        kartaZRuchuPierwszego = stosRezerwowy[licznikStosuRezerwowego];
                        tymczasowyWskaznikJeden = & stosRezerwowy;
                    }
                    break;
                }
            }
            if(ruchPierwszyWybor != '8')
            {
                RuchPierwszy(poprawnyRuch, ilePrzeniescKart, kartaZRuchuPierwszego, 
                ileOdkrytychKart[numerKolumnyDoPrzeniesienia - 1], (* tymczasowyWskaznikJeden));
            }
            if(poprawnyRuch == true)
            {
                //Wykonanie drugiego ruchu.
                std::cout << std::endl << "Wybierz co chcesz zrobic (wybierz inna kolumne od 1 do 7, stos koncowy jako numer 8 lub w przypadku wybrania ";
                std::cout << std::endl << "stosu rezerwowego, wpisz 9 aby sprawdzic nastepna karte ze stosu): ";
                bool czyPoprawnyRuch;
                char ruchDrugiWybor;
                int ruchDrugiCyfra;                 //Zmienna która będzie przechowywać wartość ruchu drugiego jako cyfrę.
                int tymczasowyIndeksOdkrytychKart;  //Tymczasowo przechowuje informacje o indeksie odkrytych kart w ruchu(trafia do tablicy od cofania).
                std::vector <std::string> * tymczasowyWskaznikDrugi;    //Wskaznik na kolumnę z ruchu drugiego.
                int tymczasowyLicznikRezerwowego = licznikStosuRezerwowego;
                std::cin >> ruchDrugiWybor;
                if(ruchDrugiWybor < 49 || ruchDrugiWybor > 57)
                {
                    std::cout << "Wykonano zly ruch!" << std::endl;
                }
                else
                {
                    for(int i = 1; i < 10; i ++)     //Zamiana chara (wartości ruchu drugiego) na inta (cyfrę).
                    {
                        if(ruchDrugiWybor == 48 + i)
                        {
                            ruchDrugiCyfra = i;
                            i += 10;    //Zakończenie działania pętli.
                        }
                    }
                    if(ruchDrugiCyfra < 8)
                    {
                        tymczasowyIndeksOdkrytychKart = ruchDrugiCyfra - 1;
                    }
                    std::string kartaZRuchuDrugiego;
                    if(numerKolumnyDoPrzeniesienia == ruchDrugiCyfra && ruchDrugiCyfra != 8)
                    {
                        std::cout << "Wykonano zly ruch!" << std::endl;
                    }
                    else
                    {
                        switch(ruchDrugiWybor)
                        {
                            case '1':
                            {
                                if(kolumna1.empty())
                                {
                                    kartaZRuchuDrugiego = "empty";
                                }
                                else
                                {
                                    kartaZRuchuDrugiego = kolumna1.back();
                                }
                                tymczasowyWskaznikDrugi = & kolumna1;
                                break;
                            }
                            case '2':
                            {
                                if(kolumna2.empty())
                                {
                                    kartaZRuchuDrugiego = "empty";
                                }
                                else
                                {
                                    kartaZRuchuDrugiego = kolumna2.back();
                                }
                                tymczasowyWskaznikDrugi = & kolumna2;
                                break;
                            }
                            case '3':
                            {
                                if(kolumna3.empty())
                                {
                                    kartaZRuchuDrugiego = "empty";
                                }
                                else
                                {
                                    kartaZRuchuDrugiego = kolumna3.back();
                                }
                                tymczasowyWskaznikDrugi = & kolumna3;
                                break;
                            }
                            case '4':
                            {
                                if(kolumna4.empty())
                                {
                                    kartaZRuchuDrugiego = "empty";
                                }
                                else
                                {
                                    kartaZRuchuDrugiego = kolumna4.back();
                                }
                                tymczasowyWskaznikDrugi = & kolumna4;
                                break;
                            }
                            case '5':
                            {
                                if(kolumna5.empty())
                                {
                                    kartaZRuchuDrugiego = "empty";
                                }
                                else
                                {
                                    kartaZRuchuDrugiego = kolumna5.back();                                    
                                }
                                tymczasowyWskaznikDrugi = & kolumna5;
                                break;
                            }
                            case '6':
                            {
                                if(kolumna6.empty())
                                {
                                    kartaZRuchuDrugiego = "empty";
                                }
                                else
                                {
                                    kartaZRuchuDrugiego = kolumna6.back();
                                }
                                tymczasowyWskaznikDrugi = & kolumna6;
                                break;
                            }
                            case '7':
                            {
                               if(kolumna7.empty())
                                {
                                    kartaZRuchuDrugiego = "empty";
                                }
                                else
                                {
                                    kartaZRuchuDrugiego = kolumna7.back();
                                }
                                tymczasowyWskaznikDrugi = & kolumna7;
                                break;
                            }
                            case '8':   //Stosy końcowe.
                            {
                                std::cout << std::endl << "Wybierz stos koncowy(1 - kier, 2 - karo, 3 - pik, 4 - trefl): ";
                                char wyborStosuKoncowego;
                                std::cin >> wyborStosuKoncowego;
                                if(wyborStosuKoncowego < 49 || wyborStosuKoncowego > 52 || ilePrzeniescKart != 1)
                                {
                                    std::cout << "Wykonano zly ruch!" << std::endl;
                                }
                                else
                                {
                                    if(wyborStosuKoncowego == '1')
                                    {
                                        if(stosKoncowyKier.empty())
                                        {
                                            kartaZRuchuDrugiego = "kiempty";
                                        }
                                        else
                                        {
                                            kartaZRuchuDrugiego = stosKoncowyKier.back();
                                        }
                                        tymczasowyWskaznikDrugi = & stosKoncowyKier;
                                        tymczasowyIndeksOdkrytychKart = 7;
                                    }
                                    else if(wyborStosuKoncowego == '2')
                                    {
                                        if(stosKoncowyKaro.empty())
                                        {
                                            kartaZRuchuDrugiego = "kaempty";
                                        }
                                        else
                                        {
                                            kartaZRuchuDrugiego = stosKoncowyKaro.back();
                                        }
                                        tymczasowyWskaznikDrugi = & stosKoncowyKaro;
                                        tymczasowyIndeksOdkrytychKart = 8;
                                    }
                                    else if(wyborStosuKoncowego == '3')
                                    {
                                        if(stosKoncowyPik.empty())
                                        {
                                            kartaZRuchuDrugiego = "piempty";
                                        }
                                        else
                                        {
                                            kartaZRuchuDrugiego = stosKoncowyPik.back();
                                        }
                                        tymczasowyWskaznikDrugi = & stosKoncowyPik;
                                        tymczasowyIndeksOdkrytychKart = 9;
                                    }
                                    else if(wyborStosuKoncowego == '4')
                                    {
                                        if(stosKoncowyTrefl.empty())
                                        {
                                            kartaZRuchuDrugiego = "trempty";
                                        }
                                        else
                                        {
                                            kartaZRuchuDrugiego = stosKoncowyTrefl.back();
                                        }
                                        tymczasowyWskaznikDrugi = & stosKoncowyTrefl;
                                        tymczasowyIndeksOdkrytychKart = 10;
                                    }
                                }
                                break;
                            }
                            case '9':
                            {
                                if(czyStosRezerwowyPusty == false)
                                {
                                    if(poziomTrudnosci == 1)
                                    {
                                        licznikStosuRezerwowego --;
                                    }
                                    else    //Przekładanie trzech kart w stosie rezerwowym.
                                    {
                                        kopiaLicznikaStosuRezerwowego = licznikStosuRezerwowego;
                                        for(int i = 0; i < 3; i ++)
                                        {
                                            kopiaLicznikaStosuRezerwowego --;
                                            while(stosRezerwowy[kopiaLicznikaStosuRezerwowego] == " " || kopiaLicznikaStosuRezerwowego < 0)
                                            {
                                                kopiaLicznikaStosuRezerwowego --;
                                                if(kopiaLicznikaStosuRezerwowego < 0)
                                                {
                                                    kopiaLicznikaStosuRezerwowego = 23;
                                                }
                                            }
                                        }
                                        licznikStosuRezerwowego = kopiaLicznikaStosuRezerwowego;    //Zmiana licznika.
                                    }
                                    tymczasowyIndeksOdkrytychKart = 11;
                                    czyPoprawnyRuch = true;
                                }
                                break;
                            }
                        }
                    }
                    if(ruchDrugiWybor != '9')
                    {
                        if(ruchDrugiWybor == '8')
                        {
                            czyPoprawnyRuch = SprawdzStosKoncowy(kartaZRuchuPierwszego, kartaZRuchuDrugiego);
                        }
                        else
                        {
                            czyPoprawnyRuch = SprawdzRuch(kartaZRuchuPierwszego, kartaZRuchuDrugiego);  
                        }
                        if(czyPoprawnyRuch == true)
                        {
                            RuchDrugi(numerKolumnyDoPrzeniesienia, ilePrzeniescKart, ileOdkrytychKart, ruchDrugiCyfra - 1, licznikStosuRezerwowego,
                            (* tymczasowyWskaznikJeden), (* tymczasowyWskaznikDrugi));
                        }
                        else
                        {
                            std::cout << "Wykonano zly ruch!" << std::endl;
                        }
                    }
                    //Sprawdzanie czy mozna cofnąć ruch oraz zapisanie potrzebnych danych.
                    if(czyPoprawnyRuch == true && poprawnyRuch == true)
                    {
                        if(licznikCofniec != 3)
                        {
                            indeksOdkrytychKartCofniecia[licznikCofniec] = tymczasowyIndeksOdkrytychKart;
                            numerKolumnyCofniecia[licznikCofniec] = numerKolumnyDoPrzeniesienia;
                            ilePrzeniescCofniecia[licznikCofniec] = ilePrzeniescKart;
                            numerLicznikaRezerwowegoCofniecia[licznikCofniec] = tymczasowyLicznikRezerwowego;
                            kartyStosuRezerwowegoCofniecie[licznikCofniec] = kartaZRuchuPierwszego;
                            wskaznikCofniecie[licznikCofniec] = tymczasowyWskaznikJeden;
                            wskaznikCofniecieDwa[licznikCofniec] = tymczasowyWskaznikDrugi;
                            licznikCofniec ++;
                        }
                        else
                        {
                            for(int i = 0; i < 2; i ++)
                            {
                                numerKolumnyCofniecia[i] = numerKolumnyCofniecia[i + 1];
                                indeksOdkrytychKartCofniecia[i] = indeksOdkrytychKartCofniecia[i + 1];
                                ilePrzeniescCofniecia[i] = ilePrzeniescCofniecia[i + 1];
                                numerLicznikaRezerwowegoCofniecia[i] = numerLicznikaRezerwowegoCofniecia[i + 1];
                                kartyStosuRezerwowegoCofniecie[i] = kartyStosuRezerwowegoCofniecie[i + 1];
                                wskaznikCofniecie[i] = wskaznikCofniecie[i + 1];
                                wskaznikCofniecieDwa[i] = wskaznikCofniecieDwa[i + 1];
                            }
                            numerKolumnyCofniecia[2] = numerKolumnyDoPrzeniesienia;
                            indeksOdkrytychKartCofniecia[2] = tymczasowyIndeksOdkrytychKart;
                            ilePrzeniescCofniecia[2] = ilePrzeniescKart;
                            numerLicznikaRezerwowegoCofniecia[2] = tymczasowyLicznikRezerwowego;
                            kartyStosuRezerwowegoCofniecie[2] = kartaZRuchuPierwszego;
                            wskaznikCofniecie[2] = tymczasowyWskaznikJeden;
                            wskaznikCofniecieDwa[2] = tymczasowyWskaznikDrugi;
                            
                        }
                    }       
                    //Sprawdzanie czy wygrałeś.
                    if(stosKoncowyKier.size() == 13 && stosKoncowyKaro.size() == 13 && stosKoncowyPik.size() == 13 && stosKoncowyTrefl.size() == 13)
                    {
                        wynik = true;
                        zakonczenieGry = true;
                    }
                }
            }
        }
        licznikPelnychRuchow ++;
    }
    if(wynik == true)
    {
        std::cout << std::endl << "GRATULACJE !!!!! JESTES ZWYCIESCA!!! :) Koncowa liczba ruchow: " << licznikPelnychRuchow << std::endl << std::endl;
        std::string nickGracza; //Zmienna przechowująca nazwe gracza która poźniej jest zapisywana w rankingu.
        std::cout << "Podaj swoje imie/pseudonim (bez spacji oraz maksymalnie 15 znakow): ";
        std::cin >> nickGracza;
        while(nickGracza.length() > 15)
        {
            std::cout << "Podaj ponownie: ";
            std::cin >> nickGracza;
        }
        ZapiszDoRankingu(nickGracza, licznikPelnychRuchow);
    }
    else
    {
        std::cout << std::endl << "Przegrales. Ale za to mozesz sprobowac ponownie :)" << std::endl << std::endl;
    }
}