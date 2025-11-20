#pragma once

#include <cmath>
#include <type_traits>
#include "Truth.h"

namespace NAL
{
    using NAL::DesireValue;
    using NAL::Truth;

    inline double novelty(const auto &truth1, const auto &truth2)
        requires std::is_same_v<std::decay_t<decltype(truth1)>, Truth> &&
                 std::is_same_v<std::decay_t<decltype(truth2)>, Truth>
    {
        return std::abs(truth1.e() - truth2.e());
    }

    inline double utility(const auto &truth)
        requires std::is_same_v<std::decay_t<decltype(truth)>, Truth>
    {
        return truth.e() - 0.5;
    }

    inline double achieving_level(const Truth &truth, const DesireValue &desire)
    {
        return 1.0 - std::abs(desire.e() - truth.e());
    }

    inline double achieving_level(const DesireValue &desire) { return 1.0 - std::abs(desire.e() - 0.5); }

    inline double sharpness(const Truth &truth) { return 2 * std::abs(truth.e() - 0.5); }

    inline double reward(double novelty, double utility)
    {
        // nu = np.clip(np.sqrt(nu) * 1.75, 0.0, 1.0)
        // return ((mu+1)*nu - 1) # *np.abs(mu)
        novelty = std::clamp(std::sqrt(novelty) * 1.75, 0.0, 1.0);
        return (utility + 1) * novelty - 1;
    }
} // namespace NAL
