#pragma once
#include <cmath>
#include <cstdint>
#include "utils.hpp"

namespace NAL
{
    namespace UTILS
    {

        inline auto get_decay_factor(double half_life_period) { return -1.0 / half_life_period * std::log(0.5); }

        inline auto decay(double value, double alpha, int64_t dt)
        {
            /*
            decay confidence by
            c' = c*exp(-alpha*dt)
            The smaller the alpha is, the slower the decay

            half-life period
            |  dt  |    alpha   |
            | ---- | ---------- |
            |    1 | 0.69314718 |
            |    2 | 0.34657359 |
            |    4 | 0.17328680 |
            |    8 | 0.08664340 |
            |   16 | 0.04332170 |
            |   32 | 0.02166085 |
            |   64 | 0.01083042 |
            |  128 | 0.00541521 |
            |  256 | 0.00270761 |
            |  512 | 0.00135380 |
            | 1024 | 0.00067690 |
            */
            return value * std::exp(-alpha * dt);
        }
    } // namespace UTILS
} // namespace NAL
