/**
 * CPSC 2720 Fall 2019
 * @author Troy Hatchard
 * copyright Castor - University of Lethbridge
*/

#ifndef LOADSAVE_H
#define LOADSAVE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Item.h"
#include "Character.h"
#include "Room.h"
#include "Events.h"

class LoadSave {
 public:
  LoadSave();
  virtual ~LoadSave();

  /**
  * Loads a game from the specified csv file
  * @param fileName the name of the file the save game is saved to
  */
void loadGame(std::string filename, std::vector<Item> &, std::vector<Room> &,
           std::vector<Character> &, std::vector<Events> &);

  /**
  * Saves a game to the specified csv file
  * @param fileName the name of the save file being loaded
  */
  void saveGame(std::string filename);

 protected:

 private:
};

#endif // LOADSAVE_H
