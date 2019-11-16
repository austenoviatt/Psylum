#include <iostream>
#include <string>
#include "Inventory.h"
#include "Item.h"
#include "gtest/gtest.h"


using namespace std;
	TEST(Inventory, addItem)
	{

			// TODO: Your test code here
			Item I("Magic Mushroom", "Will have hallucination when consumed, may die from overdose", true);
			Item I2("Lab Coat", "Normal looking lab coat, stolen from the lab", true);
			Item I3("DECOY ITEM!!", "THIS ITEM DOESN'T EXIST, IT IS A DECOY", false);

      cout << 1;
			Inventory v;
			cout << 2;
			v.addItem(I);
			cout << 3;
			v.addItem(I2);
      cout << 4;

			EXPECT_EQ(I.getName(), v.getItems()[0].getName());
			cout << 5;
			EXPECT_FALSE(v.removeItem(I3));
			cout <<6;
			//EXPECT_THROW(v.removeItem(I3), item_not_found);
		}


