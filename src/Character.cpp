/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#include <string>
#include <vector>
#include <iostream>
#include "Character.h"
#include "Inventory.h"



Character::Character() {
  charaID = "DEFAULT ID";
  name = "DEFAULT NPC NAME";
  description = "DEFAULT NPC DESCRIPTION";
  isAlive = true;
  eventCounter = 0;
  dialogue = "DEFAULT DIALOGUE";
}
Character::Character(std::string a, std::string b, std::string c, bool d, int e,
                     std::string f) {
  charaID = a;
  name = b;
  description = c;
  isAlive = d;
  eventCounter = e;
  dialogue = f;
}

std::string Character::getID() {
  return charaID;
}

std::string Character::getName() {
  return name;
}

std::string Character::getDescription() {
  return description;
}

bool Character::getIsAlive() {
  return isAlive;
}

int Character::getEventCounter() {
  return eventCounter;
}

/**
* set the alive status of the character to died
*/
void Character::killChara() {
  isAlive = false;
}


/**
* move the conversation of the character forward by increasing the eventCounter by 1
*/
void Character::increaseEventCounter() {
  eventCounter = eventCounter + 1;
}

