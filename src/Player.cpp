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

Player::Player() {
  currentRoom = {};
  inventory = {};
  roomCount = 0;
  isAlive = true;
}

Player::Player(Room* currentRoom, Inventory inventory,
               int roomCount, bool isAlive) : currentRoom{ currentRoom }, inventory {inventory}, roomCount{ roomCount }, isAlive {isAlive} {


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

