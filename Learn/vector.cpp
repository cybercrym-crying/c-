#include <bits/stdc++.h>
using namespace std;
struct akun {
  string userName;
  string userPass;
};
int main() {
  vector<char> huruf = {'q', 'b', 'l'};
  if (ranges::contains(huruf, 'l')) {
    cout << "true\n";
  }
  string name, pass;
  vector<akun> listAkun;
  cin >> name;
  cin >> pass;
  listAkun.push_back({name, pass});
  cout << listAkun[0].userName;

  return 0;
}
