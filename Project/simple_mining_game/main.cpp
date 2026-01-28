#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

enum MetalRarity {
  COMMON = 70,
  UNCOMMON = 50,
  RARE = 24,
  EPIC = 10,
  LEGENDARY = 3
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
};

class PickaxeType {
private:
  string pickaxeName;
  int pickaxeDurability;

public:
};

int main() {
  vector<MetalType> metals;
  string inputName;
  int defaultLevel = 1, defaultMana = 10, defaultLucky = 5, defaultStrenght = 2;
  metals.emplace_back("Copper", 1000, COMMON, 35);
  metals.emplace_back("Ore", 1200, COMMON, 38);
  metals.emplace_back("Iron", 1500, UNCOMMON, 44);
  metals.emplace_back("Gold", 2800, RARE, 12);
  metals[2].displayInfo();

  return 0;
}
