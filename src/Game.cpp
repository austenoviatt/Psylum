/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#include <string>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Player.h"
#include "Game.h"
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
      string input = userInput;
      //convert userInput into lowercase letters
      transform(input.begin(), input.end(), input.begin(), ::tolower);

      //separate the input by space and store into vector
      std::vector<std::string> result;
      std::istringstream iss(input);
      for(std::string input; iss >> input; )
        result.push_back(input);

      std::string firstWord = result[0];

      //clean up unnecessary word
      for (int i = 0; i < result.size(); i++) {
        if (result[i] == "with" || result[i] == "to" || result[i] == "at" || result[i] == "the" || result[i] == "on" || result[i] == "door") {
          result.erase(result.begin() + i);
        }
      }

      //compare the verb with verb vector
      for (int i = 0; i < command.size(); i++) {
        for (int j = 0; j < command[i].size(); j++) {
            if (firstWord == command[i][j]) {
              //found the command, return value of set of command
              switch(i) {
              case 0:
                go(result);
                break;
              case 1:
                look(result);
                break;
              case 2:
                take(result);
                break;
              case 3:
                use(result);
                break;
              case 4:
                talk(result);
                break;
              case 5:
                help(result);
                break;
              case 6:
                inventory(result);
                break;

              }
            }
        }
      }
      //did not find the corresponding command
      return "Input Invalid";

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

      for (int i = 0; i < currentRoom->exits.size(); i++) {
          if (currentRoom->exits[i]->getDoorDesc() == result[1]) {
            if (currentRoom->exits[i]->getLocked() == false) {
              player.moveToRoom(currentRoom->exits[i]);
              return currentRoom->getDoorDesc();
            }
            else if (currentRoom->exits[i]->getLocked() == true) {
              return "the room is locked";
            }
          }
      }
      if (result[1] == "forward" || "front" && currentRoom->exits[0]->getName() != "a wall"){
          if (currentRoom->exits[0]->getLocked() == false) {
              player.moveToRoom(currentRoom->exits[0]);
              return currentRoom->getDoorDesc();
          }
          else if (currentRoom->exits[0]->getLocked() == true) {
              return "the room is locked";
          }
      }


      else if (result[1] == "right" && currentRoom->exits[1]->getName() != "a wall") {
          if (currentRoom->exits[1]->getLocked() == false) {
              player.moveToRoom(currentRoom->exits[1]);
              return currentRoom->getDoorDesc();
          }
          else if (currentRoom->exits[1]->getLocked() == true) {
              return "the room is locked";
          }

      }
      else if (result[1] == "backward" || "back" || "behind" && currentRoom->exits[2]->getName() != "a wall") {
          if (currentRoom->exits[2]->getLocked() == false) {
              player.moveToRoom(currentRoom->exits[2]);
              return currentRoom->getDoorDesc();
          }
          else if (currentRoom->exits[2]->getLocked() == true) {
              return "the room is locked";

          }
      }
      else if (result[1] == "right" && currentRoom->exits[3]->getName() != "a wall") {
          if (currentRoom->exits[3]->getLocked() == false) {
              player.moveToRoom(currentRoom->exits[3]);
              return currentRoom->getDoorDesc();
          }
          else if (currentRoom->exits[3]->getLocked() == true) {
              return "the room is locked";

          }
      }


   }

   /**
    * prints the list of actions in case the player gets stuck
    * @return a string explaining what happened
    */
   string Game::help(vector<string> result) {
      int inputSize = result.size();
      if (inputSize == 1) {
        //pop the help page
      }
      else if (inputSize == 2) {
        if (result[1] == "me") {
           //pop the help page
        }
        else {
          return "Input Invalid";
        }
      }
      else {
        return "Input Invalid";
      }
   }

   /**
    * prints all items in players inventory
    * @return a string explaining what happened
    */
   string Game::inventory(vector<string> result) {
      if (player.inventory.getInvCount() != 0) {
          std::cout << "In your inventory you have: " << "\n";
        for (int i = 0; i < player.inventory.getInvCount(); i++) {

        std::cout<< player.inventory.getItems()[i].getName() << ", ";
      }
      std::cout << "\n";
      }
      else {
        std::cout << "Your inventory is empty." << "\n";
      }


   }

   /**
    * prints out description of a room or item or NPC
    * @return a string explaining what happened
    */
   string Game::look(vector<string> result) {
      int inputSize = result.size();
      string lookType;
      //grab player's current location
      Room* currentRoom = player.currentRoom;
      //process the second word, what type of word?


      if (inputSize == 1) {
        return currentRoom->description + "\n" + currentRoom->getDoorDesc();
      }
      else if (inputSize == 2) {
        //index 1 is important here
        if (result[1] == "around" || "room") {
          return currentRoom->description + "\n" + currentRoom->getDoorDesc();
        }
        else if (result[1] == "inventory") {
          return inventory(result);
        }
        //looping through item on player
        for (int i = 0; i < player.inventory.items.size(); i++) {
          if (result[1] == player.inventory.getItems()[i].getName()) {
            return player.inventory.getItems()[i].getItemDesc();
          }
        }
        //looping through item in room
        for (int i = 0; i < currentRoom->inventory.items.size(); i++) {
          if (result[1] == currentRoom->inventory.getItems()[i].getName()) {
            return currentRoom->inventory.getItems()[i].getItemDesc();
          }
        }

        //looping through the npc in the room
        for (int i = 0; i < currentRoom->characters.size(); i++) {
          if (result[1] == currentRoom->characters[i].getName()) {
            return currentRoom->characters[i].getDescription();
          }
        }
      }
      else {
        return "Input Invalid";
      }
      return "Input Invalid";
   }

   /**
    * add an item to players inventory
    * @return a string explaining what happened
    */
   string Game::take(vector<string> result) {
      //grab player's current location
      Room* currentRoom = player.currentRoom;

      for (int i = 0; i < currentRoom->inventory.items.size();i++) {
        if (result[1] == currentRoom->inventory.items[i].getName()) {
         //item found, pickup item, remove item from room inventory and add it to player inventory
         string output = currentRoom->inventory.items[i].getName();
         player.inventory.addItem(currentRoom->inventory.items[i]);
         currentRoom->inventory.removeItem(currentRoom->inventory.items[i]);
          return "You picked up " + output + " and put it into your pocket.";
        }
      }
      return "Input Invalid";
   }

   /**
    * initiate dialogue options with an NPC
    * @return a string explaining what happened
    */
   string Game::talk(vector<string> result) {
      //grab player's current location
      Room* currentRoom = player.currentRoom;

      for (int i = 0; i < currentRoom->characters.size(); i++) {
        if (result[1] == currentRoom->characters[i].getName()) {
          //npc found
          return "talk to " + currentRoom->characters[i].getName();
        }
      }
      return "Input Invalid";

   }

    /**
    * use an item inside the inventory
    * @return a string explaining what happened
    */
   string Game::use(vector<string> result) {

   }

