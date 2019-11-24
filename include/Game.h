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

class Game {
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
  string processCommand(string userInput, Player P);

  void getUserInput(Player P);
  /**
   * removes an item from an inventory
   * @return a string explaining what happened
   */
  //string drop();

  /**
   * moves player to specified room
   * @return a string explaining what happened
   */
  void go(vector<string> result, Player P);

  /**
   * prints the list of actions in case the player gets stuck
   * @return a string explaining what happened
   */
  void help(vector<string> result, Player P);

  /**
   * prints all items in players inventory
   * @return a string explaining what happened
   */
  void inventory(Player P);

  /**
   * prints out description of a room or item or NPC
   * @return a string explaining what happened
   */
  void look(vector<string> result, Player P);

  /**
   * add an item to players inventory
   * @return a string explaining what happened
   */
  void take(vector<string> result, Player P);

  /**
   * initiate dialogue options with an NPC
   * @return a string explaining what happened
   */
  void talk(vector<string> result, Player P);

  /**
   * use an item inside the inventory
   * @return a string explaining what happened
   */
  void use(vector<string> result, Player P);

  /**
   * display a page of text to give player all the possible commands in the game
   */
  void displayHelp();

  void testLoadGame();

  /**
  * determine if the character is still alive
  */
  bool isAlive;

  string stringBold (std::string s);


 private:

  std::vector<Room> locations;
  std::vector<Item> items;
  std::vector<Character> characters;
  std::vector<string> result;
  std::vector<vector<string>> command {
    {"go"},
    {"look", "check", "inspect", "see"},
    {"take", "get", "grab"},
    {"use", "eat", "drink", "consume", "add"},
    {"talk", "speak"},
    {"help"},
    {"inventory", "inv", "i"},
  };
  Player player;

};

#endif // GAME_H
