#include<iostream>
#include "tablica.hpp"
using namespace std;
void wyswietl(arkusz arkusz1 )
{
for (int w=0; w<arkusz1.zwrocwiersz(); w++)
  { 
   for( int k=0; k<arkusz1.zwrockolumna(); k++)
    {
     cout<<"Komorka "<<k<<","<<w<<" = "<<arkusz1.zwrocwartosctekstowa(w,k);
     cout<<"\t";
    }
    cout<<"\n";
  }
}
