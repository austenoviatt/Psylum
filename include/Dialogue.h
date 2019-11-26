#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>
#include "Events.h"
#include "Room.h"
#include "Player.h"

class Dialogue {
 public:
  Dialogue();

  ~Dialogue() {}

  void talk(Character *c, Player P);


 private:


};

#endif //CHARACTER_H
