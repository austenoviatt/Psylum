/**
 * CPSC 2720 Fall 2019
 * @author Austen Oviatt
 * copyright Castor University of Lethbridge
*/

#include "gtest/gtest.h"
#include "Character.h"

TEST(Character, getID)
{
  Character C;
  Character C2("Char2", "Douglas", "Doug is bald", true, 0, "Talk to me baby");
  Character C3("Char3", "JaMarcus", "JaMarcus is the dopest dead dude ever", false, 2, "No thanks!");

  EXPECT_EQ("Char2", C2.getID());
  EXPECT_EQ("DEFAULT ID", C.getID());
  EXPECT_NE(C2.getID(), C3.getID());
}

TEST(Character, getName)
{
  Character C;
  Character C2("Char2", "Douglas", "Doug is bald", true, 0, "Talk to me baby");
  Character C3("Char3", "JaMarcus", "JaMarcus is the dopest dead dude ever", false, 2, "No thanks!");

  EXPECT_EQ("JaMarcus", C3.getName());
  EXPECT_EQ("DEFAULT NPC NAME", C.getName());
  EXPECT_NE(C.getName(), C3.getName());
}

TEST(Character, getDescription)
{
    Character C;
  Character C2("Char2", "Douglas", "Doug is bald", true, 0, "Talk to me baby");
  Character C3("Char3", "JaMarcus", "JaMarcus is the dopest dead dude ever", false, 2, "No thanks!");

EXPECT_EQ("Doug is bald", C2.getDescription());
EXPECT_EQ("DEFAULT NPC DESCRIPTION", C.getDescription());
EXPECT_NE(C3.getDescription(), C.getDescription());
}

TEST(Character, isAliveORKill)
{
  Character C;
  Character C2("Char2", "Douglas", "Doug is bald", true, 0, "Talk to me baby");
  Character C3("Char3", "JaMarcus", "JaMarcus is the dopest dead dude ever", false, 2, "No thanks!");

  EXPECT_TRUE(C.getIsAlive());
  EXPECT_FALSE(C3.getIsAlive());
  EXPECT_TRUE(C2.getIsAlive());

  C.killChara();
  C2.killChara();
  C3.killChara();

  EXPECT_FALSE(C.getIsAlive());
  EXPECT_FALSE(C2.getIsAlive());
  EXPECT_FALSE(C3.getIsAlive());
}

TEST(Character, eventCounterANDCounterIncrease)
{
  Character C;
    Character C2("Char2", "Douglas", "Doug is bald", true, 0, "Talk to me baby");
    Character C3("Char3", "JaMarcus", "JaMarcus is the dopest dead dude ever", false, 2, "No thanks!");

  EXPECT_EQ(0, C.getEventCounter());
  EXPECT_EQ(0, C2.getEventCounter());
  EXPECT_EQ(2, C3.getEventCounter());

  C.increaseEventCounter();
  C3.increaseEventCounter();

  EXPECT_EQ(1, C.getEventCounter());
  EXPECT_NE(1, C2.getEventCounter());
  EXPECT_EQ(3, C3.getEventCounter());
}
