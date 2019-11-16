/**
 * CPSC 2720 Fall 2019
 * @author Austen Oviatt
 * copyright Castor University of Lethbridge
*/

#include "gtest/gtest.h"
#include "Player.h"

TEST(Player, Inventory){
  Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
  Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);

  Inventory v;
  v.addItem(I);
  v.addItem(I2);

  Inventory v2;
  v2.addItem(I3);

  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, v, noKey, {}, {}, {});

  Player P(&R2, v2, 0);

  EXPECT_TRUE(P.inventory.hasItem(I3));
  EXPECT_TRUE(P.inventory.removeItem(I3));
  EXPECT_FALSE(P.inventory.hasItem(I3));
  P.inventory.addItem(I2);
  EXPECT_EQ("Lab Coat", P.inventory.getItems()[0].getName());
}

TEST(Player, Room){

  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, {}, noKey, {}, {}, {});
  Room R3("Desert", "It looks like it hasn't rained here in years.", "You see a door with a sign that says 'Water required'", true, {}, claw, {}, {}, {});
  std::string nameR2 = "Forest";
  std::string nameR3 = "Desert";

  Player P(&R2, {}, 0);
  EXPECT_EQ(0, P.getRoomCount());
  EXPECT_EQ(nameR2, P.currentRoom->getName());
  P.moveToRoom(&R3);
  EXPECT_EQ(nameR3, P.currentRoom->getName());
  std::cout<<P.getRoomCount();
  EXPECT_EQ(1, P.getRoomCount());

}
