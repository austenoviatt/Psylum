#ifndef USE_H
#define USE_H

#include "Player.h"

#include <string>
#include <vector>

class Use {
 public:
  Use();
  ~Use() {}

  void use(std::vector<std::string>, Player*);

 private:

  std::string itemName;
};


#endif //USE_H
