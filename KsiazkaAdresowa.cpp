#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenadzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    idZalogowanegoUzytkownika = uzytkownikMenadzer.logowanieUzytkownika();
    adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
    idZalogowanegoUzytkownika = 0;
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatMenadzer.dodajAdresata(idZalogowanegoUzytkownika);
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow() {
    adresatMenadzer.wypiszWszystkichAdresatow();
}
