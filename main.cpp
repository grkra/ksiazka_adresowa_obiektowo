#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //ksiazkaAdresowa.rejestracjaUzytkownika();

    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    cout << "logowanie uzytkownika" << endl;
    ksiazkaAdresowa.logowanieUzytkownika();
    cout << "ID zalogowanego uzytkownika " << ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() << endl;

    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanego);

    ksiazkaAdresowa.dodajAdresata();

    //ksiazkaAdresowa.wylogowanieUzytkownika();

    return 0;
}
