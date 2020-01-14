/**
K01: Definicja funkcji fib(n:całkowita): całkowita
K02: Jeżeli (n=1) lub (n=0) to fib:=n w przeciwnym wypadku fib:=fib(n-1)+fib(n-2);
K03: Koniec definicji funkcji fib
K04: Wypisz (wartość funkcji fib(6))
K05: Koniec
**/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int fib(int n) {
  if (n==1 || n==0) {
    return n;
  }
  return fib(n-1) + fib(n-2);
}

int main () {
  cout << endl << fib(6) << endl;
}
