
#include <bits/stdc++.h>
using namespace std;
int main() {
  // array 2d
  int angka[] = {
      1,
      6,
      5,
  };
  int n = sizeof(angka) / sizeof(angka[0]);
  sort(angka, angka + n);
  for (int i = 0; i < n; i++) {
    cout << angka[i] << " ";
  }
  cout << "\n\n";

  // array 3d
  int matriks[3][4] = {{1, 2, 3, 4}, {1, 2, 3}, {1, 2, 3}};
  n = sizeof(matriks) / sizeof(matriks[0]);
  for (int i = 0; i < n; i++) {
    int panjang = sizeof(matriks[i]) / sizeof(matriks[i][0]);
    for (int j = 0; j < panjang; j++) {
      cout << matriks[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
