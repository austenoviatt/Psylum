#include "Take.h"
#include "Player.h"
#include "Item.h"
#include "Game.h"
#include "Inventory.h"

#include <iostream>

using namespace std;

Take::Take() {}

void Take::take(Item I, Player* P) {

      if (I.getName() == "wolf") {
          increaseItself(I, P);
      }
      else if (I.getName() == "sedative") {
          increaseOther(I, P);
      }
}

void Take::increaseItself(Item I, Player* P) {
  for (int i = 0; i < P->allInv.items.size(); i++) {
    if (I.getName() == P->allInv.items[i].getName()) {
      P->allInv.items[i].increaseItemState();
      //cout << P->allInv.items[i].getItemState() << endl;
      return;
    }
  }
}

void Take::increaseOther(Item I, Player* P) {
  if (I.getName() == "sedative") {
    for (int i = 0; i < P->allInv.items.size(); i++) {
      if (P->allInv.items[i].getName() == "box") {
        P->allInv.items[i].increaseItemState();
      }
    }
  }


}
