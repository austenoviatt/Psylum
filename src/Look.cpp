#include "Look.h"
#include "Player.h"
#include "Item.h"
#include "Game.h"
#include "Inventory.h"

#include <iostream>
#include <sstream>>

using namespace std;

Look::Look() {}

void Look::look(Item I, Player P) {
  int itemStateCounter;
  /*
  need to add in a look for room too!!!!!!!!!!!!!!!!!



  */

  //find the item in the allInv vector
  for (int i = 0; i < P.allInv.items.size(); i++) {
    if (I.getName() == P.allInv.items[i].getName()) {
        //cout << P.allInv.items[i].getItemState() << endl;
      itemStateCounter = P.allInv.items[i].getItemState();
    }
  }
  string description = I.getItemDesc();

  //separate the input by space and store into vector
  std::istringstream ss(description);

  std::string token;
  vector<string> result;

  while (std::getline(ss, token, '|')) {
    result.push_back(token);
  }

  if (itemStateCounter == 0) {
    std::cout << result[0] << std::endl << endl;
  }
  else if (itemStateCounter == 1) {
    std::cout << result[1] << std::endl << endl;
  }
  else if (itemStateCounter == 2) {
    std::cout << result[2] << std::endl << endl;
  }
  else if (itemStateCounter == 3) {
    std::cout << result[3] << std::endl << endl;
  }
  else {
    return;
  }


}
