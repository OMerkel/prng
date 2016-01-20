/** \file lcg.cpp
 *
 * Implementation of a Linear Congurential Generator
 *
 * MIT licensed (See LICENSE file being part of the repository)
 * Copyright (c) 2016 Oliver Merkel
 * All rights reserved.
 *
 * @author Oliver Merkel, <Merkel(dot)Oliver(at)web(dot)de>
 *
 * References:
 * Payne, Rabung, Bogyo, "Coding the Lehmer pseudo-random number generator", Communications of the ACM Volume 12 #2: p.85–86, 1969.
 * Stephen K. Park and Keith W. Miller, "Random Number Generators: Good Ones Are Hard To Find", Communications of the ACM Volume 31 #10: p.1192–1201, 1988.
 *
 */

#include "lcg.h"

//! Constructor for LinearCongurentialGenerator with standard settings.
LinearCongurentialGenerator::LinearCongurentialGenerator() {
  a = 16807; // multiplier, 7**5
  m = 0x7FFFFFFF; // prime modulus, Mersenne prime 2147483647 = 2**31-1
  q = 127773; // m divided by a
  r = 2836; // m modulo a
  // this.a * this.q + this.r == this.m
  // 7**5 * 127773 + 2836 == 2**31-1
  seed = 1;
}

//! Constructor for LinearCongurentialGenerator taking parameters.
/*!
  \param a multiplier.
  \param m modulus.
  \param m divided by a (for best use of integer range)
  \param r m modulo a (for best use of integer range)
 */
LinearCongurentialGenerator::LinearCongurentialGenerator(int32_t a, int32_t m,
  int32_t q, int32_t r) {
  this->a = a;
  this->m = m;
  this->q = q;
  this->r = r;
  seed = 1;
}

//! Setting a seed for the RNG.
/*!
  \param seed seed value.
 */
void LinearCongurentialGenerator::setSeed (int32_t seed) {
  this->seed = seed;
}

//! Get the next random integer value.
/*!
  \return The next random integer value.
 */   
int32_t LinearCongurentialGenerator::getInt (void) {
  int32_t xn = seed;
  int32_t hi = xn / q;
  int32_t lo = xn - hi * q; 
  xn = a * lo - hi * r;
  seed = xn < 0 ? xn + m: xn;
  return seed;
}

