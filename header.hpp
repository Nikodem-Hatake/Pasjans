#include <vector>

void Menu();
void Gra(int kolorKierKaro, int kolorPikTrefl, int maxIloscRuchow, char znakZakonczeniaRozgrywki, char znakCofnieciaRuchu);
void Ranking();
void ZapiszDoRankingu(std::string nazwaGracza, int iloscRuchow);
void Ustawienia(int & iloscRuch, int & kolorKierKaro, int & kolorPikTrefl, char & znakKoniec, char & znakCofniecia);

void RuchPierwszy(bool & poprawnoscRuchu, int & ileDoPrzeniesienia, std::string & kartaRuchJeden, int ileOdkrytych, std::vector <std::string> kolumna);
void RuchDrugi(int numerKolumnyPrzeniesienia, int ilePrzeniesc, int iloscOdkrytychKart[],
int indeksOdkrytychKart, int & licznikRezerwowego, std::vector <std::string> & kolumnaJeden, std::vector <std::string> & kolumnaDwa);
void CofnijRuch(int numerKolumnyPrzeniesienia, int ilePrzeniesc, int iloscOdkrytychKart[], int indeksOdkrytychKart, int numerLicznikaCofniecie, 
int & licznikStosu, std::string kartaStosuRezerwowego, std::vector <std::string> & kolumnaJeden, std::vector <std::string> & kolumnaDwa);

void Wypisywanie(std::vector <std::string> kolumna, int & odkryte, int numerKolumny, int kolorKierOrazKaro, int kolorPikOrazTrefl);
void WypisywanieStosu(std::vector <std::string> stos, std::string nazwaStosu, int kolorKierOrazKaro, int kolorPikOrazTrefl);
void WypisywanieRezerwowy(std::vector <std::string> rezerwowy, int & licznik, bool czyPusty, int kolorKierOrazKaro, 
int kolorPikOrazTrefl, int poziom);
void WypiszZKolorem(int kolorKierKaro, int kolorPikTrefl, std::string karta);

bool SprawdzRuch(std::string kartaRuch, std::string kartaRuchDwa);
bool SprawdzStosKoncowy(std::string kartaRuchJeden, std::string kartaRuchDwa);