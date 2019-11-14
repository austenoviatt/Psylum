/*
* CPSC 2720 Fall 2019
* Copyright 2019 Castor of University of Lethbridge
*/
#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

/**
  * Representation of a three-dimensional Cartisian coordinate.
  */
class Coordinate {
 public:
  Coordinate(unsigned int x = 0, unsigned int y = 0, unsigned int z = 0) :x{x}, y{y}, z{z} {}
  virtual ~Coordinate() {}

  /**
  * @return true if the x, y and z values of c are the same as those of the object, false otherwise.
  */
  bool operator==(const Coordinate& c) const;

  /**
  * @return true if the x, y and z values of c are different from those of the object, false otherwise.
  */
  bool operator!=(const Coordinate& c) const;

  /**
  * @return an output stream containing a representation of the coordinate in "[x,y,z]" format.
  */
  friend std::ostream& operator<<(std::ostream& os, const Coordinate& c);

  /** The x-coordinate */
  const unsigned int x;

  /** The y-coordinate */
  const unsigned int y;

  /** The z-coordinate */
  const unsigned int z;
};

#endif  // COORDINATE_H
