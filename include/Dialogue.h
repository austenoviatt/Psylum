#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>
#include "Events.h"
#include "Room.h"

class Dialogue {
public:
Dialogue();

~Dialogue() {}
void talk(std::string chaID);


private:
std::string chaID;

};

#endif //CHARACTER_H
