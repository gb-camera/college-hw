// -----------------------------------------------------------------------
// monsters.cpp
// -----------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int LINE_WIDTH = 50;
const string LINE_DIVIDE = "--------";

struct Weapon {
    string name;
    int damageModifier;
};

struct Stats {
   int agility;
   int toughness;
   int hitpoints;
};

struct Monster {
   string name;
   Stats stats;
   Weapon weapon;
} ;

///TODO (2):  declare Hero struct
struct Hero {
   string name;
   Stats stats;
   Weapon weapon;
};

//output agility, toughness, and hitpoints, NO newline
void displayStats(const Stats& s);

//output Weapon name and damageModifier, NO newline
void displayWeapon(const Weapon& w);

//output name, stats, and weapon
void displayMonster(const Monster& m);

//output name, stats, and weapon
void displayHero(const Hero& h);

//roll a d6 numDice times (nd6)
int d6Roll(int numDice);

//Hero attacks a Monster
void attackMonster(const Hero& h, Monster& m);

//Monster attacks the Hero
void attackHero(Hero& h, const Monster& m);

//Display each monster in the vector
void displayMonsters(const vector<Monster>& lair);

//Each Monster whose hitpoints > 0 attacks the Hero
//If the hero's hitpoints drop below zero, break
void monstersTurn(Hero& h, const vector<Monster>& lair);

//The Hero attacks each Monster whose hitpoints > 0
void heroTurn(const Hero& h, vector<Monster>& lair);

//returns true if there is no Monster whose hitpoints > 0
bool lairCleared(vector<Monster>& lair);

//begin an epic battle!  displayHero, displayMonsters
//loop as long as the hero is alive and the lair is not clear
void enterLair(Hero& h, vector<Monster>& lair);
//*******

int main()
{
    srand(1337);  //don't change me!

    Weapon teeth = {"teeth/claws", -6};
    Weapon axe = {"sharp axe", +1};
    Weapon dagger = {"steel dagger", +2};

    vector<Monster> lair;
    lair.push_back({"Rat", Stats{3, 4, 2}, teeth});
    lair.push_back({"Goblin", Stats{2, 7, 9}, axe});

    Hero hero = {"Darwin", Stats{5, 9, 20}, dagger};

    enterLair(hero, lair);

    if(lairCleared(lair)) cout << "You win!" << endl;
    else cout << "Game over" << endl;

    return 0;
}

void displayStats(const Stats& s) {
   cout << "[a:" << s.agility << ", t:" << s.toughness << ", hp:" << s.hitpoints << "]";
}

void displayWeapon(const Weapon& w) {
   if(w.damageModifier >= 0) {
      cout << "<" << w.name << ", +" << w.damageModifier << ">";
   }
   else {
      cout << "<" << w.name << ", " << w.damageModifier << ">";
   }
}

void displayMonster(const Monster& m) {
   cout << LINE_DIVIDE << endl;
   cout << m.name << " ";
   displayStats(m.stats);
   cout << " ";
   displayWeapon(m.weapon);
   cout << endl << LINE_DIVIDE << endl;
}

//output name, stats, and weapon
void displayHero(const Hero& h) {
   cout << LINE_DIVIDE << endl;
   cout << "Our Hero..." << endl;
   cout << h.name << " ";
   displayStats(h.stats);
   cout << " ";
   displayWeapon(h.weapon);
   cout << endl << LINE_DIVIDE << endl;
}

//roll a d6 numDice times (nd6)
int d6Roll(int numDice) {
   int rollSum = 0;
   for(int i = 1; i <= numDice; i++) {
      rollSum += rand() % 6 + 1;
   }
   return rollSum;
}

