#include <iostream>
#include <string>
using namespace std;
class Makanan {
public:
  string namaMakanan;
  string porsiMakanan;
  int hargaMakanan;
  Makanan(string inputNama, string inputPorsi, int inputHarga) {
    namaMakanan = inputNama;
    porsiMakanan = inputPorsi;
    hargaMakanan = inputHarga;
  }

  void Tampilkan() {
    cout << namaMakanan << " | " << porsiMakanan << " | " << hargaMakanan
         << endl;
  }

  void UbahHarga(int &hargaLama, int hargaBaru) { hargaLama = hargaBaru; }
};
int main() {
  Makanan menu1 = {"Udang Asam Manis", "2 Orang", 32000};
  menu1.Tampilkan();
  menu1.UbahHarga(menu1.hargaMakanan, 30000);
  menu1.Tampilkan();
  return 0;
}
