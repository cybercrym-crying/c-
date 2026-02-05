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

public:
  Item(string n) : itemName(n) {}
  string getName() const { return itemName; }
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

class Player {
  string playerName;
  int playerEnergy = 10;

public:
  Player(string n) : playerName(n) {}
};

int main() {
  vector<Metal> metal;
  Player player1("Akbar");

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
void miningProcess(vector<Metal> &metal) {
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
  randomResult = uni(gen);
}
void Metal::displayMetalInfo() {
  cout << "Metal Name   : " << getName() << endl;
  cout << "Metal Rarity : " << metalRarity << endl;
  cout << "Metal Price  : " << metalPrice << endl;
}
