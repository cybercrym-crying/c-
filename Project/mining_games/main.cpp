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
      if (item->getName() == name) {
        return item.get();
      }
    }
    return nullptr;
  }

  void addItem(Metal &metal, int amount);
  void displayBagContent();
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
  addMetalFromFile(metal);
  string playerInput;
  Bag playerBag;
  Player player1("Akbar");
  while (true) {
    cout << "1. Mining" << endl;
    cout << "2. Bag" << endl;
    cout << "Input Menu : ";
    cin >> playerInput;
    cout << endl;
    if (playerInput == "1") {
      miningProcess(metal, playerBag);
    } else if (playerInput == "2") {
      playerBag.displayBagContent();
    } else {
      cout << "Not In Option" << endl;
      continue;
    }
  }
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
  this_thread::sleep_for(chrono::seconds(5));
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
  uniform_int_distribution<> randomAmount{1, 3};
  randomResult = uni(gen);
  int randomResultAmount = randomAmount(gen);
  metalListRarity[randomResult].displayMetalInfo();
  cout << "Metal Amount : " << randomResultAmount << endl << endl;
  playerBag.addItem(metalListRarity[randomResult], randomResultAmount);
}
void Metal::displayMetalInfo() {
  cout << "Metal Name   : " << getName() << endl;
  cout << "Metal Rarity : " << metalRarity << endl;
  cout << "Metal Price  : " << metalPrice << endl;
}

void Bag::addItem(Metal &metal, int amount) {
  while (true) {
    Item *item = itemExist(metal.getName());

    if (item == nullptr) {
      bag.emplace_back(make_unique<Metal>(metal));
      continue;
    }
    int spaceBag = item->getStackMax() - item->getItemStack();

    if (amount > spaceBag) {
      item->addStack(spaceBag);
      amount -= spaceBag;
      continue;
    } else {
      item->addStack(amount);
      break;
    }
    break;
  }
}

void Bag::displayBagContent() {
  if (bag.empty()) {
    cout << "No Item In bag" << endl;
  } else {
    for (auto const &item : bag) {
      cout << "Item Name : " << item->getName() << endl;
      cout << "Item Stack : " << item->getItemStack() << endl << endl;
    }
  }
}
