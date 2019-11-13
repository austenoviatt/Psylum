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
   /**
    * Default room constructor
    */
  Room(string name, string description, Room exits): {}

   /**
    * Default room destructor
    */
   virtual ~Room();
   
   /**
    * status of whether room is currently locked
    * @return locked state
    */
   bool locked;
   
   /**
    * All the items in the room
    */
   Inventory inventory;
   
   /**
    * The key required to unlock a room
    */
   KeyItem key;
   
   /**
    * Sets the locked status of the room
    * @return lock state of room
    */
   bool setLock();
   
   /**
    * checks whether an exit exists
    * @return does the room connect to desired room
    */
   bool hasExit();
   
   /**
    * sends player to room through exit
    * @return room on other side of exit
    */
   Room getExit();
   
   
  private:
   /**
    * The key that opens the room
    */
   KeyID Keys;
   
   /**
    * Inventory of the room
    */
   Inventory inventory;
   
   /**
    * Characters in the room
    */
   Character characters;
   
};

#endif // ROOM_H