//Hero attacks a Monster
void attackMonster(const Hero& h, Monster& m) {
   cout << h.name << " attacks " << m.name << " with " << h.weapon.name << "..." << endl;
   int roll = d6Roll(1);
   cout << "  Hit? " << roll << " vs. " << m.stats.agility << " : ";
   if(roll < m.stats.agility) {
      cout << "no" << endl;
      cout << h.name << " misses." << endl;
      return;
   }
   else if(roll >= m.stats.agility) {
      cout << "yes" << endl;
      cout << h.name << " hits " << m.name << "..." << endl;
      int hitpoints = d6Roll(2);
      cout << "  Inflict? " << hitpoints << " vs. " << m.stats.toughness << " : ";
      if(hitpoints <= m.stats.toughness) {
         cout << "no" << endl;
         cout << m.name << "'s toughness prevents damage." << endl;
         return;
      }
      else if(hitpoints > m.stats.toughness) {
         cout << "yes" << endl;
         hitpoints += h.weapon.damageModifier;
         if(hitpoints < 0) {
            hitpoints = 0;
         }
         cout << h.name << " inflicts " << hitpoints << " points of damage..." << endl;
         m.stats.hitpoints -= hitpoints;
         if(m.stats.hitpoints <= 0) {
            cout << m.name << " is slain!" << endl;
         }
         return;
      }
   }
}

//Monster attacks the Hero
void attackHero(Hero& h, const Monster& m) {
   cout << m.name << " attacks " << h.name << " with " << m.weapon.name << "..." << endl;
   int roll = d6Roll(1);
   cout << "  Hit? " << roll << " vs. " << h.stats.agility << " : ";
   if(roll < h.stats.agility) {
      cout << "no" << endl;
      cout << m.name << " misses." << endl;
      return;
   }
   else if(roll >= h.stats.agility) {
      cout << "yes" << endl;
      cout << m.name << " hits " << h.name << "..." << endl;
      int hitpoints = d6Roll(2);
      cout << "  Inflict? " << hitpoints << " vs. " << h.stats.toughness << " : ";
      if(hitpoints <= h.stats.toughness) {
         cout << "no" << endl;
         cout << h.name << "'s toughness prevents damage." << endl;
         return;
      }
      else if(hitpoints > h.stats.toughness) {
         cout << "yes" << endl;
         hitpoints += m.weapon.damageModifier;
         if(hitpoints < 0) {
            hitpoints = 0;
         }
         cout << m.name << " inflicts " << hitpoints << " points of damage..." << endl;
         h.stats.hitpoints -= hitpoints;
         if(h.stats.hitpoints <= 0) {
            cout << h.name << " is slain!" << endl;
         }
         return;
      }
   }
}

//Display each monster in the vector
void displayMonsters(const vector<Monster>& lair) {
   cout << "Monster lair..." << endl;
   for(size_t i = 0; i < lair.size(); i++) {
      displayMonster(lair.at(i));
   }
}

//Each Monster whose hitpoints > 0 attacks the Hero
//If the hero's hitpoints drop below zero, break
void monstersTurn(Hero& h, const vector<Monster>& lair) {
   for(size_t i = 0; i < lair.size(); i++) {
      if(lair.at(i).stats.hitpoints > 0) {
         displayMonster(lair.at(i));
         attackHero(h, lair.at(i));
      }
      if(h.stats.hitpoints <= 0) {
         break;
      }
   }
}

//The Hero attacks each Monster whose hitpoints > 0
void heroTurn(const Hero& h, vector<Monster>& lair) {
   displayHero(h);
   for(size_t i = 0; i < lair.size(); i++) {
      if(lair.at(i).stats.hitpoints > 0) {
         attackMonster(h, lair.at(i));
      }
   }
}

//returns true if there is no Monster whose hitpoints > 0
bool lairCleared(vector<Monster>& lair) {
   for(size_t i = 0; i < lair.size(); i++) {
      if(lair.at(i).stats.hitpoints > 0) {
         return false;
      }
      else {
         continue;
      }
   }
   return true;
}

void enterLair(Hero& h, vector<Monster>& lair) {
   displayHero(h);
   displayMonsters(lair);
   cout << "The battle begins..." << endl;
   while(h.stats.hitpoints > 0 && !lairCleared(lair)) {
      heroTurn(h, lair);
      if(!lairCleared(lair)) {
         monstersTurn(h, lair);
      }
   }
}