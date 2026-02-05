#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class Item {
  string itemName;
  int itemStackMax = 99;
  int itemAmount;

public:
  string getName() const { return itemName; }
  int getAmount() const { return itemAmount; }
  int getStack() const { return itemStackMax; }
  Item(string n, int a) : itemName(n), itemAmount(a) {}

  void addAmount(int amount) { itemAmount += amount; }
};

class Resource : public Item {
  int resoPrice;
  int resoRarity;

public:
  Resource(string n, int a, int p, int r)
      : Item(n, a), resoPrice(p), resoRarity(r) {}
};

class Bag {
  vector<unique_ptr<Item>> bag;

public:
  Item *itemExist(const string &itemName) {
    for (auto const &item : bag) {
      if (item->getName() == itemName && item->getAmount() != 99) {
        return item.get();
      }
    }
    return nullptr;
  }

  void addItem(string itemName, int itemAmount, int itemPrice, int itemRarity) {
    Item *item = itemExist(itemName);
    if (item == nullptr) {
      bag.emplace_back(
          make_unique<Resource>(itemName, itemAmount, itemPrice, itemRarity));
    } else {
      if (item->getStack() < item->getAmount() + itemAmount) {
        bag.emplace_back(
            make_unique<Resource>(itemName, itemAmount, itemPrice, itemRarity));
      } else {
        item->addAmount(itemAmount);
      }
    }
  }

  void displayBagContent() {
    if (bag.empty()) {
      cout << "Bag empty" << endl;
    } else {
      for (auto const &item : bag) {
        cout << "Item Name   : " << item->getName() << endl;
        cout << "Item Amount : " << item->getAmount() << endl;
      }
    }
  }
};

int main() {

  Bag playerBag;
  playerBag.displayBagContent();
  playerBag.addItem("Metal", 10, 1999, 10);
  playerBag.displayBagContent();
  return 0;
}
