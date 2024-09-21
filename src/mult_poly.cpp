#include "mult_poly.hpp"
#include <iostream>
//#include "utils.hpp"
/*
 * https://cryptographycaffe.sandboxaq.com/posts/ntt-01/
 * Polynomials are really just fancy lists of numbers that have a particular way of doing arithmetic.
For example, adding two polynomials is as simple as just summing up their coefficients.
Multiplying a polynomial by a constant is just multiplying every coefficient by that constant.
However, when we want to multiply polynomials, things get slightly more complicated.
Suppose we have two degree (d−1) polynomials
The classical way of performing polynomial multiplications is to expand out the summation, and multiply everything in P(x) with everything in Q(x) to form a degree 2d−2 polynomial:
 This summation is commonly known as the convolution of the coefficients of P,Q.
i.e. Schoolbook Multiplication
*/

void mult_poly_naive(const std::vector<uint64_t> & p1,
                     const std::vector<uint64_t> & p2,
                     std::vector<uint64_t>& result)
{
    for (int i = 0; i < p1.size(); ++i)
        for (int j = 0; j < p2.size(); ++j)
            result[i + j] += p1[i] * p2[j];
}
/*
 * integers modulo a prime number q
 * The interesting thing about working in a finite field is that the polynomial coefficients
 * wrap around when being multiplied. So regardless of how much polynomial arithmetic we
 * perform, the coefficients of the polynomial can still be bounded in a fixed range
*/
void mult_poly_naive_q(const std::vector<uint64_t>& p1,
                       const std::vector<uint64_t>& p2,
                       uint64_t q,
                       std::vector<uint64_t>& result) {
    mult_poly_naive(p1,p2,result);
    for (uint64_t & i : result) i = i % q;
}

/*
 * Cyclic Convolution (CC)
 * The degree of the polynomial will only grow larger and larger as we perform
 * more multiplications. That means we need to have longer
 * arrays to store coefficients and more complex convolutions every time a
 * multiplication is performed.  It would be great if the degree of the polynomials
 * could wrap around just like the coefficients.
 * we can take modulo some polynomial ϕ(x) after every polynomial operation.
 * The resulting polynomial’s degree would never be larger or equal to the degree of ϕ(x).
 * We call such structure Zq[x]/(ϕ(x)
 * when ϕ(x)=xd−1. If we take any polynomial modulo xd−1, it’s equivalent to removing multiples
 * of xd−1 from the polynomial until the resulting polynomial has degree lower than d
 */
void mult_poly_naive_q_cc(const std::vector<uint64_t>& p1,
                          const std::vector<uint64_t>& p2,
                          uint64_t q,
                          uint64_t d,
                          std::vector<uint64_t>& result) {
    mult_poly_naive_q(p1,p2,q, result);
    for (uint64_t i = d; i < result.size(); ++i) {
        result[i - d] = (result[i - d] + result[i]) % q;
        result[i] = 0;
    }
}
/*
 * Conversely, the other modulus ϕ(x)=xd+1 results in what is called negative
 * wrapped convolution, or sometimes negacyclic convolution. Obviously, because
 * the sign of the one term flipped, now when removing copies of the modulus
 * from a polynomial, what wraps around will be the negation of the original
 * high degree term coefficient that got reduced.
*/
void mult_poly_naive_q_nwc(const std::vector<uint64_t>& p1,
                           const std::vector<uint64_t>& p2,
                          uint64_t q, uint64_t d,
                          std::vector<uint64_t>& result) {
    mult_poly_naive_q(p1,p2,q, result);
    for (uint64_t i = d; i < result.size(); ++i) {
        int64_t tmp = result[i - d] - result[i];
        result[i - d] = tmp > 0 ? tmp % q : tmp + q;
        result[i] = 0;
    }
}