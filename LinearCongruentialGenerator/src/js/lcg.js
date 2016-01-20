/**
 * Implementation of a Linear Congurential Generator
 *
 * MIT licensed (See LICENSE file being part of the repository)
 * Copyright (c) 2016 Oliver Merkel
 * All rights reserved.
 *
 * @author Oliver Merkel, <Merkel(dot)Oliver(at)web(dot)de>
 *
 * Mind that we only want to use integer values while JavaScript only
 * implements a general NumberType.
 * See http://www.ecma-international.org/ecma-262/5.1/#sec-8
 * Section 8.5: double-precision 64-bit format IEEE 754 values plus special NaN
 * The mantisse is build on 53-bit
 *
 * References:
 * Payne, Rabung, Bogyo, "Coding the Lehmer pseudo-random number generator", Communications of the ACM Volume 12 #2: p.85–86, 1969.
 * Stephen K. Park and Keith W. Miller, "Random Number Generators: Good Ones Are Hard To Find", Communications of the ACM Volume 31 #10: p.1192–1201, 1988.
 *
 */

function LinearCongurentialGenerator( a, m, q, r ) {
  this.a = a; // multiplier
  this.m = m; // modulus
  this.q = q; // m divided by a (for best use of integer range)
  this.r = r; // m modulo a (for best use of integer range)
}

LinearCongurentialGenerator.prototype.setSeed = function(s) {
  this.seed = s;
};

LinearCongurentialGenerator.prototype.getInt = function() {
  var xn = this.seed;
  var hi = Math.floor(xn / this.q);
  var lo = xn - hi * this.q;
  xn = this.a * lo - hi * this.r;
  this.seed = xn < 0 ? xn + this.m : xn;
  return this.seed;
}

