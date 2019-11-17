#include <iostream>
#include <string>
#include "Inventory.h"
#include "Item.h"
#include "gtest/gtest.h"



	TEST(Inventory, addItem)
	{

			Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
			Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
			Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);

			Inventory v;
			v.addItem(I);
			v.addItem(I2);


			EXPECT_EQ(I.getName(), v.getItems()[0].getName());
      EXPECT_EQ(I2.getName(), v.getItems()[1].getName());
			EXPECT_NE(I3.getName(), v.getItems()[0].getName());
		}

TEST(Inventory, removeItem)
{
      Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
			Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
			Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);

			Inventory v;
			v.addItem(I);
			v.addItem(I2);

			EXPECT_TRUE(v.removeItem(I));
			EXPECT_FALSE(v.removeItem(I));
			EXPECT_FALSE(v.removeItem(I3));
			EXPECT_TRUE(v.removeItem(I2));

			v.addItem(I2);

			EXPECT_TRUE(v.removeItem(I2));
}

TEST(Inventory, hasItem)
{
      Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
			Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
			Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);

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
