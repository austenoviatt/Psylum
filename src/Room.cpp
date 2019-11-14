#include "Room.h"
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

Room::Room() {
string name = "DEFAULT ROOM NAME";
string description = "DEFAULT ROOM DESCRIPTION";
bool locked = false;
inventory inv= nullptr;
KeyItem key = 0;
exits = nullptr;
events = nullptr;
characters = nullptr;
}

Room::Room(string name, string description, bool locked, Inventory inventory,
           keyItem key, std::vector<Room*> exits, std::vector<Events> events,
           std::vector<Character> character){


           }
