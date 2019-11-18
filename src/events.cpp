/**
 * Castor, 2019
 * @author Austen Oviatt
 * @date November 15, 2019
 */

 #include "Events.h"

 Events::Events(std::string name, std::string eventDescription, int eventCounter) : name{name}, eventDescription{eventDescription}, eventCounter{eventCounter}{

 }

 Events::~Events(){}

 std::string Events::getName(){
 return name;
 }

 std::string Events::getDesc(){
 return eventDescription;
 }

int Events::getEventCounter() {
return eventCounter;
 }

 void Events::addEventCounter() {
 eventCounter++;
 }


