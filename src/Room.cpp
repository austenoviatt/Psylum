/*#include "Room.h"
#include "Character.h"
#include "Inventory.h"
#include "keyItem.h"
#include <string>
#include <vector>

Room::~Room() {
  for (uint i = 0; i < characters.size(); i++) {
    delete[] contents[i];
    contents[i] = nullptr;
  }
  for (uint i = 0; i < events.size(); i++){
    delete[] contents[i];
    contents[i] = nullptr;
  }
  for (uint i = 0; i < exits.size(); i++){
    delete[] contents[i];
    contents[i] = nullptr;
  }
  for (uint i = 0; i < inventory.size(); i++){
    delete[] contents[i];
    contents[i] = nullptr;
  }
  delete[] description;
  delete[] name;
}

Room::Room() {PLAYER_H
string name = "DEFAULT ROOM NAME";
string description = "DEFAULT ROOM DESCRIPTION";
bool locked = false;
inventory inv= nullptr;
KeyItem key = 0;
exits = nullptr;
events = nullptr;
characters = nullptr;
}

Room::Room(string a, string b, bool c, std::vector<Inventory> d,
           keyItem e, std::vector<Room*> f, std::vector<Events> g,
           std::vector<Character> h){
             name = name;
             description = description;
             locked = locked;
             invnetory = d;
             keyItem = e;
             exits = f;
             events = g;
             characters = h;}




           }
*/
