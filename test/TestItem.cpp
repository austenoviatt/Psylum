#include <iostream>
#include <string>
#include "Item.h"
#include "gtest/gtest.h"


TEST(Item, name) {
  std::string IName = "Magic Mushroom";
  Item I("Magic Mushroom",
         "Will have hallucination when consumed, may die from overdose", "");
  Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", "", true);
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", "", true);

  EXPECT_EQ(IName, I.getName());
  EXPECT_EQ("Lab Coat", I2.getName());
  EXPECT_NE(IName, I2.getName());
}
/*
TEST(Item, pickupable)
{
  Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
  Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);

  EXPECT_TRUE(I.isFixed());
  EXPECT_FALSE(I3.isFixed());
}
*/
TEST(Item, description) {
  std::string I3Name = "THIS ITEM DOESN'T EXIST, IT IS A DECOY";
  Item I("Magic Mushroom",
         "Will have hallucination when consumed, may die from overdose", "");
  Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", "");
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", "");

  EXPECT_EQ("Normal looking lab coat, stolen from the lab", I2.getItemDesc());
  EXPECT_EQ(I3Name, I3.getItemDesc());
  EXPECT_NE(I.getItemDesc(), I2.getItemDesc());
}
