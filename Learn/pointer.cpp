#include <bits/stdc++.h>
using namespace std;

int main() {
  int darah = 100;
  cout << &darah << endl;
  int *ptr_darah = &darah;
  *ptr_darah = 90;
  cout << darah;
  return 0;
}
