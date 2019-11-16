<<<<<<< HEAD
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

//Game::Game() {

//}

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
   string processCommand() {

   }

   /**
    * removes an item from an inventory
    * @return a string explaining what happened
    */
   string drop() {

   }

   /**
    * moves player to specified room
    * @return a string explaining what happened
    */
   string go() {

   }

   /**
    * prints the list of actions in case the player gets stuck
    * @return a string explaining what happened
    */
   string help() {

   }

   /**
    * prints all items in players inventory
    * @return a string explaining what happened
    */
   string Game::inventory() {

      for (int i = 0; i < player.inventory.getInvCount(); i++) {
        std::cout<< player.inventory.getItems()[i].getName() << " ";
      }
      std::cout << "\n";
   }

   /**
    * prints out description of a room or item or NPC
    * @return a string explaining what happened
    */
   string look() {

   }

   /**
    * add an item to players inventory
    * @return a string explaining what happened
    */
   string take() {

   }

   /**
    * initiate dialogue options with an NPC
    * @return a string explaining what happened
    */
   string talk() {

   }

