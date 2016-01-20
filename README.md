# PRNG
A PRNG (short for Pseudorandom Number Generator) is an algorithm to render number sequences looking random to users but actually being deterministic. It is intended that the PRNG gets close to idealistic random statistical behavior.

## Linear Congruential Generator
The LCG (short for Linear Congruential Generator) is based on the following number sequence.

![x_{n+1} = ( a x_{n} + c )  \mod m](res/prng_lcg_formula.png)
<!-- math xmlns="http://www.w3.org/1998/Math/MathML">
<mrow><msub>
  <mi>x</mi>
  <mn>n+1</mn>
</msub>
<mo> = </mo>
<mo>(</mo><mi>a</mi>
<msub>
  <mi>x</mi>
  <mn>n</mn>
</msub>
<mo> + </mo>
<mi>c</mi>
<mo>)</mo>
<mo>mod</mo>
<mi>m</mi>
</mrow>
</math -->
<!-- x_{n+1} = ( a x_{n} + c )  \mod m -->

whereas the **modulus** _m_ defines the periodicity, _x0_ is called the **seed** of the number sequence, _a_ being a natural number used as a **multiplier** and _c_ called an **increment**.

Some basic implementations of LCGs in different programming languages are available in the public domain or other open licensing. The implementations available in this code repository are MIT licensed (See LICENSE file).

The statistical quality of the LCG strongly depends on choice of the parameters for multiplier _a_, increment _c_, and modulus _m_. Common proposals are described and available in [Ent97]. In case that the increment _c_ equals 0 (zero) the LCG is sometimes referred being a _Park–Miller random number generator_ (after Stephen K. Park and Keith W. Miller) or a _Derrick Henry Lehmer RNG_ [PRB69]. A possible low quality choice on parameterization and therefore pitfall exists with increment _c_ equals 0 (zero), multiplier _a_ as 16807 = 7 ** 5, and higher modulus _m_ or size of integers to use in the algorithm [PM88][boost-1]. Such a variant with increment _c_ equals 0 (zero) is proposed in [LGM69] and is referred to as MINSTD_rand0. This quality constraint is since then with seed _x0_ as 1 the algorithm's random number divided by 7 will always have remainder being 0 (zero) at least until the overflow is reached caused by the integer range or modulus in use. Furthermore you should mind that with increment _c_ equals 0 (zero) the seed _x0_ being 0 (zero) is problematic as well. 

So a possible simple help might be to choose

* increment _c_ not being equal to 0 (zero),
* multiplier _a_ and modulus _m_ being prime or with low amount of prime factors,
* prime factors of multiplier _a_, increment _c_, and modulus _m_ shall differ,
* factorization of parameters shall not have values similar to any semantics for the domain the RNG is in use, e.g. multiplier _a_ as 16807 = 7**5 possibly being problematic to randomly select a day of week (7d == 1w).

Usually due to the number representation of the hardware architecture a specific number range and modulus is targeted and preferred over other values for these parameters. Additionally the number representation as used by the programming language introduces constraints and restrictions to keep the algorithm simple in code.

## Bibliography / References
* [PRB69] "Coding the Lehmer pseudo-random number generator", Payne, Rabung, Bogyo, Communications of the ACM Volume 12 #2: pp. 85–86, 1969. http://www.firstpr.com.au/dsp/rand31/p85-payne.pdf
* [LGM69] "A pseudo-random number generator for the System/360", P.A. Lewis, A.S. Goodman, J.M. Miller, IBM Systems Journal, Volume 8 #2: pp. 136-146, 1969.
* [PM88] "Random Number Generators: Good Ones Are Hard To Find", Stephen K. Park and Keith W. Miller, Communications of the ACM Volume 31 #10: pp. 1192–1201, 1988. http://www.firstpr.com.au/dsp/rand31/p1192-park.pdf
* [Ent97] "A collection of selected pseudorandom number generators with linear structures", Karl Entacher, TR #97, ACPC - Austrian Center for Parallel Computation, University of Vienna, Austria, 1997. http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.53.3686&rep=rep1&type=pdf
* [boost-1] https://github.com/boostorg/random/blame/develop/include/boost/random/linear_congruential.hpp
  * https://github.com/boostorg/random/commit/2248892f096109bcc58a29831ad5e7ad8d347d06 , include/boost/random/linear_congruential.hpp
  * https://github.com/boostorg/random/commit/e4cca265d0ff13c0fd1bc5bee132d0342195fa66 , include/boost/random/linear_congruential.hpp
