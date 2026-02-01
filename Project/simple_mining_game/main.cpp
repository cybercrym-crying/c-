#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
public:
  string itemName;
  Item(string name) : itemName(name) {}
};

class Material : public Item {
private:
  int mountMax = 99;

public:
  Material(string name, int max) : Item(name), mountMax(max) {}
};
class Tools : public Item {
private:
  int duraMax;
  int stackMax = 1;

public:
  Tools(string name, int dura) : Item(name), duraMax(dura) {}
};

class Character {
private:
  string charName;
  int charEnergy = 10;
  int charLevel = 1;
  Tools *tool;

public:
  Character(string name, Tools *t) : charName(name), tool(t) {}
  void useTool() { cout << "Using " << tool->itemName << endl; }
};

int main() {
  vector<Material> metal;
  Tools *ironPickaxe = new Tools("Iron Pickaxe", 50);

  Character player("Eliced Star", ironPickaxe);
  player.useTool();

  return 0;
}
