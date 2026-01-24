#include <iostream>
#include <random>
#include <string>
#include <vector>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
using namespace std;

bool cekUserInput(string inputUser);
void clearScreen();

class Atm {
private:
  int saldo;
  string userName;
  string userPin;

public:
  Atm(string inputUserName, string inputUserPin) {
    saldo = 0;
    userName = inputUserName;
    userPin = inputUserPin;
  }

  void withdrawMoney();
  void cashDeposit();
  void balanceCheck();
};

int main() {
  string inputUser;
  Atm akun = {"user", "123"};
  while (true) {
    cout << BOLD << "-------ATM-------" << RESET << endl;
    cout << BOLD << "1. Withdraw Cash" << RESET << endl;
    cout << BOLD << "2. Cash Deposit" << RESET << endl;
    cout << BOLD << "3. Balance Check" << endl << RESET << endl;
    cout << "Choose Menu : ";
    cin >> inputUser;
    if (!(cekUserInput(inputUser))) {
      clearScreen();
      continue;
    }
    switch (stoi(inputUser)) {
    case 1:
      akun.withdrawMoney();
      continue;
    case 2:
      akun.cashDeposit();
      continue;

    case 3:
      akun.balanceCheck();
      continue;

    default:
      clearScreen();
      continue;
    }
  }
  return 0;
}

void clearScreen() { std::cout << "\033[2J\033[1;1H"; }

bool cekUserInput(string inputUser) {
  if (inputUser.empty()) {
    clearScreen();

    cout << "Input must be number" << endl;
    return false;
  } else {
    for (char c : inputUser) {
      if (!isdigit(c)) {
        clearScreen();

        cout << "Input must be number" << endl;
        return false;
      }
    }
    return true;
  }
}

void Atm::withdrawMoney() {
  string withdrawTotal;
  cout << "Input amount cash : ";
  cin >> withdrawTotal;
  if (cekUserInput(withdrawTotal)) {

    if (saldo < stoi(withdrawTotal)) {
      clearScreen();

      cout << RED << BOLD << "Insufficient balance" << RESET << endl;
    } else {
      clearScreen();
      cout << GREEN << BOLD << "Succes" << RESET << endl;

      saldo -= stoi(withdrawTotal);
    }
  }
}

void Atm::cashDeposit() {
  string totalCashDeposit, inputPin, inputName;
  cout << "Input user name : ";
  cin >> inputName;
  cout << "Input user pin  : ";
  cin >> inputPin;
  if (inputPin != userPin || inputName != userName) {
    clearScreen();

    cout << RED << "Incorrect pin or name" << RESET << endl;
  } else {
    cout << "Input amount of deposit : " << endl;
    cin >> totalCashDeposit;
    if (cekUserInput(totalCashDeposit)) {
      clearScreen();

      cout << GREEN << BOLD << "Succes" << RESET << endl;
      saldo += stoi(totalCashDeposit);
    }
  }
}

void Atm::balanceCheck() { cout << saldo << endl; }
