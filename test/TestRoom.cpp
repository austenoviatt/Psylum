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

  Room R;
  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, I, noKey, {}, {}, {});
  Room R3("Desert", "It looks like it hasn't rained here in years.", "You see a door with a sign that says 'Water required'", true, I, claw, {}, {}, {});

  EXPECT_FALSE(R.getLocked());
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

  Room R;
  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, {}, noKey, {}, {}, {});
  Room R3("Desert", "It looks like it hasn't rained here in years.", "You see a door with a sign that says 'Water required'", true, {}, claw, {}, {}, {});

  std::vector<Room*> R2Exit = {&R, &R3};
  std::vector<Room*> R3Exit = {&R, &R2};

  R2.setExit(R2Exit);
  R3.setExit(R3Exit);

  EXPECT_TRUE(R2.hasExit("Desert"));
  EXPECT_TRUE(R2.hasExit("DEFAULT ROOM NAME"));
  EXPECT_FALSE(R.hasExit("Forest"));
  EXPECT_TRUE(R3.hasExit("Forest"));

}

TEST(TestRoom, testInventory) {
  std::cout << 1;
  Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
  std::cout << 2;
  Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
  std::cout << 3;
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);
  std::cout << 4;
  Inventory v;
  std::cout << 5;
  v.addItem(I);
  std::cout << 6;
  v.addItem(I2);



  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, v, noKey, {}, {}, {});
  std::cout << "after";
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

  Events A("Tree Riddle", "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch", 0);
  Events B("Quest for bait", "I need bait to catch my toilet fish!", 2);
  std::string nameA = "Tree Riddle";
  std::string nameB = "Quest for bait";
  std::string descA = "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch";
  std::string descB = "I need bait to catch my toilet fish!";

  std::vector<Events> E = {A, B};


  Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, {}, noKey, {}, E, {});

    EXPECT_EQ(nameA, R2.events[0].getName());
    EXPECT_EQ(nameB, R2.events[1].getName());
    EXPECT_NE(nameA, R2.events[1].getName());

    EXPECT_EQ(descA, R2.events[0].getDesc());
    EXPECT_EQ(descB, R2.events[1].getDesc());

    EXPECT_EQ(0, R2.events[0].getStage());
    EXPECT_EQ(2, R2.events[1].getStage());

    R2.events[0].increaseStageCounter();
    R2.events[1].increaseStageCounter();

    EXPECT_EQ(1, R2.events[0].getStage());
    EXPECT_EQ(3, R2.events[1].getStage());

}

TEST(TestRoom, Character){

    Character C2("Char2", "Douglas", "Doug is bald", true, 0, "Talk to me baby");
    Character C3("Char3", "JaMarcus", "JaMarcus is the dopest dead dude ever", false, 2, "No thanks!");

    std::vector<Character> CC = {C2, C3};

    Room R2("Forest", "It's a huge forest!", "You see a door with a big tree symbol etched into it.", false, {}, noKey, {}, {}, CC);
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
