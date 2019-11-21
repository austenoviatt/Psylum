/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#ifndef CHARACTER_H
#define CHARACTER_H

/**
 * This class is for NPC characters
 */

#include <string>
#include "Inventory.h"

class Character {
 public:
  /**
   * Default constructor for Character
   */
  Character();

  /**
  * Constructor for Character
  * @param string Character ID
  * @param string character name
  * @param string description
  * @param bool whether character is alive or not
  * @param int event stage for character
  */
  Character(std::string, std::string, std::string, bool, int, std::string);

  /**
   * Default destructor
   */
  ~Character() {}

  /**
   * This is the dialogue options for the character
   */
  void talk(std::string charaID);

  /**
  * returns the character ID
  * @return string character ID
  */
  std::string getID();

  /**
    * @return the name of the Character
    */
  std::string getName();

  /**
    * @return the description of the Character
    */
  std::string getDescription();

  /**
  * returns event counter
  * @return int event counter
  */
  int getEventCounter();

  /**
  * @return the alive status of the Character
  */
  bool getIsAlive();

  /**
  * set the alive status of the character to died
  */
  void killChara();

  /**
  * move the conversation of the character forward by increasing the eventCounter by 1
  */
  void increaseEventCounter();

  /**
  * determine if the character is still alive
  */
  bool isAlive;


 private:
  std::string charaID;
  std::string name;
  std::string description;
  int eventCounter;
  std::string dialogue;

};
#endif //CHARACTER_H
