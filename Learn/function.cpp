#include <bits/stdc++.h>
using namespace std;
int add(int i); // deklarasi and prototype

int add(int i, int j) { // definition dan sebuah fungsi bisa dengan nama yang
                        // sama namun dengan parameter yang berbeda

  int a = i + j;
  return a;
}
// int addsome(inti = 3,int j = 3, int k); tidak boleh
int addsome(int i, int j = 3, int k = 2) { return i + j + k; }
void reference(int &input) { input = 1; } //  parameter dengan alamat memori
void outputVector(const vector<int> &v) {
  for (int i : v) {
    cout << i << " ";
  }
}
int main() {
  int angka = 10;
  cout << addsome(1) << endl;
  cout << add(1) << endl;
  cout << angka << endl;
  reference(angka);
  cout << angka << endl;
  vector<int> number = {1, 2, 3, 4, 5, 6};
  outputVector(number);
  return 0;
}

int add(int i) { return true; }
