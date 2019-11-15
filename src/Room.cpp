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
   string doorDescription = "DEFAULT DOOR DESCRIPTION";
   bool locked = false;
   inventory inv= nullptr;
   KeyItem key = 0;
   exits = nullptr;
   events = nullptr;
   characters = nullptr;
}

Room::Room(string a, string b, string c, bool d, std::vector<Inventory> e,
           keyItem f, std::vector<Room*> g, std::vector<Events> h,
           std::vector<Character> i){
             name = a;
             description = b;
	     doorDescription = c;
             locked = d;
             invnetory = e;
             keyItem = f;
             exits = g;
             events = h;
             characters = i;}
	     
}

bool Room::setLocked(bool A) {
   locked = A;
}

bool Room::hasExit(string A) {

   for (auto x : exits)
   {
      if (x.name == A)
	 return true;
   }
   return false;
}

Room Room::getExit() {
   for (auto x : exits)
      cout << x.doodDescription;
}
