#include <iostream>
#include <string>
using namespace std;

class Item {
public:
  string itemName;
  void useItem() { cout << "Menggunakan " << itemName << endl; }
  void eraseItem() { cout << "Mengahapus " << itemName << endl; }
};

class Tool : public Item {
public:
  void repairTool() { cout << "Memperbaiki " << itemName << endl; }
};

class Vehicle {
public:
  void turnOnMachine() { cout << "Machine On" << endl; }
};

class Car : public Vehicle {
public:
  void speeding() { cout << "Brrrrmrmmmrm" << endl; }
};

class RaceCar : public Car {
public:
  void increaseSpeed() { cout << "BRMMMMMMMMMMMMMMMMM" << endl; }
};
int main() {
  Tool peralatan;
  peralatan.itemName = "Pickaxe";
  peralatan.useItem();
  peralatan.repairTool();
  peralatan.eraseItem();
  cout << endl;
  RaceCar honda;
  honda.turnOnMachine();
  honda.speeding();
  honda.increaseSpeed();
  return 0;
}
