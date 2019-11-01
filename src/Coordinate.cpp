/*
* CPSC 2720 Fall 2019
* Copyright 2019 Castor of University of Lethbridge
*/
#include <sstream>
#include <string>
#include <iostream>
#include <Coordinate.h>

bool Coordinate::operator==(const Coordinate& c) const {
  if (c.x == x && c.y == y && c.z == z) {
    return true;
  } else {
    return false;
  }
}

bool Coordinate::operator!=(const Coordinate& c) const {
  if (c.x != x || c.y != y || c.z != z) {
    return true;
  } else {
    return false;
  }
}

std::ostream& operator<<(std::ostream& os, const Coordinate& c) {
  os << "[" << c.x << "," << c.y << "," << c.z << "]";
  return os;
}



