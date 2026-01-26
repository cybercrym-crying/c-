#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d, inX, inY;
  double T;
  cin >> n >> d;
  vector<int> kedekatan;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> inX >> inY;
    x[i] = inX;
    y[i] = inY;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      T = pow(abs(x[i] - x[j]), d) + pow(abs(y[i] - y[j]), d);
      kedekatan.push_back(round(T));
    }

    sort(kedekatan.begin(), kedekatan.end());
  }
  cout << kedekatan[0] << " " << kedekatan[n - 1];
  return 0;
}
