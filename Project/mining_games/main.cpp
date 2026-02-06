#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <thread>
#include <vector>
using namespace std;

enum Rarity { COMMON = 60, UNCOMMON = 30, RARE = 6, EPIC = 3, LEGENDARY = 1 };

class Item {
  string itemName;
  int stackMax = 99;
  int itemStack = 0;

public:
  Item(string n) : itemName(n) {}
  string getName() const { return itemName; }
  int getStackMax() const { return stackMax; }
  int getItemStack() const { return itemStack; }
  void addStack(int amount) { itemStack += amount; }
};

class Metal : public Item {
  int metalHardness;
  int metalRarity;
  int metalPrice;

public:
  Metal(string n, int h, int r, int p)
      : Item(n), metalHardness(h), metalRarity(r), metalPrice(p) {}
  int getRarity() const { return metalRarity; }
  void displayMetalInfo();
};

class Bag {
  vector<unique_ptr<Item>> bag;

public:
  Item *itemExist(string name) {
    for (auto const &item : bag) {
      if (item->getName() == name &&
          item->getItemStack() != item->getStackMax()) {
        return item.get();
      }
      return nullptr;
    }
    return nullptr;
  }

  void addItem(string name, int amount) {
    while (true) {
      Item *item = itemExist(name);
      int stackReady = item->getStackMax() - item->getItemStack();
      if (item == nullptr) {
        continue;
      } else if (amount > stackReady) {
        item->addStack(stackReady);
        amount -= stackReady;
        continue;
      } else {
        item->addStack(amount);
        break;
      }
      break;
    }
  }
};

class Player {
  string playerName;
  int playerEnergy = 10;

public:
  Player(string n) : playerName(n) {}
};

void addMetalFromFile(vector<Metal> &metal);
void miningProcess(vector<Metal> &metal, Bag &playerBag);
int main() {
  vector<Metal> metal;
  Bag playerBag;
  Player player1("Akbar");
  addMetalFromFile(metal);
  miningProcess(metal, playerBag);
  return 0;
}

void addMetalFromFile(vector<Metal> &metal) {
  string name, rarityB;
  int hard, rarity, price;
  ifstream fileMetal("metal.txt");
  if (fileMetal.is_open()) {
    while (fileMetal >> name >> hard >> rarityB >> price) {
      if (rarityB == "COMMON") {
        rarity = COMMON;
      } else if (rarityB == "UNCOMMON") {
        rarity = UNCOMMON;
      } else if (rarityB == "RARE") {
        rarity = RARE;
      } else if (rarityB == "EPIC") {
        rarity = EPIC;
      } else {
        rarity = LEGENDARY;
      }

      metal.emplace_back(name, hard, rarity, price);
    }
    fileMetal.close();
  } else {
    cout << "Failed to load Metal" << endl;
  }
}
void miningProcess(vector<Metal> &metal, Bag &playerBag) {
  random_device rd;
  mt19937 gen(rd());
  discrete_distribution<> dist{COMMON, UNCOMMON, RARE, EPIC, LEGENDARY};
  vector<Metal> metalListRarity;
  int rarityMetal;
  int randomResult = dist(gen);

  switch (randomResult) {
  case 0:
    rarityMetal = COMMON;
    break;
  case 1:
    rarityMetal = UNCOMMON;
    break;
  case 2:
    rarityMetal = RARE;
    break;
  case 3:
    rarityMetal = EPIC;
    break;
  case 4:
    rarityMetal = LEGENDARY;
    break;
  }
  for (auto const &m : metal) {
    if (m.getRarity() == rarityMetal) {
      metalListRarity.emplace_back(m);
    }
  }
  uniform_int_distribution<> uni(0, metalListRarity.size() - 1);
  discrete_distribution<> randomAmount{1, 2, 3};
  randomResult = uni(gen);
  int randomResultAmount = randomAmount(gen);
  metalListRarity[randomResult].displayMetalInfo();
  cout << "Metal Amount : " << randomResultAmount << endl;
  playerBag.addItem(metalListRarity[randomResult].getName(),
                    randomResultAmount);
}
void Metal::displayMetalInfo() {
  cout << "Metal Name   : " << getName() << endl;
  cout << "Metal Rarity : " << metalRarity << endl;
  cout << "Metal Price  : " << metalPrice << endl;
}
