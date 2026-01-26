#include <bits/stdc++.h>
using namespace std;

class character {
private:
  string playerName;
  int playerLevel;
  int playerMana;
  int playerLucky;

public:
  character(string name, int level, int mana, int lucky) {
    playerName = name;
    playerLevel = level;
    playerMana = mana;
    playerLucky = lucky;
  }
};

class metalType {
private:
  string metalName;
  int metalPrice;
  int metalRarity;
  int metalHardness;

public:
  metalType(string name, int price, int rarity, int hardness) {
    metalName = name;
    metalPrice = price;
    metalRarity = rarity;
    metalHardness = hardness;
  }
};

int main() {

  string inputName;
  int defaultLevel = 1, defaultMana = 10, defaultLucky = 5;
  cout << "Input you character name  : ";
  getline(cin, inputName);
  character player(inputName, defaultLevel, defaultMana, defaultLucky);
  cout << "Mining...";

  return 0;
}
