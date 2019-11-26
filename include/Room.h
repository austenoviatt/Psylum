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

class Room {
 public:
  /**
   * Default room constructor
   */
  Room();

  /**
  * Room constructor
  */
  Room(std::string, std::string, std::string, bool, Inventory, std::string,
       std::vector<Room*>, Events, std::vector<Character>);

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


  std::string getDoorDesc();

  /**
   * Lists all rooms attached to current room
   * @return room on other side of exit
   */
  std::string getExit();

  /**
  * Returns whether the door is locked or not
  * @return bool door locked is true or not
  */
  bool getLocked();

  /**
  * Returns the name of the room
  * @return string name of room
  */
  std::string getName();

  /**
  * Description of the room
  */
  std::string description;

  std::string getKey();

  int charaIndex(std::string c);

  int charaNum();

  /**
   * Inventory of the room
   */
  Inventory inventory;

  Events event;

  /**
   * Characters in the room
   */
  std::vector<Character> characters;
  std::vector<Room*> exits;
 private:
  /**
   * Description of the doorway leading into the room
   */
  std::string doorDescription;

  /**
   * The key that opens the room
   */
  std::string key;

  /**
   * The name of the room
   */
  std::string name;
};

#endif // ROOM_H
