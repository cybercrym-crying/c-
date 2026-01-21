#include <bits/stdc++.h>
using namespace std;

struct enemyList {
  string name;
  int health;
  int mana;
  int damage;
  int def;
};
struct playerList {
  string name;
  int health;
  int mana;
  int damage;
  int def;
};

void clearScreen() { std::cout << "\033[2J\033[H"; }
void characterStatus(const enemyList &character) {
  cout << "Name : " << character.name << endl;
  cout << "Health : " << character.health << endl;
  cout << "Mana : " << character.mana << endl;
  cout << endl;
}
int main() {
  vector<enemyList> enemy;
  vector<playerList> player;
  enemy.emplace_back(enemyList{"Bob", 20, 10, 2, 4});
  enemy.emplace_back(enemyList{"Lea", 10, 12, 5, 3});
  player.emplace_back(playerList{"User", 50, 39, 10, 7});
  string attackChoose;
  int playerChance = player.size(), enemyChance = 0;

  while (true) {
    cout << "Player Status" << endl;
    playerList &player1 = player[0];
    cout << "Name : " << player1.name << endl;
    cout << "Health : " << player1.health << endl;
    cout << "Mana : " << player1.mana << endl;
    cout << endl;

    cout << "Enemy Status" << endl;

    for (int i = 0; i < enemy.size(); i++) {
      characterStatus(enemy.at(i));
    }

    // Player Chance
    if (playerChance > 0) {
      cout << "Choose Name of Enemy to Attack : ";
      cin >> attackChoose;
      auto it = ranges::find_if(enemy, [&](const enemyList &choose) {
        return choose.name == attackChoose;
      });
      if (it != enemy.end()) {
        it->health -= (player1.damage - it->def);
        player1.mana -= 2;
        playerChance = 0;
        cout << "Attack To " << attackChoose << endl;
        this_thread::sleep_for(chrono::seconds(2));
        if (it->health <= 0) {
          cout << attackChoose << " " << "Berhasil Di Kalahkan" << endl;
          enemy.erase(it);
          if (enemy.size() == 0) {
            cout << "You WINNNNN";
            return 0;
          }
        }

        clearScreen();
        continue;
      } else {
        cout << "Name Not In The Option" << endl;
        continue;
      }
    }
    // Enemny Chance
    else {
      cout << "Enemy Attack " << endl;
      this_thread::sleep_for(chrono::seconds(3));
      for (int i = 0; i < enemy.size(); i++) {
        player1.health -= enemy[i].damage;
      }
      playerChance = player.size();
      clearScreen();
    }
  }

  return 0;
}
