#include <bits/stdc++.h>
using namespace std;

enum status_barang { batal = -1, belum_bayar, dikirim };
struct buah {
  struct jeruk {
    string rasa = "asam";
    int harga = 10000;
    bool ketersediaan = true;
  } JERUK;
  struct apel {
    string rasa = "manis";
    int harga = 12000;
    bool ketersediaan = false;
  } APEL;
};

int main() {
  status_barang pelanggan = dikirim;
  if (pelanggan == dikirim) {
    cout << "Barang masih dikirim" << endl;
  }
  buah jeruk;
  cout << jeruk.JERUK.rasa;
  return 0;
}
