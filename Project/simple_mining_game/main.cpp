#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum spawnRateMetal {
  COMMON = 60,
  UNCOMMON = 30,
  RARE = 5,
  EPIC = 3,
  LEGENDARY = 2
};

class Item {
public:
  string itemName;
  Item(string name) : itemName(name) {}
  virtual void displayInfoObject() {
    cout << "Name    \t: " << itemName << endl;
  }
};

class Material : public Item {
private:
  int mountMax = 99;

public:
  Material(string name, int max) : Item(name), mountMax(max) {}
};

class WorldObject : public Item {
private:
  int durability;
  int spawnRate;

public:
  WorldObject(string name, int dura, int sr)
      : Item(name), durability(dura), spawnRate(sr) {}
  void displayInfoObject() override {
    Item::displayInfoObject();
    cout << "Durability    \t: " << durability << endl;
    cout << "Rarity    \t: " << spawnRate << endl;
  }
};

class Tools : public Item {
private:
  int durability;
  int stackMax = 1;

public:
  Tools(string name, int dura) : Item(name), durability(dura) {}
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
void addingMetalList(vector<WorldObject> &metal);

int main() {
  vector<WorldObject> metalBlock;
  Tools *ironPickaxe = new Tools("Iron Pickaxe", 50);
  Character player("Eliced Star", ironPickaxe);
  player.useTool();
  addingMetalList(metalBlock);
  metalBlock[0].displayInfoObject();
  return 0;
}

void addingMetalList(vector<WorldObject> &metal) {
  string name, bufferSR;
  int dura, spawnRate;
  ifstream fileMetal("metal_list.txt");
  if (fileMetal.is_open()) {
    while (fileMetal >> name >> dura >> bufferSR) {
      if (bufferSR == "COMMON") {
        spawnRate = COMMON;
      } else if (bufferSR == "UNCOMMON") {
        spawnRate = UNCOMMON;
      } else if (bufferSR == "RARE") {
        spawnRate = RARE;
      } else if (bufferSR == "EPIC") {
        spawnRate = EPIC;
      } else {
        spawnRate = LEGENDARY;
      }
      metal.emplace_back(name, dura, spawnRate);
    }
    fileMetal.close();
  }
}
