Uruchomienie gry:

- Należy uruchomić plik gra.exe za pomąca kompilatora c++ (najlepiej MinGW obsługującego jak najwyższą wersję języka c++).
- Po podpięciu kompilatora można w powershellu wejść w katalog z grą i wpisać "./gra" co spowoduje uruchomienie się gry.
- Do najlepszego działania gry zalecane jest włączenie pełnego ekranu.

Instrukcja rozgryzwki i poruszania się po programie:

- Zasady dotyczące przekładania, symboli, wartości i przetasowywania kart są takie same jak dla zwykłej gry w pasjansa.
- Po uruchomieniu pliku gra.exe pojawi się menu z 4 opcjami do wyboru.
- Opcja pierwsza uruchamia grę, druga pozwala zmienić ustawienia, trzecia wyświetla ranking a czwarta zamyka program.
- Każde wpisanie znaku/znaków na klawiaturze należy zatwierdzić klawiszem enter.
a)Rozgrywka:
- Po wybraniu opcji 1 z menu i zatwierdzeniu jej enterem, pojawi się opcja wybrania poziomu trudności. 
Trzeba postąpić tutaj tak samo jak w przypadku opcji z menu.
- Po wybraniu poziomu trudności pokażą się wszystkie kolumny, stosy końcowe i stos rezerwowy wraz z odsłoniętymi kartami.
- Każdy ruch składa się z dwóch wyborów: 
    1. Wybór kolumny/stosu rezerwowego z której/którego chce się przenieść karty/kartę.
    UWAGA - gdy wybierze się kolumne i jest na niej więcej niż jedna odsłonięta karta, należy również podać ile kart chce się przenieść 
    (nie dotyczy to stosu rezerwowego na trudnym poziomie trudności - patrz kolejny punkt oznaczony "UWAGA").
    UWAGA - gdy gra się na trudnym poziomie trudności i chce się przełożyć kartę ze stosu rezerwowego, można użyć tylko tej najbardziej na lewo w stosie.
    2. Wybór kolumny/stosu końcowego na który chce się przenieść karty (lub w przypadku wybrania stosu rezerwowego w wyborze pierwszym oraz cyferki 9 w 
    wyborze drugim, sprawdza się kolejną/kolejne kartę/karty w stosie rezerwowym).
    UWAGA - w przypadku wybrania cyferki 8 (stosy koncowe), trzeba wybrać numer stosu koncowego (zostanie wyświetlone który numer odpowiada któremu stosowi).
    UWAGA - w przypadku niepoprawnego ruchu, nic złego się nie stanie (poza zwiększeniem licznika ruchów o jeden),
    zostanie tylko wyświetlony napis o złym ruchu a grę będzie można kontynuować dalej.
    Numery stosów końcowych oraz kolumn będą pokazane w trakcie gry na samym dole ekranu podczas wykonania odpowiedniego ruchu.
- Każdy poprawnie wykonany ruch można cofnąć wpisując znak odpowiadający cofaniu (domyślnie 'c').
Można cofnąć maksymalnie 3 ostatnie ruchy.
- Rozgrywkę można odrazu zakończyć porażką poprzez wpisanie odpowiedniego znaku (domyślnie 'x').
- Wielkość literki ma znaczenie w przypadku gdy chce się cofnąć ruch lub zakończyć grę.
- W razie niezrozumienia, opis jaki znak można wybrać w danym ruchu zawsze będzie na dole ekranu.
- Gdy wygramy, pojawi się komunikat o tym żeby wpisać swoją nazwę gracza. (w przypadku wpisania nicku ze spacją, wszyzstko po spacji będzie usunięte).
Nasza nazwa gracza oraz ilość ruchów trafia na ranking.
b)Ustawienia:
- Można tutaj zmienić:
    1. Maksymalną ilość ruchów (domyślnie 2147483647).
    2. Kolory kart (domyślnie czewony dla kier i karo, biały dla pik i trefl).
    3. Znaki od cofania ruchu i zakończenia gry (domyślnie 'c' dla cofania ruchu i 'x' dla zakończenia rozgrywki).
- Po wybraniu danej opcji w ustawieniach, pojawi się menu gdzie trzeba poprawnie według wyświetlonej instrukcji wprowadzić zmiany.
c)Ranking:
- Wyświetlane są tu statystyki od najmniejszej do największej ilości ruchów (im mniej ruchów tym lepsza pozycja).
- Po każdej wygranej i poprawnym podaniu nazwy gracza, nazwa oraz ilość ruchów trafiają do rankingu.
UWAGA - aby sprawiedliwie był wyświetlany ranking, należy nic niezmieniać w pliku "ranking.txt".

Opis każdej funckji znajduje się w plikach z funkcjami (nie licząc plika nagłówkowego "header.hpp" w którym są same informacje o istnieniu fukncji i ich parametrach).
Życzę miłej i przyjemnej (niemęczącej) rozgrywki :).