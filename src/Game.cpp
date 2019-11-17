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
   void Game::processCommand(string userInput) {
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

   }

   /**
    * removes an item from an inventory
    * @return a string explaining what happened
    */
   //string Game::drop() {

   //}

   /**
    * moves player to specified room
    * @return a string explaining what happened
    */
   string Game::go(vector<string> result) {

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

      for (int i = 0; i < player.inventory.getInvCount(); i++) {
        std::cout<< player.inventory.getItems()[i].getName() << " ";
      }
      std::cout << "\n";
   }

   /**
    * prints out description of a room or item or NPC
    * @return a string explaining what happened
    */
   string Game::look(vector<string> result) {
      int inputSize = result.size();
      //grab player's current location
      Room* currentRoom = player.currentRoom;

      //process the second word


      if (inputSize == 1) {
        return currentRoom->description + "\n" + currentRoom->doorDescription;
      }
      else if (inputSize == 2) {
        //index 1 is important here
        if (result[1] == "around") {
          return currentRoom->description + "\n" + currentRoom->doorDescription;
        }
        else if (result[1] == "inventory") {
          for (int i = 0; i < player.inventory.getInvCount(); i++) {
            std::cout<< player.inventory.getItems()[i].getName() << " ";
          }
          std::cout << "\n";
        }
        else {

        }
      }
      else {
        return "Input Invalid";
      }
   }

   /**
    * add an item to players inventory
    * @return a string explaining what happened
    */
   string Game::take(vector<string> result) {

   }

   /**
    * initiate dialogue options with an NPC
    * @return a string explaining what happened
    */
   string Game::talk(vector<string> result) {

   }

    /**
    * use an item inside the inventory
    * @return a string explaining what happened
    */
   string Game::use(vector<string> result) {

   }

