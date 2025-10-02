 aplikacja.out : main.o menu.o tablica.o tablica_wysw.o pliki.o
	g++ -g -o $@ $^
 main.o : main.cpp
	g++ -c -g -o $@ $^
 menu.o : menu.cpp
	g++ -c -g -o $@ $^
 tablica.o : tablica.cpp
	g++ -c -g -o $@ $^
 tablica_wysw.o : tablica_wysw.cpp
	g++ -c -g -o $@ $^
 pliki.o : pliki.cpp
	g++ -c -g -o $@ $^