#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
struct Tl {
  int day;
  string month;
  int year;
  Tl(int d, string m, int y) : day(d), month(m), year(y) {}
};
struct Mahasiswa {
  string name;
  int age;
  Tl birth;
  Mahasiswa(string n, int a, int d, string m, int y)
      : name(n), age(a), birth(d, m, y) {}
};
int main() {
  auto p = make_unique<int>(10);
  cout << *p << endl;
  unique_ptr<int> q = make_unique<int>(5);
  cout << *q << endl;

  vector<unique_ptr<Mahasiswa>> v;

  v.push_back(make_unique<Mahasiswa>("Akbar", 10, 10, "July", 2002));
  cout << v[0]->name;
}
