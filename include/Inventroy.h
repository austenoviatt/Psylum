/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#ifndef INVENTORY_H
#define INVENTORY_H

/**
 * This class implements an inventory for the player and the rooms
 */
#include <vector>
#include "Item.h"

class Inventroy{
  public:
   /**
    * Default constructor
    */
   Inventory();

   /**
    * Default destructor
    */
   virtual ~Inventory();

   /**
    * Checks to see if an item exists in the inventory
    * @return a bool of whether the item is in the inventory
    */
   bool hasItem();

   /**
    * Adds an item to the inventory
    */
   void addItem();

   /**
    * Removes an Item from the inventory
    */
   void removeItem();

  private:
   std::vector<Item> items;

};

#endif // INVENTORY_H
   
