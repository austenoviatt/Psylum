/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Player.h"
#include "Game.h"
#include "Use.h"
#include "Dialogue.h"
#include<bits/stdc++.h>

Game::Game() {
}
/**
* creates a new game at starting point
*/
void create() {

}

/**
 * Saves game at current state and location
 * @param fileName the name of the file the save game is saved to
 */
void saveGame(string fileName) {

}

/**
 * Loads game from a save file
 * @param fileName the name of the save file being loaded
 */
void loadGame(string fileName) {

}

void Game::getUserInput(Player P) {
  std::string userInput;
  std::cout << "enter: ";
  getline(cin,userInput);
  std::cout << std::endl;
  processCommand(userInput, P);
}

void Game::testLoadGame() {

  Item I("magicmushroom", "Will have hallucination when consumed, may die from overdose", "magic mushroom", false);
  Item I2("labcoat", "Normal looking lab coat, stolen from the lab", "lab coat", false);
  Item I3("fridge", "Old rusty fridge", "fridge", true);
  Item I4("ratpoison", "testing to see if poison is in the room", "rat poison", false);
  Item I5("sedative", "has a label on it says it can knock out any person after injection", "sedative", false);

  Inventory playerInventory;
  Inventory roomInventory;
  Inventory room2Inventory;
  //std::cout << roomInventory.getInvCount() << std::endl;

  roomInventory.addItem(I);   //working good
  roomInventory.addItem(I2);  //working good
  roomInventory.addItem(I3);
  roomInventory.addItem(I4);
  room2Inventory.addItem(I5);


   //std::cout << playerInventory.getInvCount() << std::endl;

  std::cout << roomInventory.getItems()[0].getName()
            << " "
            << roomInventory.getItems()[1].getName()
            << " "
            << roomInventory.getItems()[2].getName()
            << std::endl;

  Events E("snitch chara counter"," ", 0);
  Events E2("greeted doctor"," ", 0);

  Character C("snitch", "patient", "sketchy looking patient who looks like she want's to help you", true, 0, " ");
  Character C2("dummy", "dummy", "dummy who looks at you but will never interact with you", false, 0, " ");

  //need work for now
  characters.push_back(C);
  characters.push_back(C2);

  std::cout << characters[0].getName()
            << " "
            << characters[1].getName()
            << std::endl;

  //std::cout << "reached before room create" << std::endl;
  Room R("testRoom", "There is a fridge on your left. On your right side, there is a patient who is looking at you. A dummy is placed in the center of the room",
         "red", false, roomInventory, " ", {}, E2, characters);
  //std::cout << "reached after room create" << std::endl;
  Room R2("testRoom2", "A hallway with flickering lights, you see scratch marks on the wall along the hallway, a whistling can be heard from the end of the hallway.",
          "hallway", false, room2Inventory, " ", {}, {}, {});

          //std::vector<Room*> exitR {{},{},R2,{}};// {R2};
          //std::vector<Room*> exitR2 {{}, {R}, {}, {}};// {R};

          std::vector<Room*> RExit {&R2};
          std::vector<Room*> R2Exit {&R};

          //std::cout << RExit[0]->getName() << " testing this one!"<< std::endl;

          //std::vector<Room*> RExit= {&R, &NONE, &NONE, &R3};
          //std::vector<Room*> R2Exit = {&R, &R2};
          //std::vector<Room*> R3Exit = {&R2, &R, &R, &R3};

          R.setExit(RExit);
          R2.setExit(R2Exit);

  std::cout << R.getName()
            << ", "
            << R.getDoorDesc()
            << ", "
            << R.getLocked()
            << ", "
            << R.inventory.getItems()[0].getName() << " " << R.inventory.getItems()[1].getName()
            << ", "
            << R.event.getName()
            << ", "
            << R.characters[0].getName() << " " << R.characters[1].getName()
            << ", "
            << R.exits[0]->getDoorDesc()
            << std::endl;

  Player P(&R, playerInventory, 0);

  bool playerIsAlive = true;

  while (playerIsAlive) {
    getUserInput(P);
  }

  //so far so good

}


