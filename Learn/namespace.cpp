#include <bits/stdc++.h>

namespace fungsi {
void tambah(int a, int b) { std::cout << a + b << std::endl; }
} // namespace fungsi
using namespace fungsi;
int main() {
  fungsi::tambah(10, 2);
  tambah(10, 20);
  return 0;
}
