/**
 * CPSC 2720 Fall 2019
 * Authors Austen Oviatt, Lambee Mangal, Troy Hatchard, Sarah Ren
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

#endif // Tile_H_INCLUDED
