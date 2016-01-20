/** \file demolcg.cpp
 * Example on hot to use the Linear Congurential Generator
 *
 * MIT licensed (See LICENSE file being part of the repository)
 * Copyright (c) 2016 Oliver Merkel
 * All rights reserved.
 *
 * @author Oliver Merkel, <Merkel(dot)Oliver(at)web(dot)de>
 *
 */
#include "lcg.h"
#include <iostream>
#include <iomanip>

int main(int argc, char * argv[]) {
  int seed = 1;
  LinearCongurentialGenerator lcg;
  lcg.setSeed(seed);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      std::cout << std::setw(10) << lcg.getInt() << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}

