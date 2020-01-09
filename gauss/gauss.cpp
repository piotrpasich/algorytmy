/**
Kod znajduje się pod adresem https://github.com/piotrpasich/algorytmy/tree/master/gauss

Metoda Gaussa-Crouta
Mając do dyspozycji algorytm z wykładu obliczania niewiadomych metodą Gaussa-Crouta napisz samodzielnie na jego podstawie kod programu w języku Basic, Pascal, C++ lub Java (do wyboru). Nie wolno korzystać z żadneych gotowych bibliotek numerycznych.

Przetestuj jego działanie, a następnie załaduj kod na platformę.
**/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double eps = 1e-12;

bool gauss (int n, double ** AB, double * X, int * W) {
  int    i, j, k;
  double m, s;

  for(i=0; i<=n; i++) {
    W [i] = i;
  }
 
  for(i=0; i<n-1; i++) {
    k = i;
    for(j=i+1; j<n; j++) {
      if(fabs(AB[i][W[k]]) < fabs(AB[i][W[j]])) {
        k = j;
      }
    }
    swap (W[k], W[i]);
    for(j=i+1; j<n; j++) {
      if( fabs ( AB [ i ][ W [ i ] ] ) < eps ) return false;
      m = -AB [ j ][ W [ i ] ] / AB [ i ][ W [ i ] ];
      for(k=i+1; k<=n; k++) {
        AB [j][W[k]] += m * AB[i][W[k]];
      }
    }
  }

  for(i=n-1; i>=0; i--) {
    if(fabs(AB[i][W[i]]) < eps ) {
      return false;
    }
    s = AB [i][n];
    for(j=n-1; j>=i+1; j--) {
      s -= AB[i][W[j]] * X[W[j]];
    }
    X[W[i]] = s/AB[i][W[i]];
  }
  
  return true;
}

// Program główny

int main( )
{
  double **AB, *X;
  int n, i, j, *W;

  cout << setprecision ( 4 ) << fixed;

  cout << "Podaj liczbę niewiadomych: ";
  cin >> n;

  AB = new double * [n];
  X  = new double [n];
  W  = new int [n+1];

  for(i=0; i<n; i++) {
    AB[i] = new double [ n + 1 ];
  }


  for(i=0; i<n; i++) {
    for(j=0; j<=n; j++) {
      if (j==n) {
        cout << "Podaj niewiadomą y dla równania " << i + 1 << ":";
      } else {
        cout << "Podaj niewiadomą x^" << j + 1 << " dla równania " << i + 1 << ":";
      }
      cin >> AB [i][j];
    }
  }

  if(gauss(n,AB,X,W)) {
    for(i=0;i<n;i++) {
      cout << "x" << i + 1 << " = " << setw (9) << X[i] << endl;
    }
  } else {
    cout << "Nie można dzielić przez 0\n";
  }

  return 0;
} 
