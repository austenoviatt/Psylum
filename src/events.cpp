/**
 * Castor, 2019
 * @author Austen Oviatt
 * @date November 15, 2019
 */

 #include "Events.h"

 Events::Events(std::string a, std::string b, uint c){
   name = a;
   eventDescription = b;
   stage = c;
 }

 Events::~Events(){}

 std::string Events::getName(){
 return name;
 }

 std::string Events::getDesc(){
 return eventDescription;
 }

 uint Events::getStage(){
 return stage;
 }

 void Events::increaseStageCounter(){
 ++stage;
 }