/**
* Processes user input into game commands
* @return string of command the program can understand
*/
string Game::processCommand(string userInput, Player P) {

//  std::string returnStatement;
  string input = userInput;
  //convert userInput into lowercase letters
  transform(input.begin(), input.end(), input.begin(), ::tolower);

  //separate the input by space and store into vector
  std::istringstream ss(input);

  std::string token;
  vector<string> result;

  while (std::getline(ss, token, ' ')) {
    result.push_back(token);
  }
  //for (int i = 0; i < result.size(); i++){
  //  std::cout << result[i] << std::endl;
  //}

  std::string firstWord = result[0];

  //clean up unnecessary word
  int counter = 0;
  while (counter < result.size()) {
      if (result[counter] == "with" || result[counter] == "to" || result[counter] == "at" || result[counter] == "the" || result[counter] == "on" || result[counter] == "door") {
        result.erase(result.begin() + counter);
      }
      else {
        counter++;
      }
  }
  counter = 0;

  //compare the verb with verb vector
  for (uint i = 0; i < command.size(); i++) {
    for (uint j = 0; j < command[i].size(); j++) {
      if (firstWord == command[i][j]) {
        //found the command, return value of set of command
        switch (i) {
        case 0:
          //std::cout << "gooooo!!!!" << std::endl;
          go(result, P);
          break;
        case 1:
          //std::cout << "look!!!!!!!!" << std::endl;
          look(result, P);
          break;
        case 2:
          //std::cout << "take!!!!!!!!!" << std::endl;
          take(result, P);
          break;
        case 3:
          //std::cout << "useeeeeeeeee!!!!" << std::endl;
          use(result, P);
          break;
        case 4:
          //std::cout << "talk!!!!!!!!!" << std::endl;
          talk(result, P);
          break;
        case 5:
          //std::cout << "help!!!!!!!!!" << std::endl;
          help(result, P);
          break;
        case 6:
          //std::cout << "inventory!!!!!!" << std::endl;
          inventory(P);
          break;

        }
      }
    }
  }
  //did not find the corresponding command
  std::cout << "Input Invalid" << std::endl;
  getUserInput(P);

}

/**
 * removes an item from an inventory
 * @return a string explaining what happened
 */
//string Game::drop(vector<string> result) {

//}

/**
 * moves player to specified room
 * @return a string explaining what happened
 */
void Game::go(vector<string> result, Player P) {

  //travel using door name
  for (uint i = 0; i < P.currentRoom->exits.size(); i++) {
      if (P.currentRoom->exits[i]->getDoorDesc() == result[1]) {

      if (P.currentRoom->exits[i]->getLocked() == false) {
        P.moveToRoom(P.currentRoom->exits[i]);

        std::cout << P.currentRoom->description << std::endl;
        getUserInput(P);

      } else if (P.currentRoom->exits[i]->getLocked() == true) {
        std::cout << "the room is locked" << std::endl;
        getUserInput(P);
      }
    }
  }
  if ((result[1] == "forward" || "front" )
      && (P.currentRoom->exits[0]->getName() != "a wall")) {
    if (P.currentRoom->exits[0]->getLocked() == false) {
      P.moveToRoom(P.currentRoom->exits[0]);

      std::cout << P.currentRoom->description << std::endl;
      getUserInput(P);

    } else if (P.currentRoom->exits[0]->getLocked() == true) {
      std::cout << "the room is locked" << std::endl;
      getUserInput(P);
    }
  } else if (result[1] == "right" && P.currentRoom->exits[1]->getName() != "a wall") {
    if (P.currentRoom->exits[1]->getLocked() == false) {
      P.moveToRoom(P.currentRoom->exits[1]);

      std::cout << P.currentRoom->description << std::endl;
      getUserInput(P);

    } else if (P.currentRoom->exits[1]->getLocked() == true) {
      std::cout << "the room is locked" << std::endl;
      getUserInput(P);
    }

  } else if ((result[1] == "backward" || "back" || "behind") && (P.currentRoom->exits[2]->getName() != "a wall")) {
    if (P.currentRoom->exits[2]->getLocked() == false) {
      P.moveToRoom(P.currentRoom->exits[2]);

      std::cout << P.currentRoom->description << std::endl;
      getUserInput(P);

    } else if (P.currentRoom->exits[2]->getLocked() == true) {
      std::cout << "the room is locked" << std::endl;
      getUserInput(P);
    }
  } else if (result[1] == "right" && P.currentRoom->exits[3]->getName() != "a wall") {
    if (P.currentRoom->exits[3]->getLocked() == false) {
      P.moveToRoom(P.currentRoom->exits[3]);

      std::cout << P.currentRoom->description << std::endl;
      getUserInput(P);

    } else if (P.currentRoom->exits[3]->getLocked() == true) {
      std::cout << "the room is locked" << std::endl;
      getUserInput(P);
    }
  }
    std::cout << "Input Invalid" << std::endl;
    getUserInput(P);
}
/**
 * prints the list of actions in case the player gets stuck
 * @return a string explaining what happened
 */
