#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Item {
protected:
  string itemName;
  int stackMax;

public:
  Item(string name, int stack) : itemName(name), stackMax(stack) {}
  string getName() const { return itemName; }
};
class Metal : public Item {
  int metalPrice;

public:
  Metal(string name, int price, int stack = 99)
      : Item(name, stack), metalPrice(price) {}
};
class Bag : public Item {
  vector<unique_ptr<Item>> bagContent;

public:
  bool itemExist(string name) {
    for (auto const &item : bagContent) {
      if (item->getName() == name) {
        return true;
      }
    }
    return false;
  }
  void addToBag(string name, int amount) {
    if (itemExist(name)) {
    }
    bagContent.emplace_back(make_unique<Item>(name, amount));
  }
};

int main() {
  vector<Metal> metal;
  metal.emplace_back("Gold", 10000);
  metal.emplace_back("Iron", 1250);
  addToBag("Iron", 1);
  return 0;
}
