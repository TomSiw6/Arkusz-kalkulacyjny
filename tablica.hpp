///@file
#pragma once
#include <string>
/**
 * @brief klasa interfejsowa komorka
 * 
 */
class komorka
{
public:
    /**
 * @brief ustawia wartosc komorki
 * 
 * @param wartosc nowa wartosc ktora komorka powinna przyjac
 */
    virtual void ustawwartosc(std::string wartosc) = 0;
    /**
     * @brief zwraca zawartosc tekstowa danej komorki
     * 
     * @return std::string - zwraca zawartosc tekstowa danej komorki
     */
    virtual std::string zwrocwartosctekstowa() = 0;
};
/**
 * @brief komokra okreslajaca wartosc liczbowa
 * 
 */
class komorkaliczbowa : public komorka
{
    int wartosc = 0;

public:
    /**
 * @brief ustawia wartosc komorki
 * 
 * @param wartosc nowa wartosc ktora komorka powinna przyjac
 */
    void ustawwartosc(std::string wartosc);
    /**
     * @brief zwraca wartosc tekstowa danej komorki
     * 
     * @return std::string - zwraca wartosc tekstowa danej komorki
     */
    std::string zwrocwartosctekstowa();
};
/**
 * @brief komokra okreslajaca wartosc tekstowa
 * 
 */
class komorkatekstowa : public komorka
{
    std::string wartosc = ".";

public:
    /**
 * @brief ustawia wartosc komorki
 * 
 * @param wartosc nowa wartosc ktora komorka powinna przyjac
 */
    void ustawwartosc(std::string wartosc);
    /**
     * @brief zwraca wartosc tekstowa danej komorki
     * 
     * @return std::string - zwraca wartosc tekstowa danej komorki
     */
    std::string zwrocwartosctekstowa();
};
/**
 * @brief klasa opisujaca arkusz
 * Klasa sluzy do przechowywania komorek w tablicy dwuwymiarowej
 */
class arkusz
{
    int wiersz;
    int kolumna;
    komorka ***tablica;
    bool *czytekstowa;

public:
    /**
   * @brief tworzy arkusz
   * 
   * @param w ilosc wierszy
   * @param k ilosc kolumn
   * @return int - zwraca kod bledu 0-wszystko przebieglo poprawnie 1-wystepuje blad
   */
    int tworzarkusz(int w, int k);
    arkusz()
    {
    }
    arkusz(int wiersze, int kolumny, bool *tekstowa);
    /**
     * @brief zwraca wartosc liczbowa danej komorki
     * 
     * @param w numer wiersza
     * @param k numer kolumny
     * @return int - zwraca wartosc liczbowa danej komorki
     */
    int zwrocwartosc(int w, int k);
    /**
     * @brief pozwala zedytowac wartosc we wskazanej komorce
     * 
     * @param w numer wiersza
     * @param k numer kolumny
     * @param wartosc wartosc w komorce
     * @return int - zwraca zedytowana wartosc
     */
    int edycjawartosc(int w, int k, std::string wartosc);
    /**
     * @brief zwraca wartosc tekstowa danej komorki
     * 
     * @param w ilosc wierszy
     * @param k ilosc kolumn
     * @return std::string - zwraca wartosc tekstowa danej komorki
     */
    std::string zwrocwartosctekstowa(int w, int k);
    /**
     * @brief zwraca ilosc wierszy
     * 
     * @return int - zwraca ilosc wierszy
     */
    int zwrocwiersz();
    /**
     * @brief zwraca ilosc kolumn
     * 
     * @return int - zwraca ilosc kolumn
     */
    int zwrockolumna();
    /**
     * @brief sprwadza czy kolumna jest tekstowa
     * 
     * @param k numer kolumny
     * @return true - kolumna jest tekstowa
     * @return false - kolumna jest liczbowa
     */
    bool czykolumnatekstowa(int k);
    /**
     * @brief zmienia ilosc kolumn i wierszy
     * 
     * @param x nowa ilosc kolumn
     * @param y nowa ilosc wierszy
     * @param v typ kolumn
     * @return int - zwraca kod bledu
     */
    int rozszerz(int x, int y, bool v);
};
/**
 * @brief wyswietla arkusz
 * 
 * @param arkusz1 wyswietlany arkusz
 */
void wyswietl(arkusz arkusz1);