#ifndef USE_H
#define USE_H

#include "Player.h"
#include "Item.h"

#include <string>
#include <vector>

class Use {
 public:
  Use();
  ~Use() {}

  void use(std::vector<std::string>, Player*);

 private:

  Item wolf;
  Item cabbage;
  Item goat;
  std::string itemName;
};


#endif //USE_H
