/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

/**
 * This class implements an inventory for the player and the rooms
 */
#include <vector>
#include "Item.h"

class Inventory {
 public:
  /**
   * Default constructor
   */
  Inventory();

  /**
   * Default destructor
   */
  virtual ~Inventory() {}

  /**
   * Checks to see if an item exists in the inventory
   * @return a bool of whether the item is in the inventory
   */

  bool hasItem(std::string s);

  /**
   * Adds an item to the inventory
   */
  void addItem(Item I);

  /**
   * Removes an item from the inventory
   */
  bool removeItem(Item I);

  bool removeItem(std::string s);

  /**
  * @return The item in the inventory
  */
  std::vector<Item> getItems();

  /**
  * @return The num of items in inventory
  */
  int getInvCount();

  std::vector<Item> items;
   int invCount = 0;

   Item findItem(std::string s);

   Item returnItem(std::string s);



 private:


};

#endif // INVENTORY_H

