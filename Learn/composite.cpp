#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
public:
  string nameItem;
  int mountItemMax;

  Item(string n, int m) : nameItem(n), mountItemMax(m) {}
};

class Tool : public Item {
public:
  int duraTool;
  Tool(string n, int m, int d) : Item(n, m), duraTool(d) {}
};

class Character {
public:
  string charName;
  Tool *pickaxe;

  Character(string c, Tool *t) : charName(c), pickaxe(t) {}
  virtual void useTool() { cout << "Use Tool " << pickaxe->nameItem << endl; }
};

class Dwarf : public Character {
public:
  Dwarf(string n, Tool *t) : Character(n, t) {}

  void useTool() override {
    cout << "Dwarf" << endl;
    Character::useTool();
  }
};
int main() {

  Tool *ironPickaxe = new Tool("Iron Pickaxe", 1, 43);
  Dwarf player("Eliced", ironPickaxe);
  player.useTool();

  return 0;
}
