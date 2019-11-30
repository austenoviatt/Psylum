#include <iostream>
#include <sstream>
#include <fstream>
#include "Game.h"
#include "Player.h"
#include "Save.h"
using namespace std;

Save::Save() {}

void Save::save(Player* P) {

  ofstream myfile;
  ofstream myfile2;
  myfile.open ("saveItemPlayer.txt");
  myfile2.open ("saveInventoryPlayer.txt");
  //this is for saving ALL items inventory
  for (int i = 0; i < P->allInv.getItems().size(); i++) {
    myfile << P->allInv.items[i].getName() << " " << P->allInv.items[i].getItemState() << "\n";
  }

  //saved item ok

  //save player inventory
  for (int i = 0; i < P->inventory.getItems().size(); i++) {
    myfile2 << P->inventory.items[i].getName() << " " << P->inventory.items[i].getItemState() << "\n";
  }

  cout << "reached here" << endl;

  myfile.close();
  myfile2.close();





}
