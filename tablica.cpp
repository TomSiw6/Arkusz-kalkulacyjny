#include <iostream>
#include "tablica.hpp"
using namespace std;

int arkusz::edycjawartosc(int w, int k, std::string wartosc)
{
  if (wiersz < w || kolumna < k)
  {
    return 1;
  }
  else if (w < 0 || k < 0)
  {
    return 1;
  }
  else
  {
    tablica[w][k]->ustawwartosc(wartosc);
  }
  return 0;
}

int arkusz::tworzarkusz(int w, int k)
{
  if (w < 1 || k < 1)
  {
    return 1;
  }
  wiersz = w;
  kolumna = k;
  tablica = new komorka **[w];
  for (int i = 0; i < w; i++)
  {
    tablica[i] = new komorka *[k];
    for (int j = 0; j < k; j++)
    {
      if (czytekstowa[j])
      {
        tablica[i][j] = new komorkatekstowa();
      }
      else
      {
        tablica[i][j] = new komorkaliczbowa();
      }
    }
  }
  return 0;
}

std::string arkusz::zwrocwartosctekstowa(int w, int k)
{
  if (w < 0 || k < 0)
  {
    return 0;
  }
  else if (w >= wiersz || k >= kolumna)
  {
    return 0;
  }
  else
  {
    return tablica[w][k]->zwrocwartosctekstowa();
  }
}

int arkusz::zwrocwiersz()
{
  return wiersz;
}
int arkusz::zwrockolumna()
{
  return kolumna;
}

arkusz::arkusz(int wiersze, int kolumny, bool *tekstowa)
{
  czytekstowa = tekstowa;
  tworzarkusz(wiersze, kolumny);
}

void komorkaliczbowa::ustawwartosc(std::string wartosc)
{
  try
  {
    this->wartosc = std::stoi(wartosc);
  }
  catch (...)
  {
  }
}
string komorkaliczbowa::zwrocwartosctekstowa()
{
  return std::to_string(wartosc);
}

bool arkusz::czykolumnatekstowa(int k)
{
  return czytekstowa[k];
}

void komorkatekstowa::ustawwartosc(std::string wartosc)
{
  this->wartosc = wartosc;
}
string komorkatekstowa::zwrocwartosctekstowa()
{
  return wartosc;
}

int arkusz::zwrocwartosc(int w, int k)
{
 int x=0;
 try
 {
   x = stoi(tablica[w][k]->zwrocwartosctekstowa());
 }
 catch(const std::exception& e)
 {
   
 }
 return x;
}

int arkusz::rozszerz(int x, int y, bool v)
{
  if (x < 1 || y < 1)
  {
    return 1;
  }
  komorka ***nowaTablica;
  bool *noweTypy = new bool[x];
  for (int i = 0; i < x; i++)
  {
    if (wiersz > i)
    {
      noweTypy[i] = czytekstowa[i];
    }
    else
    {
      noweTypy[i] = v;
    }
  }
  nowaTablica = new komorka **[y];
  for (size_t wys = 0; wys < y; wys++)
  {
    nowaTablica[wys] = new komorka *[x];
    for (size_t szer = 0; szer < x; szer++)
    {
      if (noweTypy[szer])
      {
        nowaTablica[wys][szer] = new komorkatekstowa();
      }
      else
      {
        nowaTablica[wys][szer] = new komorkaliczbowa();
      }
      if (wys < wiersz && szer < kolumna)
      {
        nowaTablica[wys][szer]->ustawwartosc(tablica[wys][szer]->zwrocwartosctekstowa());
        delete tablica[wys][szer];
      }
    }
  }

  delete[] czytekstowa;
  delete[](tablica);
  wiersz = y;
  kolumna = x;
  tablica = nowaTablica;
  czytekstowa = noweTypy;
  return 0;
}