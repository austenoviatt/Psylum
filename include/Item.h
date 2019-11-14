/**
 * @author Troy Hatchard, Lambee Mangal, Austen Oviatt, Sarah Ren
 * @date November 13, 2019
*/

#ifndef ITEM_H
#define ITEM_H

/**
 * This class is for all items in the game
*/


#include <string>

class Item{
  public:
   /**
    * Default constructor
    * @param name the name of the new item being created
    * @param description the description of the item
    * @param pickupable whether the item is able to be picked up or not
    */   
   item(string name = "DEFAULT NAME", string description =
	"DEFAULT DESCRIPTION", bool pickupable = false);

   /**
    * Default destructor
    */
   virtual ~Item() {}

   /**
    * This defines how an item interacts with other items/the environment
    */
   void use();

  private:
   
   string name;
   string description;
   bool pickupable;
};

#endif //ITEM_H
