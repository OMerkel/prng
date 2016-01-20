/** \file lcg.h
 * \brief Linear Congurential Generator class/header
 *
 * Header/Class declaration of a Linear Congurential Generator
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

#ifndef _LCG_
#define _LCG_
#include <cstdint>

class LinearCongurentialGenerator {

  int32_t a; //!< multiplier
  int32_t m; //!< modulus
  int32_t q; //!< m divided by a (for best use of integer range)
  int32_t r; //!< m modulo a (for best use of integer range)
  int32_t seed;

public:

  //! Constructor for LinearCongurentialGenerator with standard settings.
  LinearCongurentialGenerator();

  //! Constructor for LinearCongurentialGenerator taking parameters.
  /*!
    \param a multiplier.
    \param m modulus.
    \param m divided by a (for best use of integer range)
    \param r m modulo a (for best use of integer range)
   */
  LinearCongurentialGenerator(int32_t a, int32_t m, int32_t q, int32_t r );

  //! Setting a seed for the RNG.
  /*!
    \param seed seed value.
   */
  void setSeed (int32_t seed);

  //! Get the next random integer value.
  /*!
    \return The next random integer value.
   */   
  int32_t getInt (void);
};

#endif /* _LCG_ */

