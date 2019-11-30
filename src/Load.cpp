#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Game.h"
#include "Player.h"
#include "Load.h"
using namespace std;

Load::Load() {}

void Load::load(Player* P) {

  ifstream myfile;
  ifstream myfile2;
  string line;
  myfile.open ("saveItemPlayer.txt");

  if (myfile.is_open())
  {

    while ( getline (myfile,line) )
    {

      string input;

      //break line into vector
      std::istringstream ss(line);

      std::string token;
      vector<string> result;


      while (std::getline(ss, token, ' ')) {
        result.push_back(token);
      }


      for (int i = 0; i < P->allInv.getItems().size(); i++) {
          if (P->allInv.items[i].getName() == result[0]) {
              uint num = stoi(result[1]);
            P->allInv.items[i].setItemState(num);
          }

      }
    }
    myfile.close();

  }

  //this is for player own inventory
myfile2.open ("saveInventoryPlayer.txt");

if (myfile2.is_open())
  {

    while ( getline (myfile2,line) )
    {

      string input;

      //break line into vector
      std::istringstream ss(line);

      std::string token;
      vector<string> result;


      while (std::getline(ss, token, ' ')) {
        result.push_back(token);
      }
      //remove all items off of player
      for (int i = 0; i < P->inventory.getItems().size(); i++) {
        P->inventory.removeItem(P->inventory.items[i]);
      }

      //add items into player
      P->inventory.addItem(P->allInv.returnItem(result[0]));
      uint num = stoi(result[1]);
      //set item count
      int n = P->inventory.getItems().size();
      P->inventory.items[n - 1].setItemState(num);


    }


  }

 myfile2.close();

}
