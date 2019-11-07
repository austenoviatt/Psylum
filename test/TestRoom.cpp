/**
 * CPSC 2720 Fall 2019
 * Authors Austen Oviatt, Lambee Mangal, Troy Hatchard, Sarah Ren
*/

#include "Coordinate.h"
#include <sstream>
#include <string>
#include "gtest/gtest.h"

#include <Coordinate.h>
#include "KeyID.h"
#include "Inventory.h"

TEST(TestCoord, constructor_test_equal) {
  Coordinate c(2, 3, 3);
  Coordinate d(2, 3, 3);
  Coordinate e(7, 8, 3);

  //equal
  EXPECT_TRUE(c == d);
  EXPECT_FALSE(d == e);
}

TEST(TESTCoord, constructor_test_notEqual) {
  Coordinate c(2, 3, 3);
  Coordinate d(2, 3, 3);
  Coordinate e(7, 8, 3);

  //not equal
  EXPECT_TRUE(c != e);
  EXPECT_FALSE(c != d);

}

TEST(TestCoord, output_test) {
  Coordinate c(2, 3, 3);

  std::stringstream ss;
  ss << c;
  EXPECT_EQ("[2,3,3]", ss.str());
}


