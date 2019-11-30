#include <iostream>
#include <string>
#include "Inventory.h"
#include "Item.h"
#include "KeyItem.h"
#include "gtest/gtest.h"



TEST(Inventory, addItem) {

  Item I("Magic Mushroom",
         "Will have hallucination when consumed, may die from overdose", "", true);
  Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", "");
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", "");

  Inventory v;
  v.addItem(I);
  v.addItem(I2);


  EXPECT_EQ(I.getName(), v.getItems()[0].getName());
  EXPECT_EQ(I2.getName(), v.getItems()[1].getName());
  EXPECT_NE(I3.getName(), v.getItems()[0].getName());
}
/*
TEST(Inventory, removeItem)
{
      Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", "");
      Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", "");
      Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", "");
 //     keyItem claw;

      Inventory v;
      v.addItem(I);
      v.addItem(I2);
//      v.addItem(claw);
std::cout << "HELP" << std::endl;
      EXPECT_TRUE(v.removeItem(I));
      std::cout << "HELP1" << std::endl;
      EXPECT_FALSE(v.removeItem(I));
      std::cout << "HELP2" << std::endl;
      EXPECT_FALSE(v.removeItem(I3));
      std::cout << "HELP3" << std::endl;
      EXPECT_TRUE(v.removeItem(I2));
      std::cout << "HELP4" << std::endl;
//      EXPECT_TRUE(v.removeItem(claw));

      v.addItem(I2);
std::cout << "HELP5" << std::endl;
      EXPECT_TRUE(v.removeItem(I2));
      std::cout << "HELP6" << std::endl;
}
*/
TEST(Inventory, hasItem) {
  Item I("Magic Mushroom",
         "Will have hallucination when consumed, may die from overdose", "");
  Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", "");
  Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", "");

  Inventory v;
  v.addItem(I);
  v.addItem(I2);

  EXPECT_TRUE(v.hasItem(I2));
  EXPECT_TRUE(v.hasItem(I));
  EXPECT_FALSE(v.hasItem(I3));

  v.removeItem(I2);
  v.addItem(I3);

  EXPECT_TRUE(v.hasItem(I3));
  EXPECT_FALSE(v.hasItem(I2));

  v.addItem(I2);

  EXPECT_TRUE(v.hasItem(I2));

}
