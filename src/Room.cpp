

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


std::string Room::getExit() {
  std::string allDoorDesc;
  for (int i = 0; i < exits.size(); i++){
      if (i == 0 && exits[i]->getDoorDesc() != ""){
        allDoorDesc += "There is a ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " in front of you. ";
      }
      else if (i == 1 && exits[i]->getDoorDesc() != ""){
        allDoorDesc += "There is a ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " to your right. ";
      }
      else if (i == 3 && exits[i]->getDoorDesc() != ""){
        allDoorDesc += "There is a ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " behind you. ";
      }
      else if (i == 4 && exits[i]->getDoorDesc() != ""){
        allDoorDesc += "There is a ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " to your left. ";
      }

      //allDoorDesc += exits[i]->getDoorDesc();//Room R3("Desert", "It looks like it hasn't rained here in years.", "You see a door with a sign that says 'Water required'", true, {}, claw, {}, {}, {});
  }
      return allDoorDesc;

}

void Room::setExit(std::vector<Room*> A)
{
  exits.insert(exits.begin(), A.begin(), A.end());
}

std::string Room::getName() {
return name;
}

std::string Room::getDoorDesc(){
return doorDescription;}