void Game::help(vector<string> result, Player P) {
  int inputSize = result.size();
  std::string returnStatement;
  if (inputSize == 1) {
    displayHelp();
     getUserInput(P);
  } else if (inputSize == 2) {
    if (result[1] == "me") {
      displayHelp();
      getUserInput(P);
    } else {
      std::cout << "Input Invalid" << std::endl;
      getUserInput(P);
    }
  } else {
    std::cout << "Input Invalid" << std::endl;
      getUserInput(P);
  }
  std::cout << "Input Invalid" << std::endl;
      getUserInput(P);
}

/**
 * prints all items in players inventory
 * or else prints that players inventory is empty. a string explaining what happened
 */
void Game::inventory(Player P) {
  if (P.inventory.getItems().size() != 0) {
    std::cout << "In your inventory you have: " << std::endl;
    for (int i = 0; i < P.inventory.getItems().size(); i++) {
      std::cout<< P.inventory.getItems()[i].getNiceName();
      if ((i + 1) != P.inventory.getItems().size()) {
        std::cout << ", ";
      }
    }
    std::cout << endl;
    getUserInput(P);
  } else {
    std::cout << "Your inventory is empty." << std::endl;
    getUserInput(P);
  }
}

/**
 * prints out description of a room or item or NPC
 * @return a string explaining what happened
 */
void Game::look(vector<string> result, Player P) {
  int inputSize = result.size();

  if (inputSize == 1) {
      std::cout << P.currentRoom->description << std::endl;
      getUserInput(P);
  } else if (inputSize == 2) {
    //index 1 is important here
    if (result[1] == "around" || result[1] == "room") {
      std::cout << P.currentRoom->description << std::endl;
       getUserInput(P);
    } else if (result[1] == "inventory"|| result[1] == "i" || result[1] == "inv") {
      inventory(P);
    }
    //looping through item on player
    //for (uint i = 0; i < player.inventory.items.size(); i++) {
    //  if (result[1] == player.inventory.getItems()[i].getName()) {
        //return player.inventory.getItems()[i].getItemDesc() + "\n";
     // }
    //}
   //std::cout << R.inventory.getInvCount() << std::endl;
    //looping through item in room
    for (unsigned int i = 0; i < P.currentRoom->inventory.getItems().size(); i++) {
      if (result[1] == P.currentRoom->inventory.getItems()[i].getName()) {
        std::cout << P.currentRoom->inventory.getItems()[i].getItemDesc() << std::endl;
         getUserInput(P);
      }
    }

    //looping through the npc in the room
    for (unsigned int i = 0; i < P.currentRoom->characters.size(); i++) {
      if (result[1] == P.currentRoom->characters[i].getName()) {
        std::cout << P.currentRoom->characters[i].getDescription() << std::endl;
        getUserInput(P);
      }
    }
    std::cout << "Input Invalid" << std::endl;
    getUserInput(P);
  }
  //concat two item name and see if there is a match
  else if (inputSize == 3) {
    result[1] = result[1] + result[2];
    //std::cout << result[1] << std::endl;
    //erase the second item name
    result.erase(result.begin() + 2);
    look(result, P);
  } else {
    std::cout << "Input Invalid" << std::endl;
    getUserInput(P);
  }

}

