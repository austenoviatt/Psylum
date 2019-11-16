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
		"DEFAULT DESCRIPTION", bool pickupable = false);

	/**
	 * Default destructor
	 */
	virtual ~Item() {}

	/**
	 * This defines how an item interacts with other items/the environment
	 */
	void use();

	/**
   * @return the name of the Item
	 Added by myself to make my code work
   */
	std::string getName();


private:

	std::string name;
	std::string description;
	bool pickupable;
};

#endif //ITEM_H


