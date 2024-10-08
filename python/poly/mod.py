from sympy import isprime


def print_modular_multiplicative_inverse(a, b, mod):
    #https: // en.wikipedia.org / wiki / Modular_multiplicative_inverse
    result = pow(a, b, mod)
    print("%d = pow(%d, %d, %d)" % (result, a, b, mod))


#  Biggest prime number less than 2^bits and satisfies 1 mod 2N.
# where bits is modulus bits.  i.e. HEXL support Maximum number of 62 bits in modulus
# N is dimensions. i.e. for tfhe lvl1param, the dimension is 1024, i.e. 1024 elements in polynomial
def print_mod(bits, dimension):
    # Number to start checking
    n = 2 ** bits - 1

    d2 = 2 * dimension

    # Limit is smallest odd number that satisfies the condition.
    limit = d2 * 2 + 1

    # Loop while we are above the limit
    while n >= limit:
        # If number is a prime and satisfies the condition n congruent 1 (mod 2048)
        if isprime(n) and n % d2 == 1:
            print("bits %d, dimension %d Modulus = %d (%s)" % (bits, dimension, n, hex(n)))
            break
        # Decrease number by 2 to take the next lower odd number
        n -= 2


if __name__ == '__main__':
    print_mod(62, 1024)
    print_modular_multiplicative_inverse(3383, -1,7681)
    print_modular_multiplicative_inverse(4, -1, 7681)
    print_modular_multiplicative_inverse(1925, -1, 7681)
