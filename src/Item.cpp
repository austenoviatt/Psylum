/**
 * @author Troy Hatchard
 * @author Lambee Mangal
 * @author Austen Oviatt
 * @author Sarah Ren
 * @date November 13, 2019
 */

#include <string>
#include "Item.h"


using namespace std;

Item::Item(std::string name, std::string description, std::string niceName,
           bool fixed, int eventCounter): name{ name }, description{ description },
  niceName{ niceName }, fixed{ fixed }, eventCounter{eventCounter} {

}

string Item::getName() {
  return name;
}

bool Item::getFixed() {
  return fixed;
}

std::string Item::getItemDesc() {
  return description;
}

std::string Item::getNiceName() {
  return niceName;
}

/**
  * increase the event status of the item by one
  */
void Item::increaseEventCounter() {
  eventCounter = eventCounter + 1;
}

int Item::getEventCounter() {
  return eventCounter;
}

