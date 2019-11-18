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

/**
* This is the dialogue options for the character
*/
void Character::talk(std::string charaID) {
  if (isAlive == false) {
    std::cout << name << " is dead.";

  } else { //character is alive, decide which character are we talking to
    if (charaID == "snitch") {

    } else if (charaID == "toiletFisher") {

    } else if (charaID == "evilDoctor") {
      //first encounter, not wearing lab coat
      std::cout <<
                "Well, well, well. We got a little escapee here. GUARDS! Take him back to his cell!!!"
                << "\n";
      //first encounter, wearing lab coat
      std::cout << "You there! Are you a newbee here in the hospital?" << "\n";
      //option 1, tell him you are a new doctor
      std::cout <<
                "Ah, nice to see a new face here. Anyways, as you can see I'm a busy man, go make me a cup of coffee."
                << "\n";
      //this dialogue get's repeated over and over again, eventCounter at this point stays 0 until player brings him the coffee
      std::cout <<
                "Remember, I'm very picky when it comes to coffee, I need exactly 10g of sugar, 35ml of cream with 415ml of coffee, now hurry up!"
                << "\n";
      //gives him the normal coffee without poison, he asks you to give him another coffee, eventCounter stays 0 and repeat the above line
      std::cout << "This is some good coffee, now go make me another one!";
      //gives him the poison coffee, he drinks it, he then asks you to grab him a donut (the donut is not in the game, this is just for example purpose)
      //increase the eventCounter to 1 to repeat the below line over and over again until he gets his donut
      std::cout << "Enough coffee for now, I want donut, now hurry up!";
      //option 2, tell him you are a mental patient
      std::cout <<
                "Well, well, well. We got a little escapee here trying to dress up for Halloween. GUARDS! Take him back to his cell!!!"
                << "\n";
    } else if (charaID == "petOwner") {

    }
  }
}
