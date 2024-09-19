#include "mult_poly.hpp"

/*
 * Polynomials are really just fancy lists of numbers that have a particular way of doing arithmetic.
For example, adding two polynomials is as simple as just summing up their coefficients.
Multiplying a polynomial by a constant is just multiplying every coefficient by that constant.
However, when we want to multiply polynomials, things get slightly more complicated.
Suppose we have two degree (d−1) polynomials
The classical way of performing polynomial multiplications is to expand out the summation, and multiply everything in P(x) with everything in Q(x) to form a degree 2d−2 polynomial:
 This summation is commonly known as the convolution of the coefficients of P,Q.
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