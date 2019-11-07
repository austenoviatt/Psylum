/**
 * CPSC 2720 Fall 2019
 * Authors Austen Oviatt, Lambee Mangal, Troy Hatchard, Sarah Ren
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>

/**
* Data structure to store the items contained within a room
* or held by a player
*/
class Inventory {
  public:
    /**
    * Initialize an empty Inventory
    */
    Inventory();

    /**
    * Initialize an inventory with a vector of items
    */
    Inventory(vector<Item> items);

    /**
    * @return a vector of the current items in the inventory
    */
    vector<Item> getItems();

    /**
    * Appends an item object to the end of the items vector
    */
    void addItem(Item item);

    /**
    * Removes an item from the items vector
    */
    void removeItem(Item item);

  private:
    /**
    * The list of items within the inventory
    */
    vector<Item> itemsList;

};

#endif
