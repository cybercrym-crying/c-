
#include <cctype>
#include <iostream>
using namespace std;
bool checkUserInput(string inputUser) {
  for (char c : inputUser) {
    if (!(isdigit(c))) {
      return false;
    }
  }
  return true;
}
void displayTodoList(string todo[], int ukuran) {
  for (int i = 0; i < ukuran; i++) {
    if (todo[i] != "0") {
      cout << i + 1 << ". " << todo[i] << endl;
      continue;
    }
    break;
  }
}
void clearScreen() { std::cout << "\033[2J\033[H"; }

int main() {
  string todoList[101], inputUser;
  int n = sizeof(todoList) / sizeof(todoList[0]);
  for (int i = 0; i < n; i++) {
    todoList[i] = "0";
  }
  while (true) {
    cout << "----- TODO LIST PROGRAM -----\n\n";
    cout << "1. Add Todo List\n";
    cout << "2. Checked Todo List\n\n";
    cout << "Input Your Choice : ";
    cin >> inputUser;
    cin.ignore();
    clearScreen();
    switch (stoi(inputUser)) {

    case 1:
      cout << "[0] Untuk Keluar\n";
      for (int i = 0; i < n; i++) {

        cout << "Input Todo List : ";
        getline(cin, inputUser);

        if (inputUser == "0") {
          clearScreen();
          break;
        }
        todoList[i] = inputUser;
      }
      continue;
    case 2:
      while (true) {
        displayTodoList(todoList, n);
        cout << endl;
        cout << "Input Your Choice : ";
        cin >> inputUser;
        if (checkUserInput(inputUser) == false || inputUser == "0") {
          cout << "Input Must Be Number\n";
          break;
        }
        todoList[stoi(inputUser) - 1] =
            todoList[stoi(inputUser) - 1] + "     \t[ Done ]";
        clearScreen();
        continue;
      }
    default:
      clearScreen();
      cout << "Not In Option" << endl;
      continue;
    }
  }
  return 0;
}
