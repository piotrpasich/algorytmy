/**

Zmienne: x, n, i: całkowite

K01: x:=107;
K02: i:=0;
K03: dopóki (i<9) wykonuj
K04: x:=x-3 mod 2;
K05: i:=i+1 div 1;
K06: koniec pętli
K07: pisz (x)
K08: koniec.
**/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main () {
  int x = 107; 
  int i = 0; 
  while (i<9) {
    x = x - 3 % 2;
    i = i + 1 / 1;
  }
  
  cout << endl << x << endl;
}
