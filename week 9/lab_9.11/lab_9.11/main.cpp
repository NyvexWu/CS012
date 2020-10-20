#include <iostream>

using namespace std;

#include "minFunc.h"
const int MAX_SIZE = 10000;
int main() {
    int arrSize;
    int arr[MAX_SIZE];
   cin >> arrSize;
   if (arrSize > 0) {
      arr[arrSize];
      for (int i = 0; i < arrSize; ++i) {
         cin >> arr[i];
      }
      const int *minLoc = min(arr, arrSize);
      cout << *minLoc << endl;
   }   
   return 0;
}

