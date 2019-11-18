/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Inventory.h"
#include "Item.h"

Inventory::Inventory() {
}
/**
   * Checks to see if an item exists in the inventory
   * @param the item to be searched for
   * @return a bool of whether the item is in the inventory
   */
bool Inventory::hasItem(Item I) {
  bool ItemFound = false;
  // Iterate over all elements in Vector
  //store the name of the item
  std::string itemName = I.getName();

  //iterate all items in the inventory
  for (auto x : items) {
    //found the item
    if (x.getName() == itemName) {
      ItemFound = true;
      break;
    }
  }
  if (ItemFound)
    return true;
  else
    //did not find the item
    return false;
}

/**
 * Adds an item to the inventory
 * @param The item to be added
 */
void Inventory::addItem(Item I) {
  items.push_back(I);
  invCount++;
}

/**
 * Removes an Item from the inventory
 * @param the item to be removed
 */
bool Inventory::removeItem(Item I) {
  bool ItemFound = false;
  int indexTracker = 0;

  std::string ItemName = I.getName();

  for (auto x : items) {
    //found the item
    if (x.getName() == ItemName) {
      //change the status and delete the item from the inventory vector
      ItemFound = true;
      items.erase(items.begin() + indexTracker);
      invCount--;
      return true;
    }
    indexTracker++;
  }
  //did not find the item, deletion failed and throw an error message
  if (ItemFound == false) {
    return false;
  }

}

/**
* @return The items in the inventory
*/
std::vector<Item> Inventory::getItems() {
  return items;

}

/**
* @return The num of items in inventory
*/
int Inventory::getInvCount() {
  return invCount;
}



