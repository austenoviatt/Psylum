/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */
using namespace std;

#include "Inventory.h"
#include "Player.h"
<<<<<<< HEAD
Player::Player() {
  currentRoom = {};
  inventory = {};

}
Player::Player(Room* currentRoom, Inventory inventory) : currentRoom{ currentRoom }, inventory {inventory} {
=======

Player::Player(){
currentRoom = {};
inventory = {};
roomCount = 0;
}

Player::Player(Room* currentRoom, Inventory inventory, int roomCount) : currentRoom{ currentRoom }, inventory {inventory}, roomCount{ roomCount } {
>>>>>>> abf7186e3ddf297ad5551ddc525b15d5a5af231d

}

	/**
	 * changes the room the player is in
	 */
void Player::moveToRoom(Room* nextRoom) {
	currentRoom = nextRoom;
	roomCount++;
}

/**
	* how many rooms the player has entered
	* @return int number of rooms visited
	*/
	int Player::getRoomCount() {
	return roomCount;
	}

