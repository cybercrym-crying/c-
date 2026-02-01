#include <cctype>
#include <iostream>
#include <string>
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
using namespace std;

bool checkUserInput(string inputUser);
void displayTodoList(string todo[], int ukuran);
void clearScreen();
void groupDisplay();
int main() {
  groupDisplay();

  string todoList[101], inputUser;
  int n = sizeof(todoList) / sizeof(todoList[0]);
  for (int i = 0; i < n; i++) {
    todoList[i] = "0";
  }
  while (true) {
    cout << "----- TODO LIST PROGRAM -----\n\n";
    cout << "1. Add Todo List\n";
    cout << "2. Checked Todo List\n";
    cout << "3. Quit\n\n";
    cout << "Input Your Choice : ";
    cin >> inputUser;
    cin.ignore();

    switch (stoi(inputUser)) {

    case 1:
      cout << "[0] Untuk Keluar\n";
      for (int i = 0; i < n; i++) {

        cout << "Input Todo List : ";
        getline(cin, inputUser);

        if (inputUser == "0") {

          break;
        }
        todoList[i] = inputUser;
      }
      cout << endl;
      continue;
    case 2:
      while (true) {
        displayTodoList(todoList, n);
        cout << endl;
        cout << "[0] To Quit" << endl;
        cout << "Input Your Choice : ";
        cin >> inputUser;
        if (checkUserInput(inputUser) == false || inputUser == "0") {
          cout << "Input Must Be Number\n";
          break;
        }
        todoList[stoi(inputUser) - 1] =
            todoList[stoi(inputUser) - 1] + "     \t[ Done ]";

        continue;
      }
      cout << endl;
      continue;
    case 3:
      cout << "Program Stoped\n\n";
      exit(0);
    default:
      cout << "Not In Option" << endl;
      continue;
    }
  }
  return 0;
}

void clearScreen() { std::cout << "\033[2J\033[H"; }

void displayTodoList(string todo[], int ukuran) {
  for (int i = 0; i < ukuran; i++) {
    if (todo[i] != "0") {
      cout << i + 1 << ". " << todo[i] << endl;
      continue;
    }
    break;
  }
}

bool checkUserInput(string inputUser) {
  for (char c : inputUser) {
    if (!(isdigit(c))) {
      return false;
    }
  }
  return true;
}

void groupDisplay() {
  cout << BOLD << GREEN << "-----KELOMPOK 9-----" << RESET << endl;
  cout << GREEN
       << "1. Ajis Aditya Alzahril\n2. Akbar Rachim\n3. M. Radja Nur Akbar\n"
       << RESET;
  cout << BOLD << GREEN << "--------------------" << RESET << endl << endl;
}
