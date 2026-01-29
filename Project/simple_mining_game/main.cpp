#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <vector>
using namespace std;

enum MetalRarity {
  COMMON = 60,
  UNCOMMON = 25,
  RARE = 9,
  EPIC = 4,
  LEGENDARY = 2
};

class Character {
private:
  string playerName;
  int playerMoney;
  int playerLevel;
  int playerEnergy;
  int playerStrenght;
  int playerLucky;
  int playerPoint;

public:
  Character(string name, int money, int level, int energy, int strenght,
            int lucky, int point) {
    playerName = name;
    playerMoney = money;
    playerLevel = level;
    playerEnergy = energy;
    playerStrenght = strenght;
    playerLucky = lucky;
    playerPoint = point;
  }
};

class MetalType {
private:
  string metalName;
  int metalPrice;
  int metalRarity;
  int metalHardness;

public:
  MetalType(string name, int price, int rarity, int hardness) {
    metalName = name;
    metalPrice = price;
    metalRarity = rarity;
    metalHardness = hardness;
  }
  void displayInfo() {
    cout << "Metal Name     \t: " << metalName << endl;
    cout << "Metal Price    \t: " << metalPrice << endl;
    cout << "Metal Rarity   \t: " << metalRarity << endl;
    cout << "Metal Hardness \t: " << metalHardness << endl;
  }

  void miningProcess() {}
  int getRarity() { return metalRarity; }

  void findEligibleRarity(int rarity) {}
};

class PickaxeType {
private:
  string pickaxeName;
  string pickaxeMaterial[3];
  int pickaxeDurability;

public:
};

int main() {
  random_device rd;
  mt19937 gen(rd());
  discrete_distribution<> d({COMMON, UNCOMMON, RARE, EPIC, LEGENDARY});
  vector<MetalType> metals;
  vector<MetalType *> eligibleRarity;
  string inputName, inputUser = "y";
  int defaultLevel = 1, defaultMana = 10, defaultLucky = 5, defaultStrenght = 2,
      rarityResult, raritySearch;
  metals.emplace_back("Copper", 1000, COMMON, 35);
  metals.emplace_back("Ore", 1200, COMMON, 38);
  metals.emplace_back("Iron", 1500, UNCOMMON, 44);
  metals.emplace_back("Gold", 2800, RARE, 55);
  metals.emplace_back("Diamond", 5600, EPIC, 79);
  metals.emplace_back("Mithril", 10000, LEGENDARY, 100);

  while (inputUser == "y") {
    cout << "Menambang..." << endl;
    this_thread::sleep_for(chrono::seconds(5));
    rarityResult = d(gen);
    switch (rarityResult) {
    case 0:
      raritySearch = COMMON;
      break;

    case 1:
      raritySearch = UNCOMMON;
      break;
    case 2:
      raritySearch = RARE;
      break;
    case 3:
      raritySearch = EPIC;
      break;
    case 4:
      raritySearch = LEGENDARY;
      break;
    }
    for (auto &m : metals) {
      if (m.getRarity() == raritySearch) {
        eligibleRarity.push_back(&m);
      }
    }
    uniform_int_distribution<> randomMetal(0, eligibleRarity.size() - 1);
    int finalMetalResult = randomMetal(gen);
    eligibleRarity[finalMetalResult]->displayInfo();
    cout << endl;
    cout << "Lanjut Menambang(y/n) : ";
    cin >> inputUser;
  }
  return 0;
}
