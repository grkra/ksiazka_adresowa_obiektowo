#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");

    char wyborOpcji;

    while (true) {
        if (!ksiazkaAdresowa.czyUzytkownikJestZalogowany()) {
            wyborOpcji = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wyborOpcji) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit (0);
                break;
            default:
                cout << "Nie ma takiej opcji w menu" << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wyborOpcji = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wyborOpcji)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                cout << "OPCJA 2" << endl;
                break;
            case '3':
                cout << "OPCJA 3" << endl;
                break;
            case '4':
                ksiazkaAdresowa.wypiszWszystkichAdresatow();
                break;
            case '5':
                cout << "OPCJA 5" << endl;
                break;
            case '6':
                cout << "OPCJA 6" << endl;
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }

    return 0;
}
