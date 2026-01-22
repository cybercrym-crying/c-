#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 1;
  if (a > 0 && a < 10) {
    cout << "a >= 0 a < 10";
  } else if (a >= 10) {
    cout << "a >= 10";
  } else {
    cout << "a = 0";
  }
  cout << endl;

  // switch and case
  switch (a) {

  case 100:
    cout << 100;
    break;
  case 120:
  case 123:
    cout << 123;
    break;
  default:
    cout << "Not Found";
  }
  cout << endl;
  bool hasil = (a == 123) ? true : false;
  cout << hasil;
  return 0;
}
