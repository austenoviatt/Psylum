#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>

class Dialogue {
public:
Dialogue();

~Dialogue() {}
void talk(std::string chaID);


private:
std::string chaID;

};

#endif //CHARACTER_H
