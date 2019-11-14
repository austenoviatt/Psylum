/*
* CPSC 2720 Fall 2019
* Copyright 2019 Castor of University of Lethbridge
*/

#include <iostream>
#include <string>
#include "Coordinate.h"
#include "Tile.h"

Tile::Tile(Coordinate c) : coordinate{c} {
}

Coordinate Tile::getCoordinate() {
  return coordinate;
}
