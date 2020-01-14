/**
Zmienne:
p,x: całkowite;
T: tablica [1..30] liczb całkowitych;

K01: x :=68;
K02: p:=0;
K03: powtarzaj
K04: p:=p+1;
K05: T[p]:=x mod 2;
K06: x:=x div 2;
K07: dopóki x<>0;
K08: dla i:=p do 1 pisz(tablica[i]);
K09: koniec.

**/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


int main () {
  int T[68];
  int x = 68;
  int p = 0 ;
  do {
    p = p + 1;
    T[p] = x%2;
    x = x / 2;
  } while (x!=0);
  for (int i = p ; i > 0; i--) {
    cout << T[i] << endl;  
  }
  
  return 1; 
}
