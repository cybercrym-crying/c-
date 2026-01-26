#include <iostream>
#include <string>
using namespace std;
class salary {
private:
  int uang;

public:
  salary(int jumlahUang) { uang = jumlahUang; }
  friend void displaySalary(salary karyawan);
};

void displaySalary(salary karyawan) {
  cout << "Gaji : " << karyawan.uang << endl;
}

int main() {
  salary karyawan1(7000000);
  displaySalary(karyawan1);
  return 0;
}