/**
 * add an item to players inventory
 * @return a string explaining what happened
 */
void Game::take(vector<string> result, Player P) {
  //int inputSize = result.size();
  //grab player's current location

  if (result.size() == 2) {
    for (uint i = 0; i < P.currentRoom->inventory.items.size(); i++) {
      if (result[1] == P.currentRoom->inventory.items[i].getName()) {
        if (!P.currentRoom->inventory.items[i].getFixed()) {
          //item found, pickup item, remove item from room inventory and add it to player inventory
          string itemName = P.currentRoom->inventory.items[i].getNiceName();

          P.inventory.addItem(P.currentRoom->inventory.items[i]);
          P.currentRoom->inventory.removeItem(P.currentRoom->inventory.items[i]);

          std::cout << "You picked up " << itemName << " and put it into your pocket." << std::endl;
          getUserInput(P);

        } else
          std::cout << "You can't pick " << P.currentRoom->inventory.items[i].getNiceName() << " up." << std::endl;
          getUserInput(P);
      }
    }
  }
  //concat two item name and see if there is a match
  else if (result.size() == 3) {
    result[1] = result[1] + result[2];
    //erase the second item name
    result.erase(result.begin() + 2);
    take(result, P);
  }
    std::cout << "Input Invalid" << std::endl;
    getUserInput(P);

}

/**
 * initiate dialogue options with an NPC
 * @return a string explaining what happened
 */
void Game::talk(vector<string> result, Player P) {

  for (unsigned int i = 0; i < P.currentRoom->characters.size(); i++) {
    if (result[1] == P.currentRoom->characters[i].getName()) {
      //npc found, pass the charaID to the talk function under character class
      Character chara = P.currentRoom->characters[i];
      Dialogue d;

      //check whether the character is alive or not
      if (chara.isAlive == false) {
        std::cout << chara.getName() << " past out on the ground." << std::endl;
      } else { //character is alive, decide which character are we talking to
        d.talk(&P.currentRoom->characters[i]);
        std::cout << "talked to the patient" << std::endl;
        getUserInput(P);
      }

    }
  }
    //npc not found
    std::cout << "Input Invalid" << std::endl;
    getUserInput(P);
}

/**
* use an item inside the inventory
* @return a string explaining what happened
*/
void Game::use(vector<string> result, Player P) {
  std::string returnStatement;
  returnStatement =+ '\n';
  std::string invalid = "Input invalid.";
  invalid =+ '\n';
  int inputSize = result.size();

  //return 0 for now because use() is not available.

  if (inputSize == 2) {
    for (int i= 0; i < player.inventory.getInvCount(); i++) {
      if (result[1] == player.inventory.getItems()[i].getName()) {
        // player.inventory.getItems()[i].use(result, &player);
        //return returnStatement;
      }
    }
  } else if (inputSize >= 3) {
    for (int i= 0; i < player.inventory.getInvCount(); i++) {
      if (result[1] == player.inventory.getItems()[i].getName()) {
        //return returnStatement;
        //return player.inventory.getItems()[i].use(result);
      }
    }
    for (int i= 0; i < player.inventory.getInvCount(); i++) {
      if (result[2] == player.inventory.getItems()[i].getName()) {
        //return returnStatement;
        //return player.inventory.getItems()[i].use(result);
      }
    }
    result[1] = result[1] + result[2];
    //erase the second item name
    result.erase(result.begin() + 2);
    //use(result);
  }
  //return invalid;
}

void Game::displayHelp() {
  std::stringstream ss;
  ss << "HELP PAGE" << "\n" << "\n"
     << "Available Commands:" << "\n"
     << "Move around: go forward, go right, go left, go back OR go red door, go blue door……"
     << "\n\n"
     << "Look around: look, look <npc>" << "\n\n"
     << "Items: look <Item>, take <Item>, give <Item>, use <Item>, use <Item1> with <Item2>, use <Item> on <npc>, add <Item1> to <Item2>"
     << "\n\n"
     << "Talk to npc: talk <npc>" << "\n\n"
     << "Inventory: inventory, inv, i" << "\n";

  std::cout << ss.str() << std::endl;

}
