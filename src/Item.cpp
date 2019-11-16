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

Item::Item(std::string name, std::string description, bool pickupable) : name{ name }, description{ description }, pickupable{ pickupable } {

}

string Item::getName() {
	return name;
}


//Usage unknown, will come back later
void Item::use() {


}







