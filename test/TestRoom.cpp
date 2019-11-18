/**
 * CPSC 2720 Fall 2019
 * @author Sarah Ren, Troy Hatchard, Austen Oviatt
 * copyright Castor University of Lethbridge
*/

#include "gtest/gtest.h"
#include "Room.h"
#include <vector>

TEST(TestRoom, TestAndSetLocked) {
  Inventory I = {};
  Events A("Tree Riddle", "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch", 1);
  Room R;
  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, I, noKey, {}, A, {});
  Room R3("Desert", "It looks like it hasn't rained here in years.", "You see a door with a sign that says 'Water required'", true, I, claw, {}, A, {});

  EXPECT_TRUE(R.getLocked());
  EXPECT_FALSE(R2.getLocked());
  EXPECT_TRUE(R3.getLocked());

  R.setLock(true);
  R2.setLock(false);
  R3.setLock(false);

  EXPECT_TRUE(R.getLocked());
  EXPECT_FALSE(R2.getLocked());
  EXPECT_FALSE(R3.getLocked());
}

TEST(TestRoom, HasExit) {
Events A("Tree Riddle", "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch", 0);

  Room NONE("NO DOOR", "", "", true, {}, keycard, {}, {}, {});
  Room R;
  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, {}, noKey, {}, A, {});
  Room R3("Desert", "It looks like it hasn't rained here in years.", "You see a door with a sign that says 'Water required'", true, {}, claw, {}, A, {});

  std::vector<Room*> R2Exit= {&R, &NONE, &NONE, &R3};
  std::vector<Room*> R3Exit = {&R, &R2};

  R2.setExit(R2Exit);
  R3.setExit(R3Exit);

  EXPECT_TRUE(R2.hasExit("Desert"));
  EXPECT_TRUE(R2.hasExit("a wall"));
  EXPECT_FALSE(R.hasExit("Forest"));
  EXPECT_TRUE(R3.hasExit("Forest"));

}

TEST(testRoom, testGetExit){
  Events A("Tree Riddle", "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch", 0);
  Room NONE("NO DOOR", "", "", true, {}, keycard, {}, A, {});
  Room R;
  Room R2("Forest", "It's a huge forest!", "red door", false, {}, noKey, {}, A, {});
  Room R3("Desert", "It looks like it hasn't rained here in years.", "green door", true, {}, claw, {}, A, {});

  std::vector<Room*> R2Exit= {&R, &NONE, &NONE, &R3};
  std::vector<Room*> R3Exit = {&R, &R2};
  std::vector<Room*> RExit = {&R2, &R, &R, &R3};

  R2.setExit(R2Exit);
  R3.setExit(R3Exit);
  R.setExit(RExit);

  //std::cout << R.getExit();

}
TEST(TestRoom, testInventory) {


  Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
  Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);

  Inventory v;
  v.addItem(I);
  v.addItem(I2);

  Events A("Tree Riddle", "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch", 0);

  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, v, noKey, {}, A, {});

 // std::cout << R2.inventory->getItems()[0].getName();

  EXPECT_TRUE(R2.inventory.hasItem(I));
  EXPECT_TRUE(R2.inventory.hasItem(I2));
  EXPECT_FALSE(R2.inventory.hasItem(I3));

  R2.inventory.addItem(I3);
  EXPECT_EQ(I3.getName(), R2.inventory.getItems()[2].getName());

  EXPECT_TRUE(R2.inventory.removeItem(I3));
  EXPECT_TRUE(R2.inventory.removeItem(I2));
  EXPECT_FALSE(R2.inventory.removeItem(I3));
  EXPECT_FALSE(v.hasItem(I3));

}

TEST(TestRoom, Events){

  Events A("Tree Riddle", "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch", 1);
  Events B("Quest for bait", "I need bait to catch my toilet fish!" , 1);
  std::string nameA = "Tree Riddle";
  std::string nameB = "Quest for bait";
  std::string descA = "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch";
  std::string descB = "I need bait to catch my toilet fish!";

  //EXPECT_EQ(nameA,E[0].getName());

  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, {}, noKey, {}, A, {});

    EXPECT_EQ(nameA, R2.event.getName());
    //EXPECT_EQ(nameB, R2.events[1].getName());
    //EXPECT_NE(nameA, R2.events[1].getName());

    //EXPECT_EQ(descA, R2.events[0].getDesc());
    //EXPECT_EQ(descB, R2.events[1].getDesc());

}
TEST(Room, Inventory){
  Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
  Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);
  Inventory v;
  v.addItem(I);
  v.addItem(I2);

  Events A("Tree Riddle", "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch", 0);

  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, v, noKey, {}, A, {});

 //std::cout << R2.inventory.getItems()[0].getName();

  EXPECT_TRUE(R2.inventory.hasItem(I));
  EXPECT_TRUE(R2.inventory.hasItem(I2));
  EXPECT_FALSE(R2.inventory.hasItem(I3));

  R2.inventory.addItem(I3);
  EXPECT_EQ(I3.getName(), R2.inventory.getItems()[2].getName());

  EXPECT_TRUE(R2.inventory.removeItem(I3));
  EXPECT_TRUE(R2.inventory.removeItem(I2));
  EXPECT_FALSE(R2.inventory.removeItem(I3));
  EXPECT_FALSE(v.hasItem(I3));

}

TEST(TestRoom, Character){

    Character C2("Char2", "Douglas", "Doug is bald", true, 0, "Talk to me baby");
    Character C3("Char3", "JaMarcus", "JaMarcus is the dopest dead dude ever", false, 2, "No thanks!");

    Events A("Tree Riddle", "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch", 0);
    std::vector<Character> CC = {C2, C3};

    Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, {}, noKey, {}, A, CC);
//    std::cout<< std::endl << C.getName() << std::endl << std::endl;
//    std::cout << R2.NPC.getName();

    EXPECT_EQ("Char2", R2.characters[0].getID());
    EXPECT_EQ("Douglas", R2.characters[0].getName());
    EXPECT_EQ("JaMarcus", R2.characters[1].getName());
    EXPECT_EQ("Doug is bald", R2.characters[0].getDescription());
    EXPECT_TRUE(R2.characters[0].getIsAlive());
    EXPECT_EQ(0, R2.characters[0].getEventCounter());
    R2.characters[0].increaseEventCounter();
    EXPECT_EQ(1, R2.characters[0].getEventCounter());
    R2.characters[0].killChara();
    EXPECT_FALSE(R2.characters[0].getIsAlive());

}
