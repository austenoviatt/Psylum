/**
 * CPSC 2720 Fall 2019
 * @authors Austen Oviatt, Lambee Mangal, Troy Hatchard, Sarah Ren
*/
#ifndef ROOM_H
#define ROOM_H
#include "KeyItem.h"
#include "Inventory.h"
#include "Character.h"
#include "Events.h"
#include <vector>
#include <string>

//nicole made suggestion to include Events in Room

class Room
{
  public:
   /**
    * Default room constructor
    */
 Room();

  /**
  * Room constructor
  */
  Room(std::string, std::string, std::string, bool, Inventory*, keyItem,
       std::vector<Room*>, std::vector<Events>, std::vector<Character>);

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
    * Sets the locked status of the room
    * @param bool Whether room will be locked or not
    * @return lock state of room
    */
   bool setLock(bool lockedState);

   /**
   * sets exits for rooms
   * @param room* the rooms being added
   */
   void setExit(std::vector<Room*>);

   /**
    * checks whether an exit exists
    * @param string the room name we are checking for
    * @return does the room connect to desired room
    */
   bool hasExit(std::string desiredRoom);

   /**
    * Lists all rooms attached to current room
    * @return room on other side of exit
    */
   void getExit();

   /**
   * Returns whether the door is locked or not
   * @return bool door locked is true or not
   */
   bool getLocked();

   /**
   * The name of the room
   */
   std::string name;

   /**
   * Description of the room
   */
   std::string description;

   /**
    * Description of the doorway leading into the room
    */
   std::string doorDescription;

   /**
    * Inventory of the room
    */
   Inventory* inventory;

   /**
    * State of any events that occur in a room
    */
    std::vector<Events> events;

   /**
    * Characters in the room
    */
   std::vector<Character> characters;

  private:
   /**
    * The key that opens the room
    */
   keyItem key;



 std::vector<Room*> exits;




};

#endif // ROOM_H
