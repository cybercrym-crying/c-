#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void clearScreen() { std::cout << "\033[2J\033[H"; }
void makeAccount();
void login();

struct accountList {
  string userName;
  string userPass;
};

enum MENU_AKUN { New_Account = 1, Login, Quit };
int userInput;
string name, pass;
vector<accountList> account;

int main() {
  cout << "SELAMAT DATANG DI TOKO KAMI" << endl;

  while (true) {
    cout << "1. New Account" << endl;
    cout << "2. Login" << endl;
    cout << "3. Quit" << endl;
    cout << "Chooser number : ";
    if (!(cin >> userInput)) {
      cout << "Number Not In List" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
    clearScreen();

    // User Choose
    switch (userInput) {
    case New_Account:
      makeAccount();
      break;

    case Login:
      login();
      break;

    case Quit:
      return 0;

    default:
      cout << "Tidak Ada Dalam Pilihan" << endl;
      continue;
    }
    continue;
  }
  return 0;
}

void makeAccount() {
  while (true) {
    cout << "Username : ";
    cin >> name;
    cout << "Password : ";
    cin >> pass;
    if (ranges::contains(account, name, &accountList::userName)) {
      cout << "Username Already Used" << endl;
      cout << "Use Another Name " << endl;
    } else {
      cout << "Make Account Succes" << endl;
      account.emplace_back(accountList{name, pass});
      break;
    }
    continue;
  }
}
void login() {
  cout << "Username : ";
  cin >> name;
  cout << "Password : ";
  cin >> pass;
  auto it = ranges::find_if(
      account, [&](const accountList &acc) { return acc.userName == name; });
  if (it != account.end()) {
    for (int i = 0; i <= it->userPass.size(); i++) {
      if (it->userPass[i] != pass[i]) {
        cout << "Wrong Password..." << endl;
        break;
      } else if (i == it->userPass.size()) {
        cout << "Login Succes" << endl;
      }
    }
  }

  else {
    cout << "Username belum terdaftar" << endl;
  }
}
