/**
 * CPSC 2720 Fall 2019
 * @author Troy Hatchard
 * copyright Castor - University of Lethbridge
*/

#include "gtest/gtest.h"
#include "LoadSave.h"

TEST(LoadSave, testLoad) {
  std::cout << "hello test!";
  LoadSave ls;
  std::vector<Item> itemsVector;
  std::vector<Room> roomsVector;
  std::vector<Character> charactersVector;
  std::vector<Events> eventsVector;
  std::string filename = "saves/saveTester.csv";
  ls.loadGame(filename, &itemsVector, &roomsVector, &charactersVector, &eventsVector);
  std::cout << "The item name: " << itemsVector.size();
  //EXPECT_EQ("ratpoisons", itemsVector[0].getName());



}
