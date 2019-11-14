#include <iostream>
#include <string>
#include "Inventory.h"
#include "Item.h"
#include "gtest/gtest.h"



	TEST(Inventory, addItem)
	{

			// TODO: Your test code here
			Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
			Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
			Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);

			Inventory v;
			v.addItem(I);
			v.addItem(I2);


			EXPECT_EQ(I.getName(), v.getItems()[0].getName());
			EXPECT_FALSE(v.removeItem(I3));
			//EXPECT_THROW(v.removeItem(I3), item_not_found);
		}


