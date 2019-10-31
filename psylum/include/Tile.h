/*
* CPSC 2720 Fall 2019
* Copyright 2019 Castor of University of Lethbridge
*/

#ifndef Tile_H_INCLUDED
#define Tile_H_INCLUDED

#include "Coordinate.h"

class Tile {
 public:
  Tile(Coordinate c);

  virtual ~Tile() {}


  /**
  * @return Location of the Tile
  */
  Coordinate getCoordinate();

 protected:
  //void checkOutOfBounds(Coordinate c);

  Coordinate coordinate;
};

#endif // WIDGET_H_INCLUDED
