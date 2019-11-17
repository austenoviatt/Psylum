/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#ifndef GAME_H
#define GAME_H

/**
 * This class implements all possible actions
 */
#include <string>
#include "Room.h"
#include "Player.h"

class Game{
  public:
   /**
    * Default constructor
    */
   Game();

   /**
    * Default destructor
    */
   virtual ~Game() {}

   /**
    * creates a new game at starting point
    */
   void create();

   /**
    * Saves game at current state and location
    * @param fileName the name of the file the save game is saved to
    */
   void saveGame(string fileName);

   /**
    * Loads game from a save file
    * @param fileName the name of the save file being loaded
    */
   void loadGame(string fileName);

   /**
    * Processes user input into game commands
    * @return string of command the program can understand
    */
    void processCommand(string userInput);

   /**
    * removes an item from an inventory
    * @return a string explaining what happened
    */
   //string drop();

   /**
    * moves player to specified room
    * @return a string explaining what happened
    */
   string go(vector<string> result);

   /**
    * prints the list of actions in case the player gets stuck
    * @return a string explaining what happened
    */
   string help(vector<string> result);

   /**
    * prints all items in players inventory
    * @return a string explaining what happened
    */
   string inventory(vector<string> result);

   /**
    * prints out description of a room or item or NPC
    * @return a string explaining what happened
    */
   string look(vector<string> result);

   /**
    * add an item to players inventory
    * @return a string explaining what happened
    */
   string take(vector<string> result);

   /**
    * initiate dialogue options with an NPC
    * @return a string explaining what happened
    */
   string talk(vector<string> result);

   /**
    * use an item inside the inventory
    * @return a string explaining what happened
    */
   string use(vector<string> result);

  private:

   std::vector<Room> locations;
   std::vector<Item> items;
   std::vector<string> result;
   std::vector<vector<string>> command {
     {"go"},
     {"look", "check", "inspect", "see"},
     {"take", "get", "grab"},
     {"use"},
     {"talk", "speak"},
     {"help"},
     {"inventory", "show"},
   };


   Player player;

};

#endif // GAME_H
