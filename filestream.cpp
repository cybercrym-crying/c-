#include <bits/stdc++.h>
using namespace std;

int main() {
  ofstream file("data.txt");
  if (file.is_open()) {

    file << "Halo apa kabar";

    file.close();
    cout << "Penulisan ke file berhasil \n file di tutup..";
  } else {
    cout << "Gagal membuka file" << endl;
  }
  return 0;
}
