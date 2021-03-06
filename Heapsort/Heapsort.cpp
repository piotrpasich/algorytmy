/**
Napisz algorytm sortowania przez kopcowanie. Czym różni się od sortowania szybkiego i dlaczego warto go stosować? 

Sorted array is 
1 2 2 3 5 8 15 92 101 
**/
#include <iostream> 
  
using namespace std; 
  
class HeapSort {
  private: 
    void heapify (int arr[], int n, int i) { 
      int largest = i; 
      int l = 2*i + 1; 
      int r = 2*i + 2; 

      if (l < n && arr[l] > arr[largest]) { 
        largest = l; 
      }

      if (r < n && arr[r] > arr[largest]) {
        largest = r; 
      }

      if (largest != i) { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
      } 
    } 
  public: 
    void heapSort(int arr[], int n) { 
      for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); 
      }

      for (int i=n-1; i>=0; i--) { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
      } 
    } 
      
    void printArray(int arr[], int n) 
    { 
        for (int i=0; i<n; ++i) {
          cout << arr[i] << " "; 
        }
        cout << "\n"; 
    } 
};

  
int main() 
{ 
  int arr[] = {2, 8, 92, 1, 3, 5, 15, 101, 2}; 
  int n = sizeof(arr)/sizeof(arr[0]); 

  class HeapSort heapSort;
  heapSort.heapSort(arr, n); 

  cout << "Sorted array is \n"; 
  heapSort.printArray(arr, n); 
}
