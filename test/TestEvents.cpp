/**
 * CPSC 2720 Fall 2019
 * @author Austen Oviatt
 * copyright Castor University of Lethbridge
*/

#include "gtest/gtest.h"
#include "Events.h"


TEST(Events, getName) {

  Events A("Tree Riddle",
           "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch",
           0);
  Events B("Quest for bait", "I need bait to catch my toilet fish!", 0);
  std::string nameA = "Tree Riddle";
  std::string nameB = "Quest for bait";
  std::string descA =
    "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch";
  std::string descB = "I need bait to catch my toilet fish!";

  EXPECT_EQ(nameA, A.getName());
  EXPECT_EQ(nameB, B.getName());
  EXPECT_NE(nameA, B.getName());
}

TEST(Events, getDesc) {

  Events A("Tree Riddle",
           "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch",
           0);
  Events B("Quest for bait", "I need bait to catch my toilet fish!", 0);
  std::string nameA = "Tree Riddle";
  std::string nameB = "Quest for bait";
  std::string descA =
    "As you walk into the room, a gnarled tree beckons you toward it with a finger-like branch";
  std::string descB = "I need bait to catch my toilet fish!";

  EXPECT_EQ(descA, A.getDesc());
  EXPECT_EQ(descB, B.getDesc());
  EXPECT_NE(descA, B.getDesc());
}
