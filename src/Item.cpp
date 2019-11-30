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
           bool fixed, int itemState) : name{ name }, description{ description },
  niceName{ niceName }, fixed{ fixed }, itemState{itemState} {

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

void Item::setItemDesc(std::string s){
description = s;
}

std::string Item::getNiceName() {
  return niceName;
}

void Item::increaseItemState() {
  itemState = itemState + 1;
}

void Item::decreaseItemState() {
  itemState = itemState - 1;
}

unsigned int Item::getItemState() {
  return itemState;
}

void Item::setItemState(int i) {
  itemState = i;
}

