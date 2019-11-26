#include "gtest/gtest.h"
#include "Game.h"
#include "Player.h"
#include "Character.h"
#include "Room.h"
#include "Inventory.h"
#include "Item.h"
#include "Dialogue.h"

#include <vector>
#include <string>

using namespace std;

TEST(TestGame, processCommand) {
  Item I("magicmushroom",
         "Will have hallucination when consumed, may die from overdose", "", true);
  Item I2("labcoat", "Normal looking lab coat, stolen from the lab", "");
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", "");
  Item I4("ratpoison", "One sip will kill you", "");

  Inventory v;
  v.addItem(I);
  v.addItem(I2);

  Inventory n;
  n.addItem(I4);

  Character C3("snitch", "patient", "the snitch who will turn us in", true, 0,
               "Talk to me baby");
  Character C2("Char2", "Douglas", "Doug is bald", true, 0, "Talk to me baby");

  //std::cout << "HELP" << std::endl;
  Character C4("toiletFisher", "patient", "he will give us a fishing rod", true,
               0, "hello");
  //EXPECT_EQ("Char2", C2.getID());
  Room R2("Forest", "It's a huge forest!", "red door", false, v, noKey, {}, {}, {C3});
  Room R3("testRoom", "Is a test room", "fsss", false, n, noKey, {}, {}, {C2});

  //Player player(&R2, {}, 0);
  Game g;

  //EXPECT_EQ("snitch",g.talk(result));
//g.processCommand("talk patient yyy");

  //std:: cout << g.processCommand("");

}

TEST(TestGame, dialogue) {
  Dialogue d;
  //d.talk("patient2");
  //d.talk("forestspirit");
}





