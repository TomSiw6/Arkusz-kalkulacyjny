#include <iostream>
#include <fstream>
#include "pliki.hpp"
using namespace std;
int zapis(arkusz arkusz1)
{
    ofstream plik("arkusz.csv");
    if (plik.good())
    {
        plik << arkusz1.zwrocwiersz() << " " << arkusz1.zwrockolumna() << endl;
        for (int i = 0; i < arkusz1.zwrockolumna(); i++)
        {
            plik << ((arkusz1.czykolumnatekstowa(i)) ? "1" : "0") << "\t";
        }
        plik << endl;
        for (int w = 0; w < arkusz1.zwrocwiersz(); w++)
        {
            for (int k = 0; k < arkusz1.zwrockolumna(); k++)
            {
                plik << arkusz1.zwrocwartosctekstowa(w, k) << " ";
            }
            plik << endl;
        }
        return 0;
    }
    return 1;
}
int odczyt(arkusz *arkusz1)
{
    ifstream plik("arkusz.csv");
    if (plik.good())
    {
        int wiersze, kolumny;
        plik >> wiersze;
        plik >> kolumny;
        if (wiersze < 1 || kolumny < 1)
        {
            return 2;
        }
        bool *tekstowa = new bool[kolumny];
        for (int i = 0; i < kolumny; i++)
        {
            int typ = 0;
            plik >> typ;
            if (typ)
            {
                tekstowa[i] = true;
            }
            else
            {
                tekstowa[i] = false;
            }
        }
        arkusz nowyarkusz(wiersze, kolumny, tekstowa);
        string tekst;
        int temp = 0;
        plik.ignore(10, '\n');
        for (int w = 0; w < wiersze; w++)
        {
            for (int k = 0; k < kolumny; k++)
            {

                plik >> tekst;
                nowyarkusz.edycjawartosc(w, k, tekst);
            }
        }
        *arkusz1 = nowyarkusz;
        return 0;
    }
    return 1;
}