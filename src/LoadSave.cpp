/**
 * CPSC 2720 Fall 2019
 * @author Troy Hatchard
 * copyright Castor - University of Lethbridge
*/

#include "LoadSave.h"
#include "Item.h"
#include "Room.h"

LoadSave::LoadSave()
{
  //ctor
}

LoadSave::~LoadSave()
{
  //dtor
}

/**
* Loads a game from the specified csv file
* @param fileName the name of the file the save game is saved to
*/
void LoadSave::loadGame(std::string filename, std::vector<Item>& itemsVector,
                        std::vector<Room>& roomsVector, std::vector<Character>& charactersVector,
                        std::vector<Events>& eventsVector) {

  std::ifstream saveFile;
  saveFile.open(filename);

  if(!saveFile.fail()) {

    std::string line, cell;
    std::vector<std::string> rowVec;
    std::string object;
    std::vector<Item> itemsVec;
    std::vector<Room> RoomsVec;
    bool skipHeader = false;

    while (!saveFile.eof()) {
      if (skipHeader) {
        std::string discard;
        getline(saveFile, discard);
        skipHeader = false;
      }
      getline(saveFile, line);
      std::stringstream s(line);
      rowVec.clear();

      while (s >> std::ws) {
        getline(s, cell, '|');
        rowVec.push_back(cell);
      }
      if (rowVec[0] == "*") {
        object = rowVec[1];
        skipHeader = true;
      } else {
        if (object == "Items") {

          Item tempItem(rowVec[0], rowVec[1], true);
          //std::cout << "The temp item name: " << tempItem.getName();
          itemsVector.push_back(tempItem);

        } else if (object == "Room") {

        }
      }




    }
  } else std::cout << "Error: File doesn't exist!";
}

/**
* Saves a game to the specified csv file
* @param fileName the name of the save file being loaded
*/
void LoadSave::saveGame(std::string filename) {

}