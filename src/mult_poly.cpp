#include "mult_poly.hpp"

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

void mult_poly_naive(const std::vector<uint64_t> & p1, const std::vector<uint64_t> & p2, std::vector<uint64_t>& result)
{
    for (int i = 0; i < p1.size(); ++i)
    {
        for (int j = 0; j < p2.size(); ++j)
        {
            result[i + j] += p1[i] * p2[j];
        }
    }
}
/*
 integers modulo a prime number q
 The interesting thing about working in a finite field is that the polynomial coefficients
 “wrap around” when being multiplied. So regardless of how much polynomial arithmetic we
 perform, the coefficients of the polynomial can still be bounded in a fixed range
*/
void mult_poly_naive_q(const std::vector<uint64_t>& a, const std::vector<uint64_t>& b, uint64_t q, std::vector<uint64_t>& result)
{

    mult_poly_naive(a,b,result);
    for (uint64_t & i : result)
    {
        if(i>q) {
            i = i % q;
        }
    }
}