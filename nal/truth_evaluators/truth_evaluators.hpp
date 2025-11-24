#pragma once
#include <cmath>
#include <type_traits>
#include "truth_evaluators.decl.hpp"
#include "../truth_value/truth_value.hpp"

namespace NAL
{
inline double novelty(const auto &truth_src, const auto &truth_tgt)
    requires std::is_same_v<std::decay_t<decltype(truth_src)>, TruthV> &&
             std::is_same_v<std::decay_t<decltype(truth_tgt)>, TruthV>
{
    return std::abs(truth_src.e() - truth_tgt.e());
}

inline double novelty_v1(const auto &truth_src, const auto &truth_tgt)
    requires std::is_same_v<std::decay_t<decltype(truth_src)>, TruthV> &&
             std::is_same_v<std::decay_t<decltype(truth_tgt)>, TruthV>
{
    return std::sqrt(std::abs(truth_src.e() - truth_tgt.e()) * truth_src.c);
}

inline double utility(const auto &truth)
    requires std::is_same_v<std::decay_t<decltype(truth)>, TruthV>
{
    return truth.e() - 0.5;
}

inline double achieving_level(const TruthV &truth, const DesireV &desire)
{
    return 1.0 - std::abs(desire.e() - truth.e());
}

inline double achieving_level(const DesireV &desire) { return 1.0 - std::abs(desire.e() - 0.5); }

inline double sharpness(const TruthV &truth) { return 2 * std::abs(truth.e() - 0.5); }

inline double reward(double novelty, double utility)
{
    // nu = np.clip(np.sqrt(nu) * 1.75, 0.0, 1.0)
    // return ((mu+1)*nu - 1) # *np.abs(mu)
    novelty = std::clamp(std::sqrt(novelty) * 1.75, 0.0, 1.0);
    return (utility + 1) * novelty - 1;
}
} // namespace NAL
