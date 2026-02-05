
#include <bits/stdc++.h>
using namespace std;
int main() {
  // array 2d
  /*
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
*/
  // array 3d

  int A[2][2] = {{1, 3}, {7, 11}};
  int B[2][2] = {{1, 2}, {5, 6}};
  int C[2][2];
  int n = sizeof(A) / sizeof(A[0]);
  int m = sizeof(B) / sizeof(B[0]);
  for (int i = 0; i < n; i++) {
    int panjang = sizeof(A[i]) / sizeof(A[i][0]);
    for (int j = 0; j < panjang; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }

  // Array pointer
  int a[3] = {1, 2, 3};
  int *ptr = a;
  cout << "Alamat Memori : " << ptr << endl;
  cout << "Nilai array   : " << *ptr << endl;

  return 0;
}
