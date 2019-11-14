/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#ifndef PLAYER_H
#define PLAYER_H

/**

 * This class is the player class
 */

#include "Inventory.h"

class Player{
  public:
   /**
    * Default constructor
    */
   Player(Room currentRoom = startRoom, Inventory inventory = 0);

   /**
    * Default destructor
    */
   virtual ~Player();

   /**
    * Players inventory
    */
   Inventory inventory;

   /**
    * changes the room the player is in
    */
   moveToRoom();

  private:

   Room currentRoom;
};

#endif // PLAYER_H
