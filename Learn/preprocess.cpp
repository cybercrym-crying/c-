#include <iostream>
#define ANGKA 1
#if ANGKA > 1
#define KUADRAT(X) (X * X)
#else
#define KUADRAT(X) (X + X)
#endif
using namespace std;

int main() {
  cout << KUADRAT(ANGKA);
  return 0;
}
