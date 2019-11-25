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
#include "mainMenu.h"

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

  mainMenu m;
  m.showMenu();
}

void Player::win() {
  cout << "Congratulations! You've have escaped the asylum! Now go and enjoy the fresh air and smell of freedom before you get 'drugged' back in!" << endl << endl;
  cout << "(press enter to go back to the main menu)" << endl << endl;
  string userInput;
  getline(cin, userInput);
  cout << endl;

  mainMenu m;
  m.showMenu();

}
