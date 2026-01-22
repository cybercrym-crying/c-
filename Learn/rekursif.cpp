#include <bits/stdc++.h>
using namespace std;

int rekursif(int i) {
  if (i == 1) {
    return 1;
  } else if (i <= 0) {
    return 0;
  }
  return rekursif(i - 1) * i;
}
int main() {
  cout << rekursif(5) << endl;
  return 0;
}

// fungsi memanggil fungsi hingga kondisi berhenti terpenuhi
