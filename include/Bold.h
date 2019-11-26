#ifndef Bold_H
#define Bold_H

#include <string>
#include "Events.h"
#include "Room.h"
#include "Player.h"

class Bold {

  static std::string stringBold (std::string s) {
    return "\e[1m" + s + "\e[0m";
  }






};

#endif //BOLD_H
