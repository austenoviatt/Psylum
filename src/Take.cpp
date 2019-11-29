#include "Take.h"
#include "Player.h"
#include "Item.h"
#include "Game.h"
#include "Inventory.h"

#include <iostream>

using namespace std;

Take::Take() {}

void Take::take(Item I, Player* P) {

      if (I.getName() == "crowbar") {
         increaseRoom(P);
      }
      else if (I.getName() == "sedative") {
          increaseOther(I, P);
      }
      else if (I.getName() == "ratpoison") {
        increaseOther(I, P);
      }
      else if (I.getName() == "button2") {
        increaseOther(I, P);
      }
      else if (I.getName() == "roomkey") {
        increaseRoom(P);
      }
      else if (I.getName() == "labcoat") {
        increaseRoom(P);
      }
      else if (I.getName() == "worm") {
        increaseRoom(P);
      }
      else if (I.getName() == "button") {
        increaseOther(I, P);
      }
      else if (I.getName() == "magnet") {
        increaseOther(I, P);
      }




}

void Take::increaseRoom(Player* P) {
  P->currentRoom->increaseRoomState();
}

void Take::increaseOther(Item I, Player* P) {
  if (I.getName() == "sedative") {
    for (uint i = 0; i < P->allInv.items.size(); i++) {
      if (P->allInv.items[i].getName() == "box") {
        P->allInv.items[i].increaseItemState();
      }
    }
  }
  else if (I.getName() == "ratpoison") {
    for (uint i = 0; i < P->allInv.items.size(); i++) {
      if (P->allInv.items[i].getName() == "shelf") {
        P->allInv.items[i].increaseItemState();
      }
    }
  }
  else if (I.getName() == "button2") {
    for (int i = 0; i < P->allInv.items.size(); i++) {
      if (P->allInv.items[i].getName() == "bag") {
        P->allInv.items[i].increaseItemState();
      }
    }
  }
  else if (I.getName() == "button") {
    for (int i = 0; i < P->allInv.items.size(); i++) {
      if (P->allInv.items[i].getName() == "machine") {
        P->allInv.items[i].increaseItemState();
      }
    }
  }
  else if (I.getName() == "magnet") {
    for (int i = 0; i < P->allInv.items.size(); i++) {
      if (P->allInv.items[i].getName() == "fridge") {
        P->allInv.items[i].increaseItemState();
      }
    }
  }





}
