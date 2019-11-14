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

class Character{
  public:
   /**
    * Default constructor
    * @param name the name of the character
    * @param descrpiction the character description
    * @param isAlive Whether the character is alive or not
    */
   character(string name = "DEFAULT NPC NAME", string description =
	     "DEFAULT NPC DESCRIPTION", bool isAlive = True);

   /**
    * Default destructor
    */
   virtual ~character();

   /**
    * This is the dialogue options for the character
    */
   void dialogue();

  private:
   string name;
   string description;
   bool isAlive;
};
#endif //CHARACTER_H
