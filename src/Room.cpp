

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
   event = {};
   characters = {};
}

Room::Room(std::string a, std::string b, std::string c, bool d, Inventory e,
           keyItem f, std::vector<Room*> g, Events h,
           std::vector<Character> i){
             name = a;
             description = b;
             doorDescription = c;
             locked = d;
             inventory = e;
             key = f;
             exits = g;
             event = h;
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

      if (i == 0 && exits[i]->getDoorDesc() != "" || "elevator" || "hallway"){
        allDoorDesc += "There is a ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " door in front of you. ";
      }
      else if (i == 0 && exits[i]->getDoorDesc() == "elevator"){
        allDoorDesc += "The ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " is in front of you. ";
      }
      else if (i == 0 && exits[i]->getDoorDesc() == "hallway"){
        allDoorDesc += "The ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " is in front of you. ";
      }
      else if (i == 1 && exits[i]->getDoorDesc() != "" || "elevator" || "hallway"){
        allDoorDesc += "There is a ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " door to your right. ";
      }
      else if (i == 2 && exits[i]->getDoorDesc() != "" || "elevator" || "hallway"){
        allDoorDesc += "There is a ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " door behind you. ";
      }
      else if (i == 2 && exits[i]->getDoorDesc() == "elevator"){
        allDoorDesc += "The ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " is behind you. ";
      }
      else if (i == 2 && exits[i]->getDoorDesc() == "hallway"){
        allDoorDesc += "The ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " is behind you. ";
      }
      else if (i == 3 && exits[i]->getDoorDesc() != "" || "elevator" || "hallway"){
        allDoorDesc += "There is a ";
        allDoorDesc += exits[i]->getDoorDesc();
        allDoorDesc += " door to your left. ";
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
