#include "gtest/gtest.h"
#include "Game.h"
#include "Player.h"
#include "Character.h"
#include "Room.h"
#include "Inventory.h"
#include "Item.h"

#include <vector>
#include <string>

using namespace std;

TEST(TestGame, processCommand) {
  Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
  Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);
  Item I4("Rat Poison", "One sip will kill you", true);

  Inventory v;
  v.addItem(I);
  v.addItem(I2);

  Inventory n;
  n.addItem(I4);
  //Game g;
  //Character C2;
  //std::cout << "HELP" << std::endl;
  //Character C;
  Character C3("snitch", "patient", "the snitch who will turn us in", true, 0, "Talk to me baby");
  Character C2("Char2", "Douglas", "Doug is bald", true, 0, "Talk to me baby");

  //std::cout << "HELP" << std::endl;
  Character C4("toiletFisher", "patient", "he will give us a fishing rod", true, 0, "hello");
  //EXPECT_EQ("Char2", C2.getID());
  Room R2("Forest", "It's a huge forest!", "red door", false, v, noKey, {}, {}, {C3});
  Room R3("testRoom", "Is a test room", "fsss", false, n, noKey, {}, {}, {C2});

  Player player(&R2, {}, 0);
  Game g;

  //EXPECT_EQ("snitch",g.talk(result));
//g.processCommand("talk patient yyy");
  std:: cout << g.processCommand("talk patient yyy");

}

//TEST(Character, getID) {
  //Character c;
//}

