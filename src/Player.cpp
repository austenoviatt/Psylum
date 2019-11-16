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

Player::Player(Room* currentRoom, Inventory inventory) : currentRoom{ currentRoom }, inventory {inventory} {

}

	/**
	 * changes the room the player is in
	 */
void Player::moveToRoom(Room* nextRoom) {
	currentRoom = nextRoom;
}

