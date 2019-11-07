/**
 * CPSC 2720 Fall 2019
 * Authors Austen Oviatt, Lambee Mangal, Troy Hatchard, Sarah Ren
*/

#include "KeyID.h"
#include "Inventory.h"

//nicole made suggestion to include Events in Room

class Room
{
public:
  Room(Coordinate c, Inventory inventory, bool isLocked, KeyID keys): {}

  /**
  * Return the list of item currently in the room
  */
  Inventory getInventory();

  /**
  * Get the corresponding key ID that opens the room
  */
  KeyID getKeyID();

  /**
  * Return the locked status of the room
  */
  bool getLocked();

  /**
  * Change the locked status of the room
  */
  void setLocked();


private:
  /**
  * The key that opens the room
  */
  KeyID Keys;

  /**
  * status of whether room is currently locked
  */
  bool isLocked;

  /**
  * Inventory of the room
  */
  Inventory inventory;



};
