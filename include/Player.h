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
	 * changes the room the player is in
	 */
	void moveToRoom(Room* nextRoom);

	/**
	* returns how many times player has changed rooms
	* @return room count
	*/
	int getRoomCount();

  Room* currentRoom;
private:

int roomCount;


};

#endif // PLAYER_H
