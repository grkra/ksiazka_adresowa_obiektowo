#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

//        if (czyPlikJestPusty(plikTekstowy) == true) {
//            plikTekstowy << liniaZDanymiAdresata;
//        } else {
//            plikTekstowy << endl << liniaZDanymiAdresata ;
//        }
        //TERNARY OPERATOR:
        czyPlikJestPusty(plikTekstowy) ? plikTekstowy << liniaZDanymiAdresata : plikTekstowy << endl << liniaZDanymiAdresata;

        idOstatniegoAdresata ++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

void PlikZAdresatami::usunAdresataZPliku (int idAdresata) {
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoSkopiwanegoAdresataWPlikuOddzielonePionowymiKreskami = "";
    fstream plikTekstowy, tymczasowyPlikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true && tymczasowyPlikTekstowy.good() == true && idAdresata != 0) {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                continue;
            } else if (czyPlikJestPusty(tymczasowyPlikTekstowy) == true) {
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                daneOstaniegoSkopiwanegoAdresataWPlikuOddzielonePionowymiKreskami = daneJednegoAdresataOddzielonePionowymiKreskami;
            } else {
                tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
                daneOstaniegoSkopiwanegoAdresataWPlikuOddzielonePionowymiKreskami = daneJednegoAdresataOddzielonePionowymiKreskami;
            }
        }
        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        MetodyPomocnicze::usunPlik(pobierzNazwePliku());
        MetodyPomocnicze::zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU, pobierzNazwePliku());
    }

    zaktualizujIdOstatniegoAdresataPoUsunieciuWybranegoAdresata (idAdresata, daneOstaniegoSkopiwanegoAdresataWPlikuOddzielonePionowymiKreskami);
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat){
    string liniaZDanymiEdytowanegoAdresataOddzielonymiPionowymiKreskami = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    int idEdytowanegoAdresata = adresat.pobierzId();

    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy, tymczasowyPlikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true && tymczasowyPlikTekstowy.good() == true && idEdytowanegoAdresata != 0){
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(czyPlikJestPusty(tymczasowyPlikTekstowy) == true){
                if(idEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)){
                    tymczasowyPlikTekstowy << liniaZDanymiEdytowanegoAdresataOddzielonymiPionowymiKreskami;
                }
                else {tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;}
            }
            else{
                if(idEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)){
                    tymczasowyPlikTekstowy << endl << liniaZDanymiEdytowanegoAdresataOddzielonymiPionowymiKreskami;
                }
                else {tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;}
            }
        }
        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();
        MetodyPomocnicze::usunPlik(pobierzNazwePliku());
        MetodyPomocnicze::zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU, pobierzNazwePliku());
    }
    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void PlikZAdresatami::zaktualizujIdOstatniegoAdresataPoUsunieciuWybranegoAdresata (int idUsunietegoAdresata, string daneOstaniegoSkopiwanegoAdresataWPlikuOddzielonePionowymiKreskami) {
    if (idUsunietegoAdresata == idOstatniegoAdresata) {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoSkopiwanegoAdresataWPlikuOddzielonePionowymiKreskami);
    }
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    vector <Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();

        if (daneOstaniegoAdresataWPliku != "") {
            idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        }
    }
    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata () {
    return idOstatniegoAdresata;
}
