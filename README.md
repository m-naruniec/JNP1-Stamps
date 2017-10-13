# JNP1-Stamps
Programming languages and tools assignment #1

**Task description in Polish**

=== Zadanie znaczki pocztowe ===

Pomóż filateliście stworzyć program wspomagający jego hobby.
Filatelista ma plik tekstowy zawierający listę znaczków. Każdy wiersz
tego pliku opisuje jeden znaczek w formacie: nazwa znaczka, wartość
znaczka, rok wydania znaczka, nazwa kraju lub poczty wydającej
znaczek. Poszczególne pola są rozdzielone odstępami, które mogą
pojawić się też na początku lub na końcu wiersza. Nazwa znaczka
i nazwa kraju lub poczty wydającej znaczek również mogą zawierać
odstępy. Program czyta ze standardowego wejścia plik z listą znaczków,
a następnie zapytania. Każde zapytanie jest w osobnym wierszu
i zawiera dwie liczby rozdzielone odstępem, oznaczające przedział lat.
Na początku lub na końcu wiersza też może pojawić się odstęp. Dla
każdego zapytania program wypisuje posortowaną informację o znaczkach
wydanych w podanym przedziale lat, w formacie: rok wydania znaczka,
nazwa kraju lub poczty wydającej znaczek, wartość znaczka, nazwa
znaczka. Informacja o każdym znaczku jest wypisywana w osobnym
wierszu, bez odstępów na początku i końcu wiersza, a wszystkie
odstępy wewnątrz wiersza są zamieniane na pojedynczą spację.

Program musi być odporny na niezgodność formatu danych wejściowych ze
specyfikacją. Dla każdego niezgodnego ze specyfikacją wiersza, który
pojawia się na standardowym wejściu, program wypisuje na standardowe
wyjście błędów komunikat w formacie:

Error in line N:WIERSZ

gdzie N jest numerem błędnego wiersza (wiersze są numerowane od 1),
a WIERSZ to błędny wiersz w oryginalnej postaci (z dokładnym
zachowaniem wszystkich odstępów), w jakiej został wczytany przez
program.

Przykładowo, dla danych wejściowych:

Franklin Z-Grill ONE CENT 930000 1867 U.S.POSTAGE
znaczek   polski
One Cent Black on Magenta ONE CENT  935000 1856  British Guiana
One Penny 1072260 1847 Mauritius
 Two Pence 1148850 1847 Mauritius
Inverted Jenny 24 CENTS 977500 1918 U.S.POSTAGE
Three-Skilling Yellow 2300000 1855 SVERIGE
Pomidor 1 1971 Poczta Polska
Brzoza 1,50 1971 Poczta Polska
Buk 0,50 1971 Poczta Polska
Dynia 1 1971 Poczta Polska
queen's slipper 3.00 1999 Kanada
1855 1856
1847 1847
Trawa 2 1971 Poczta Polska
1970 1972
2000 1999

program wypisuje na standardowym wyjściu:

1855 SVERIGE 2300000 Three-Skilling Yellow
1856 British Guiana 935000 One Cent Black on Magenta ONE CENT
1847 Mauritius 1072260 One Penny
1847 Mauritius 1148850 Two Pence
1971 Poczta Polska 0,50 Buk
1971 Poczta Polska 1 Dynia
1971 Poczta Polska 1 Pomidor
1971 Poczta Polska 1,50 Brzoza

a na standardowym wyjściu błędów:

Error in line 2:znaczek   polski
Error in line 15:Trawa 2 1971 Poczta Polska
Error in line 17:2000 1999

Oczekiwane rozwiązanie nie powinno zawierać definicji własnych
struktur i klas. Zamiast tego należy intensywnie korzystać
z kontenerów i algorytmów dostarczanych przez standardową bibliotekę
języka C++. W szczególności do sortowania i wyszukiwania należy użyć
efektywnych algorytmów. Zapytań o przedziały lat może być dużo.
Rozwiązanie należy umieścić w pliku znaczki.cc, który należy umieścić
w repozytorium w katalogu

grupaN/zadanie1/ab123456+cd123456

lub

grupaN/zadanie1/ab123456+cd123456+ef123456

gdzie N jest numerem grupy, a ab123456, cd123456, ef123456 są
identyfikatorami członków zespołu umieszczającego to rozwiązanie.
Katalog z rozwiązaniem nie powinien zawierać innych plików, ale może
zawierać podkatalog private, gdzie można umieszczać różne pliki, np.
swoje testy. Pliki umieszczone w tym podkatalogu nie będą oceniane.
