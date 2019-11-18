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

/**
* Processes user input into game commands
* @return string of command the program can understand
*/
string Game::processCommand(string userInput) {
  std::string returnStatement;
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
  for (int i = 0; i < result.size(); i++) {
    if (result[i] == "with" || result[i] == "to" || result[i] == "at"
        || result[i] == "the" || result[i] == "on" || result[i] == "door") {
      result.erase(result.begin() + i);
    }
  }
  //firstWord = result[1];
  //compare the verb with verb vector
  for (int i = 0; i < command.size(); i++) {
    for (int j = 0; j < command[i].size(); j++) {
      if (firstWord == command[i][j]) {
        //found the command, return value of set of command
        switch (i) {
        case 0:
          return go(result);
          break;
        case 1:
          return look(result);
          break;
        case 2:
          return take(result);
          break;
        case 3:
          return use(result);
          break;
        case 4:
          std::cout << "talk!!!!!!!!!";
          return talk(result);
          break;
        case 5:
          return help(result);
          break;
        case 6:
          return inventory(result);
          break;

        }
      }
    }
  }
  //did not find the corresponding command
  returnStatement = strcat("Input Invalid", "\n");
  return returnStatement;

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
string Game::go(vector<string> result) {
  //grab player's current location
  Room* currentRoom = player.currentRoom;
  std::string returnStatement;

  for (int i = 0; i < currentRoom->exits.size(); i++) {
    if (currentRoom->exits[i]->getDoorDesc() == result[1]) {
      if (currentRoom->exits[i]->getLocked() == false) {
        player.moveToRoom(currentRoom->exits[i]);

        std::stringstream ss;
        ss << currentRoom->getDoorDesc() << "\n";
        returnStatement = ss.str();
        return returnStatement;
      } else if (currentRoom->exits[i]->getLocked() == true) {
        return "the room is locked\n";
      }
    }
  }
  if (result[1] == "forward" || "front"
      && currentRoom->exits[0]->getName() != "a wall") {
    if (currentRoom->exits[0]->getLocked() == false) {
      player.moveToRoom(currentRoom->exits[0]);

      std::stringstream ss;
      ss << currentRoom->getDoorDesc() << "\n";
      returnStatement = ss.str();
      return returnStatement;
    } else if (currentRoom->exits[0]->getLocked() == true) {
      return "the room is locked\n";
    }
  } else if (result[1] == "right"
             && currentRoom->exits[1]->getName() != "a wall") {
    if (currentRoom->exits[1]->getLocked() == false) {
      player.moveToRoom(currentRoom->exits[1]);

      std::stringstream ss;
      ss << currentRoom->getDoorDesc() << "\n";
      returnStatement = ss.str();
      return returnStatement;
    } else if (currentRoom->exits[1]->getLocked() == true) {
      return "the room is locked\n";
    }

  } else if (result[1] == "backward" || "back" || "behind"
             && currentRoom->exits[2]->getName() != "a wall") {
    if (currentRoom->exits[2]->getLocked() == false) {
      player.moveToRoom(currentRoom->exits[2]);

      std::stringstream ss;
      ss << currentRoom->getDoorDesc() << "\n";
      returnStatement = ss.str();
      return returnStatement;
    } else if (currentRoom->exits[2]->getLocked() == true) {
      return "the room is locked\n";
    }
  } else if (result[1] == "right"
             && currentRoom->exits[3]->getName() != "a wall") {
    if (currentRoom->exits[3]->getLocked() == false) {
      player.moveToRoom(currentRoom->exits[3]);

      std::stringstream ss;
      ss << currentRoom->getDoorDesc() << "\n";
      returnStatement = ss.str();
      return returnStatement;
    } else if (currentRoom->exits[3]->getLocked() == true) {
      return "the room is locked\n";
    }
  }
  return "Input Invalid\n";
}
/**
 * prints the list of actions in case the player gets stuck
 * @return a string explaining what happened
 */
string Game::help(vector<string> result) {
  int inputSize = result.size();
  std::string returnStatement;
  if (inputSize == 1) {
    return displayHelp();
  } else if (inputSize == 2) {
    if (result[1] == "me") {
      return displayHelp();
    } else {
      return "Input Invalid\n";
    }
  } else {
    return "Input Invalid\n";
  }
  return "Input Invalid\n";
}

/**
 * prints all items in players inventory
 * @return a string explaining what happened
 */
string Game::inventory(vector<string> result) {
  std::string returnStatement;
  if (player.inventory.getInvCount() != 0) {
    std::cout << "In your inventory you have: " << "\n";
    for (int i = 0; i < player.inventory.getInvCount(); i++) {

      std::cout<< player.inventory.getItems()[i].getName() + ", ";
    }
    std::cout << "\n";
  } else {
    return "Your inventory is empty.\n";
  }
}

/**
 * prints out description of a room or item or NPC
 * @return a string explaining what happened
 */
string Game::look(vector<string> result) {
  std::string returnStatement;
  int inputSize = result.size();

  //grab player's current location
  Room* currentRoom = player.currentRoom;

  if (inputSize == 1) {
    return currentRoom->description + "\n" + currentRoom->getDoorDesc() + "\n";
  } else if (inputSize == 2) {
    //index 1 is important here
    if (result[1] == "around" || "room") {
      return currentRoom->description + "\n" + currentRoom->getDoorDesc() + "\n";
    } else if (result[1] == "inventory") {
      return inventory(result);
    }
    //looping through item on player
    for (int i = 0; i < player.inventory.items.size(); i++) {
      if (result[1] == player.inventory.getItems()[i].getName()) {
        return player.inventory.getItems()[i].getItemDesc() + "\n";
      }
    }
    //looping through item in room
    for (int i = 0; i < currentRoom->inventory.items.size(); i++) {
      if (result[1] == currentRoom->inventory.getItems()[i].getName()) {
        return currentRoom->inventory.getItems()[i].getItemDesc() + "\n";;
      }
    }

    //looping through the npc in the room
    for (int i = 0; i < currentRoom->characters.size(); i++) {
      if (result[1] == currentRoom->characters[i].getName()) {
        return currentRoom->characters[i].getDescription() + "\n";;
      }
    }
  }
  //concat two item name and see if there is a match
  else if (inputSize == 3) {
    result[1] = result[1] + result[2];
    //erase the second item name
    result.erase(result.begin() + 2);
    look(result);
  } else {
    return "Input Invalid\n";
  }
  return "Input Invalid\n";
}

/**
 * add an item to players inventory
 * @return a string explaining what happened
 */
string Game::take(vector<string> result) {
  std::string returnStatement;
  int inputSize = result.size();
  //grab player's current location
  Room* currentRoom = player.currentRoom;
  if (inputSize == 2) {
    for (int i = 0; i < currentRoom->inventory.items.size(); i++) {
      if (result[1] == currentRoom->inventory.items[i].getName()) {
        //item found, pickup item, remove item from room inventory and add it to player inventory
        string output = currentRoom->inventory.items[i].getName();

        player.inventory.addItem(currentRoom->inventory.items[i]);
        currentRoom->inventory.removeItem(currentRoom->inventory.items[i]);

        std::stringstream ss;
        ss << "You picked up " << output << " and put it into your pocket." << "\n";
        returnStatement = ss.str();
        return returnStatement;
      }
    }
  }
  //concat two item name and see if there is a match
  else if (inputSize == 3) {
    result[1] = result[1] + result[2];
    //erase the second item name
    result.erase(result.begin() + 2);
    take(result);
  }
  return "Input Invalid\n";
}

/**
 * initiate dialogue options with an NPC
 * @return a string explaining what happened
 */
string Game::talk(vector<string> result) {
  std::string returnStatement;
  //std::cout << "ok so far";
  //grab player's current location
  Room* currentRoom = player.currentRoom;

  for (int i = 0; i < currentRoom->characters.size(); i++) {
    if (result[1] == currentRoom->characters[i].getName()) {
      //npc found, pass the charaID to the talk function under character class
      Character chara = currentRoom->characters[i];
      //currentRoom->characters[i].talk(currentRoom->characters[i].getID());

      //check whether the character is alive or not
      if (chara.isAlive == false) {
        std::cout << chara.getName() << " is dead.";
      } else { //character is alive, decide which character are we talking to
        if (chara.getID() == "snitch") {
          std::cout << "found snitch";
        } else if (chara.getID() == "toiletFisher") {
          std::cout << "found toilet fisher";
        }
      }

      /*
      std::stringstream ss;
      ss << "talk to " << currentRoom->characters[i].getName() << "\n";
      returnStatement = ss.str();
      return returnStatement;
      */
    }
  }
  //npc not found
  return "Input Invalid\n";
}

/**
* use an item inside the inventory
* @return a string explaining what happened
*/
string Game::use(vector<string> result) {
  std::string returnStatement;
  int inputSize = result.size();

  //return 0 for now because use() is not available.

  if (inputSize == 2) {
    for (int i= 0; i < player.inventory.getInvCount(); i++) {
      if (result[1] == player.inventory.getItems()[i].getName()) {
        return 0;
        //return player.inventory.getItems()[i].use(result, &player);
      }
    }
  } else if (inputSize >= 3) {
    for (int i= 0; i < player.inventory.getInvCount(); i++) {
      if (result[1] == player.inventory.getItems()[i].getName()) {
        return 0;
        //return player.inventory.getItems()[i].use(result);
      }
    }
    for (int i= 0; i < player.inventory.getInvCount(); i++) {
      if (result[2] == player.inventory.getItems()[i].getName()) {
        return 0;
        //return player.inventory.getItems()[i].use(result);
      }
    }
    result[1] = result[1] + result[2];
    //erase the second item name
    result.erase(result.begin() + 2);
    //use(result);
  }
  return "Input Invalid\n";
}

string Game::displayHelp() {
  std::stringstream ss;
  ss << "HELP PAGE" << "\n" << "\n"
     << "Available Commands:" << "\n"
     << "Move around: go forward, go right, go left, go back OR go red door, go blue door……"
     << "\n\n"
     << "Look around: look, look <npc>" << "\n\n"
     << "Items: look <Item>, take <Item>, give <Item>, use <Item>, use <Item1> with <Item2>, use <Item> on <npc>, add <Item1> to <Item2>"
     << "\n\n"
     << "Talk to npc: talk <npc>" << "\n\n"
     << "Inventory: inventory, inv, i" << "\n\n";

  return ss.str();

}

