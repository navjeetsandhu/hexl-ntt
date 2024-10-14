#include <iostream>
#include <array>
#include <cmath>

#define N 4

inline void TwistFFT(std::array<uint64_t, N> &res, const std::array<double, N> &a)
{
    fftplvl1.execute_direct_torus64(res.data(), a.data());
}

inline void TwistFFT(std::array<uint32_t, N> &res, const std::array<double, N> &a)
{
    fftplvl1.execute_direct_torus32(res.data(), a.data());
}

inline void TwistIFFT(std::array<double, N> &res, const std::array<uint64_t, N> &a)
{
    fftplvl1.execute_reverse_torus64(res.data(), a.data());
}

inline void TwistIFFT(std::array<double, N> &res, const std::array<uint32_t, N> &a)
{
    fftplvl1.execute_reverse_torus32(res.data(), a.data());
}

inline void MulInFD(std::array<double, N> &res, const std::array<double, N> &b)
{
    for (int i = 0; i < N / 2; i++) {
        double aimbim = res[i + N / 2] * b[i + N / 2];
        double arebim = res[i] * b[i + N / 2];
        res[i] = std::fma(res[i], b[i], -aimbim);
        res[i + N / 2] = std::fma(res[i + N / 2], b[i], arebim);
    }
}

inline void PolyMulFFT(std::array<uint64_t, N>& res, const std::array<uint64_t, N> &a,
         const std::array<uint64_t, N> & b)
{
    alignas(64) std::array<double, N> ffta;
    TwistIFFT(ffta, a);
    alignas(64) std::array<double, N> fftb;
    TwistIFFT(fftb, b);
    MulInFD(ffta, fftb);
    TwistFFT(res, ffta);
}

inline void PolyMulFFT(std::array<uint32_t, N>& res, const std::array<uint32_t, N> &a,
                       const std::array<uint32_t, N> & b)
{
    alignas(64) std::array<double, N> ffta;
    TwistIFFT(ffta, a);
    alignas(64) std::array<double, N> fftb;
    TwistIFFT(fftb, b);
    MulInFD(ffta, fftb);
    TwistFFT(res, ffta);
}




