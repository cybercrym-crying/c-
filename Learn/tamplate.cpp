#include <bits/stdc++.h>
using namespace std;
template <typename T> T getMin(T a, T b) { return (a < b) ? a : b; }
int main() {
  cout << getMin(2, 1) << endl;
  cout << getMin('a', 'b');
  return 0;
}
