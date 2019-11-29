/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */
using namespace std;

#include <iostream>
#include "Inventory.h"
#include "Player.h"
#include "Game.h"



Player::Player() {
  currentRoom = {};
  inventory = {};
  roomCount = 0;
  isAlive = true;
  //allInv = {};
}

Player::Player(Room* currentRoom, Inventory inventory,
               int roomCount, bool isAlive, Inventory allInv) : currentRoom{ currentRoom }, inventory {inventory}, roomCount{ roomCount }, isAlive {isAlive}, allInv {allInv} {

}

/**
 * changes the room the player is in
 */
void Player::moveToRoom(Room* nextRoom) {
  if (nextRoom->getName() == "End of Game!") {
      win();
  }
  else if (nextRoom->getName() == "Sewer") {
    currentRoom->setLock(true);
  }
  else if (nextRoom->getName() == "Main Lobby"){
    std::cout<< "You're in the main lobby of the building. There's exit doors in the distance but you've been spotted by security! 'That's the patient who was last seen with the doctor!' They run over and grab you by the arm and roughly escort you back up to your room. They lock you up much more securely than before, there is no way to get out now. "
    << std::endl << std::endl;
    killPlayer();
  }
  else if (nextRoom->getName() == "Ice Room") {
    if (inventory.hasItem("magicmushroom") == false) {
      cout << "You tried everything you can, but you couldn't get out of the room, as you slowly froze to death, you can't stop wondering: Did you forgot to bring something with you along the way?" << endl << endl;
      killPlayer();
    }
    else {
      currentRoom->setLock(true);
    }
  }
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

bool Player::getIsAlive() {
  return isAlive;
}

void Player::killPlayer() {
  isAlive = false;
  cout << "GAME OVER (press enter to go back to the main menu)" << endl;
  string userInput;
  getline(cin, userInput);
  cout << endl;

}

void Player::win() {
  isAlive = false;
  cout << "Congratulations! You've have escaped the asylum! Now go and enjoy the fresh air and smell of freedom before you get 'drugged' back in!" << endl << endl;
  cout << "(press enter to go back to the main menu)" << endl << endl;
  string userInput;
  getline(cin, userInput);
  cout << endl;

}
