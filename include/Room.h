/**
 * CPSC 2720 Fall 2019
 * @authors Austen Oviatt, Lambee Mangal, Troy Hatchard, Sarah Ren
*/
#ifndef ROOM_H
#define ROOM_H
#include "KeyID.h"
#include "Inventory.h"
#include "Character.h"
#include <vector>

//nicole made suggestion to include Events in Room

class Room
{
  public:
   /**
    * Default room constructor
    */
  Room(): {}

  /**
  * Room constructor
  */
   Room::Room(string name, string description, string doorDescription, bool locked,
	      Inventory inventory, keyItem key, std::vector<Room*> exits,
	      std::vector<Events> events, std::vector<Character> character)

   /**
    * Default room destructor
    */
   ~Room();

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
    * @param bool Whether room will be locked or not
    * @return lock state of room
    */
   bool setLock(bool lockedState);

   /**
    * checks whether an exit exists
    * @param string the room name we are checking for
    * @return does the room connect to desired room
    */
   bool hasExit(string desiredRoom);

   /**
    * Lists all rooms attached to current room
    * @return room on other side of exit
    */
   Room getExit();

   /**
   * The name of the room
   */
   string name;

   /**
   * Description of the room
   */
   string description;

   /**
    * Description of the doorway leading into the room
    */
   string doorDescription;

  private:
   /**
    * The key that opens the room
    */
   KeyItem key;

   std::vector<Room*> exits;


   /**
    * State of any events that occur in a room
    */
    std::vector<Events> events;

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
