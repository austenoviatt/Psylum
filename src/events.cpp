/**
 * Castor, 2019
 * @author Austen Oviatt
 * @date November 15, 2019
 */

 #include "Events.h"

 Events::Events(std::string a, std::string b, unsigned int c){
   name = a;
   eventDescription = b;
   eventCounter = c;
 }

 Events::~Events(){}

 std::string Events::getName(){
 return name;
 }

 std::string Events::getDesc(){
 return eventDescription;
 }

 unsigned int Events::getEventCounter() {
return eventCounter;
 }
