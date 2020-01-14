/**
K01: Do i przypisz 1
K02: Do ai przypisz 9
K03: Do suma przypisz 9
K04: Zwiększ ai o 2
K05: Zwiększ suma o ai
K06: Zinkrementuj i
K07: Jeżeli i jest różne od 6 to skocz do K04 w przeciwnym wypadku skocz do K08
K08: Wypisz suma
K09: Zakończ działanie
**/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main () {
  int i = 1;
  int ai = 9; 
  int suma = 9;
  while (i != 6) {
    ai += 2;
    suma += ai;
    i++;
  }
  cout << endl << suma << endl;
}
