#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
using namespace std;

struct foodList {
  string nameFood;
  int priceFood;
};

void listMenu(const vector<foodList> &l);
void loadingAnimation(int much);
void takeMenu(vector<foodList> &f);
void orderCheck(vector<foodList> &f, int &noOrder, int &muchOrder);

int main() {
  int noOrder, muchOrder, orderTotal;
  vector<foodList> food;
  takeMenu(food);
  cout << "WELCOME TO MY RESTOURANT" << endl << endl;
  listMenu(food);
  cout << endl;
  orderCheck(food, noOrder, muchOrder);
  orderTotal = food[noOrder - 1].priceFood * muchOrder;
  cout << endl
       << "Order : " << food[noOrder - 1].nameFood << " " << muchOrder << "x "
       << food[noOrder - 1].priceFood << endl;
  cout << "Order Total : " << orderTotal << endl;
  loadingAnimation(muchOrder);
  return 0;
}

// FUNCTION
void takeMenu(vector<foodList> &f) {
  string name;
  int price;
  ifstream fileMenu("food_menu.txt", ios::in);
  if (fileMenu.is_open()) {
    while (fileMenu >> name >> price) {
      f.push_back({name, price});
    }
  } else {
    cout << "Failed To Open The Menu" << endl;
    exit(1);
  }
  fileMenu.close();
}

void listMenu(const vector<foodList> &l) {
  int i = 1;
  cout << "-------------------------" << endl;
  cout << "Name \t\t" << "|  " << "Price" << endl;
  cout << "-------------------------" << endl;
  for (const auto &f : l) {

    cout << i << ". " << f.nameFood << "\t|  " << f.priceFood << endl;
    i++;
  }
  cout << "-------------------------" << endl;
}

void orderCheck(vector<foodList> &f, int &noOrder, int &muchOrder) {
  while (true) {
    cout << "Input Your Number Order : ";
    if (!(cin >> noOrder) || noOrder > f.size() || noOrder <= 0) {
      cout << "Input Harus Berupa No Di Menu" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
    break;
  }

  while (true) {
    cout << "Input Your Much Order : ";
    if (!(cin >> muchOrder)) {
      cout << "Input Harus Berupa Angka" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
    break;
  }
}

void loadingAnimation(int much) {
  vector<char> loadingStick = {'|', '/', '-', '\\'};
  for (int i = 0; i < much; i++) {
    for (char l : loadingStick) {
      cout << "Your Order Will Be Served [" << l << "]" << "\r" << flush;
      this_thread::sleep_for(chrono::milliseconds(100));
    }
  }
  cout << endl << "Here Your Order HAPPY MEAL";
}
