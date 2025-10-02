///@file
#pragma once
#include "tablica.hpp"

/**
 * @brief funkcja otwierajaca menu zarzadzajace dzialaniem programu
 * 
 */
void menu();
/**
 * @brief funkcja pozwalajaca edytowac poszczegolne komorki w arkuszu
 * 
 * @param arkusz1 arkusz
 */
void edycja(arkusz *arkusz1);
/**
 * @brief funkcja tworzaca nowy arkusz
 * 
 * @param arkusz1 stworzy nowy arkusz w miejsce arkusz1
 * 
 * @return int - zwraca kod bledu,0-brak bledu,1-niepoprawny rozmiar tworzonej tablicy
 */
int stworz(arkusz *arkusz1);
/**
 * @brief zmienia liczbe kolumn i wierszy w arkuszu
 * 
 * @param warkusz zmieniony arkusz
 */
void rozszerzarkusz(arkusz*warkusz);
/**
 * @brief wyszukuje najwieksza wartosc w arkuszu
 * 
 * @param tablica arkusz
 * @param kolumny numer kolumny
 * @return int - zwraca najwieksza wartosc
 */
int znajdzmax(arkusz *tablica, int kolumny);
/**
 * @brief wyszukuje najmniejsza wartosc w arkuszu
 * 
 * @param tablica arkusz
 * @param kolumny numer kolumny
 * @return int - zwraca najmniejsza wartosc
 */
int znajdzmin(arkusz *tablica, int kolumny);
/**
 * @brief oblicza srednia wartosci w arkuszu
 * 
 * @param tablica arkusz
 * @param kolumny numer kolumny
 * @return double - zwraca sredna wartosc 
 */
double srednia(arkusz *tablica, int kolumny);
/**
 * @brief sumuje wartosci w arkuszu poprzez kolumny
 * 
 * @param tablica arkusz
 * @param kolumny numer kolumny
 * @return int - zwraca sume wartosci w kolumnach
 */
int sumowaniekolumny(arkusz *tablica, int kolumny);
