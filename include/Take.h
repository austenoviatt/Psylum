#ifndef TAKE_H
#define TAKE_H

#include "Player.h"

#include <string>
#include <vector>

class Take {
 public:
  Take();
  ~Take() {}

  void take(Item I, Player* P);

  void increaseRoom(Player* P);

  void increaseOther(Item I, Player* P);

 private:

};


#endif //TAKE_H
