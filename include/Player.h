/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

/**
 * This class is the player class
 */

#include "Inventory.h"
#include "Room.h"

class Player {
 public:
  /**
   * Default constructor
   */
  Player();

  /**
  * Constructor
  */
  Player(Room* currentRoom, Inventory inventory, int roomCount);

  /**
   * Default destructor
   */
  virtual ~Player() {}

  /**
    * Players inventory
    */
  Inventory inventory;


  /**
   * changes the room the player is in, increments roomCount
   */
  void moveToRoom(Room* nextRoom);

  /**
  * how many rooms the player has entered
  * @return int number of rooms visited
  */
  int getRoomCount();


  Room* currentRoom;
 private:

  int roomCount;



};

#endif // PLAYER_H
