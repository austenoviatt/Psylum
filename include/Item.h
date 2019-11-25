/**
 * @author Troy Hatchard, Lambee Mangal, Austen Oviatt, Sarah Ren
 * @date November 13, 2019
*/

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

/**
 * This class is for all items in the game
*/

#include <string>

class Item {
 public:
  /**
   * Default constructor
   * @param name the name of the new item being created
   * @param description the description of the item
   * @param pickupable whether the item is able to be picked up or not
   */
  Item(std::string name = "DEFAULT NAME", std::string description =
         "DEFAULT DESCRIPTION", std::string niceName = "NICE NAME", bool fixed = false, int itemState = 0);

  /**
   * Default destructor
   */
  virtual ~Item() {}

  /**
   * This defines how an item interacts with other items/the environment
   */
  //void use();

  /**
  * returns the name of the Item
   * @return the name of the Item
   */
  std::string getName();

  std::string getNiceName();

  /**
  *returns whether item is fixedratpo or not
  * @return can pickup or not
  */

  /**
  * returns description of item
  * @return Item description
  */
  std::string getItemDesc();

  bool getFixed();

  void increaseItemState();

  int getItemState();
 private:

  std::string name;
  std::string niceName;
  std::string description;
  bool fixed;
  int itemState;
};

#endif //ITEM_H


