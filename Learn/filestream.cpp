#include <bits/stdc++.h>
using namespace std;

int main() {
  string text, erase = "Burger 10k";
  fstream fileReal("data.txt", ios::out | ios::in);
  if (fileReal.is_open()) {
    ofstream fileTemp("temp.txt", ios::app);
    while (getline(fileReal, text)) {
      if (fileTemp.is_open()) {
        if (text != erase) {
          fileTemp << text << "\n";
        }
      }
    }

    fileTemp.close();
  }
  fileReal.close();

  remove("data.txt");
  rename("temp.txt", "data.txt");

  return 0;
}
