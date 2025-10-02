#include <iostream>
#include "menu.hpp"
#include "pliki.hpp"
using namespace std;
void menu()
{
  int liczba;
  arkusz tablica;
  while (stworz(&tablica))
    ;
  cout << "Witaj uzytkowniku!" << endl;
  cout << "Korzystasz z arkusza kalkulacyjnego" << endl;
  do
  {
    cout << "Co chcesz zrobic?" << endl;
    cout << endl;
    cout << "1.Stworz arkusz" << endl;
    cout << "2.Edytuj zawartosc" << endl;
    cout << "3.Wyswietl zawartosc" << endl;
    cout << "4.Zapisz tablice" << endl;
    cout << "5.Wczytaj tablice" << endl;
    cout << "6.Rozszerz arkusz" << endl;
    cout << "7.Funkcje matematyczne" << endl;
    cout << "0.Wylacz program" << endl;
    cin >> liczba;
    system("clear");
    switch (liczba)
    {
    case 1:
      stworz(&tablica);
      break;

    case 2:
      edycja(&tablica);
      break;

    case 3:
      wyswietl(tablica);
      break;

    case 4:
      if (zapis(tablica))
      {
        cout << "Nieprawidlowa nazwa lub brak dostepu do pliku" << endl;
      }
      break;

    case 5:
      switch (odczyt(&tablica))
      {
      case 1:
        cout << "Nieprawidlowa nazwa lub brak dostepu do pliku" << endl;
        break;

      case 2:
        cout << "Nieprawidlowy format pliku lub nieprawidlowe dane" << endl;
        break;

      case 0:
        cout << "Plik wczytany" << endl;
        break;
      }
      break;
    case 6:
    {
      rozszerzarkusz(&tablica);
    }
    break;

    case 7:
    {
      cout << "Ktora kolumne chcesz obliczyc: " << endl;
      int kolumna;
      cin >> kolumna;
      if (tablica.czykolumnatekstowa(kolumna))
      {
        cout << "Jest to kolumna tekstowa, nie mozna wykonac na niej obliczen" << endl;
      }
      else
      {
        cout << "Wartosc maksymalna: " << znajdzmax(&tablica, kolumna) << endl;
        cout << "Wartosc minimalna: " << znajdzmin(&tablica, kolumna) << endl;
        cout << "Wartosc srednia: " << srednia(&tablica, kolumna) << endl;
        cout << "Suma kolumn wynosi: " << sumowaniekolumny(&tablica, kolumna) << endl;
      }
      break;
    }
    }
  } while (liczba != 0);
  cout << "Do widzenia!" << endl;
}

int stworz(arkusz *arkusz1)
{
  int wiersz;
  int kolumna;
  cout << "Jaki ma byc rozmiar arkusza?" << endl;
  cout << "Liczba kolumn: ";
  cin >> kolumna;
  cout << "Liczba wierszy ";
  cin >> wiersz;
  cout << "Wprowadz 1 dla tekstowej" << endl;
  bool *typ = new bool[kolumna];
  for (int i = 0; i < kolumna; i++)
  {
    cout << "Jakiego typu ma byc kolumna?" << endl;
    cout << "Kolumna " << i << endl;
    int pomocnicza = 0;
    cin >> pomocnicza;
    if (pomocnicza == 1)
    {
      typ[i] = true;
    }
    else
    {
      typ[i] = false;
    }
  }
  arkusz nowyarkusz(wiersz, kolumna, typ);
  *arkusz1 = nowyarkusz;
  system("clear");
  cout << "Twoj arkusz ma rozmiar " << wiersz << "X" << kolumna << endl;
  cout << "Uzupelnij arkusz" << endl;
  int temp = 0;
  string tekst = "";
  for (int w = 0; w < wiersz; w++)
  {
    for (int k = 0; k < kolumna; k++)
    {
      cout << "Komorka " << k << "," << w << " = ";

      cin >> tekst;
      arkusz1->edycjawartosc(w, k, tekst);
    }
  }
  return 0;
}

void edycja(arkusz *arkusz1)
{
  int w;
  int k;
  int wartosc;
  string tekst;
  cout << "Wybierz wiersz: ";
  cin >> w;
  cout << "Wybierz komokre: ";
  cin >> k;
  cout << "Wybierz wartosc: ";
  cin >> tekst;
  if (arkusz1->edycjawartosc(w, k, tekst))
  {
    cout << "Niepoprawna wybrana wartosc" << endl;
  }
}

void rozszerzarkusz(arkusz *warkusz)
{
  int w;
  int k;
  bool czytekst;
  cout << "Podaj ilosc wierszy: ";
  cin >> w;
  cout << "Podaj ilosc kolumn: ";
  cin >> k;

  cout << "Wprowadz 1 dla tekstowej" << endl;
  int pomocnicza = 0;
  cin >> pomocnicza;
  if (pomocnicza == 1)
  {
    czytekst = true;
  }
  else
  {
    czytekst = false;
  }
  if (warkusz->rozszerz(k, w, czytekst))
  {
    cout << "Nieprawidlowy rozmiar arkusza \n";
  }
}

int znajdzmax(arkusz *tablica, int kolumny)
{
  int max = tablica->zwrocwartosc(0, kolumny);
  for (int i = 1; i < tablica->zwrocwiersz(); i++)
  {
    if (max < tablica->zwrocwartosc(i, kolumny))
    {
      max = tablica->zwrocwartosc(i, kolumny);
    }
  }
  return max;
}

int znajdzmin(arkusz *tablica, int kolumny)
{
  int min = tablica->zwrocwartosc(0, kolumny);

  for (int i = 1; i < tablica->zwrocwiersz(); i++)
  {
    if (min > tablica->zwrocwartosc(i, kolumny))
    {
      min = tablica->zwrocwartosc(i, kolumny);
    }
  }

  return min;
}

double srednia(arkusz *tablica, int kolumny)
{
  double x = static_cast<double>(sumowaniekolumny(tablica, kolumny)) / tablica->zwrocwiersz();
  return x;
}

int sumowaniekolumny(arkusz *tablica, int kolumny)
{
  int suma = 0;
  for (int i = 0; i < tablica->zwrockolumna(); i++)
  {
    suma += tablica->zwrocwartosc(i, kolumny);
  }
  return suma;
}