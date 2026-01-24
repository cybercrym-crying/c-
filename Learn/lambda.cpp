#include <bits/stdc++.h>
using namespace std;

int main() {
  int nilai = 100;

  auto lamb = [&]() { return nilai--; };
  lamb();
  cout << nilai;
  return 0;
}
