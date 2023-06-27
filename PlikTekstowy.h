#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {
private:
    const string NAZWA_PLIKU;

protected:
    bool czyPlikJestPusty(fstream &plikTekstowy);
    string pobierzNazwePliku();

public:
    PlikTekstowy (string nazwaPliku)
        :NAZWA_PLIKU(nazwaPliku) {
    };
};

#endif
