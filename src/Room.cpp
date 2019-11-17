

#include "Room.h"
#include "Character.h"
#include "Inventory.h"
#include "KeyItem.h"
#include <string>
#include <vector>
#include <iostream>

Room::~Room() {
//  for (uint i = 0; i < events.size(); i++){
//   delete[] events[i];
//    events[i] = nullptr;
//  }
//  for (uint i = 0; i < exits.size(); i++){
//   delete[] exits[i];
//    exits[i] = nullptr;
  }
//  for (uint i = 0; i < inventory.size(); i++){
//    delete[] inventory[i];
//    inventory[i] = nullptr;
//  }
//}

Room::Room() {
   name = "a wall";
   description = "It's a wall.";
   doorDescription = "";
   locked = true;
   inventory = {};
   key = wall;
   exits = {};
   events = {};
   characters = {};
}

Room::Room(std::string a, std::string b, std::string c, bool d, Inventory e,
           keyItem f, std::vector<Room*> g, std::vector<Events> h,
           std::vector<Character> i){
             name = a;
             description = b;
             doorDescription = c;
             locked = d;
             inventory = e;
             key = f;
             exits = g;
             events = h;
             characters = i;
}

bool Room::setLock(bool A) {
   return locked = A;
}

bool Room::hasExit(std::string A) {

   for (auto x : exits)
   {
      if (x->name == A)
	 return true;
   }
   return false;
}

bool Room::getLocked() {
return locked;
}

void Room::getExit() {
   for (auto x : exits)
      std::cout << x->doorDescription;Room R3("Desert", "It looks like it hasn't rained here in years.", "You see a door with a sign that says 'Water required'", true, {}, claw, {}, {}, {});
}

void Room::setExit(std::vector<Room*> A)
{
  exits.insert(exits.begin(), A.begin(), A.end());
}

std::string Room::getName() {
return name;
}
