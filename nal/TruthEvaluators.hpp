#pragma once

#include "TruthEvaluators.decl.hpp"

#include "TruthValue.hpp"

#include <algorithm>
#include <cmath>

namespace seqnars::nal
{

inline auto novelty(const TruthValue &truth_src, const TruthValue &truth_tgt) -> double
{
    return std::abs(truth_src.e() - truth_tgt.e());
}

inline auto novelty(const TruthValue &truthv) -> double { return std::abs(truthv.e() - 0.5); }

inline auto novelty_v1(const TruthValue &truth_src, const TruthValue &truth_tgt) -> double
{
    return std::sqrt(std::abs(truth_src.e() - truth_tgt.e()) * truth_src.c);
}

inline auto utility(const TruthValue &truth) -> double { return truth.e() - 0.5; }

inline auto achieving_level(const TruthValue &truth, const DesireValue &desire) -> double
{
    return 1.0 - std::abs(desire.e() - truth.e());
}

inline auto achieving_level(const DesireValue &desire) -> double { return 1.0 - std::abs(desire.e() - 0.5); }

inline auto sharpness(const TruthValue &truth) -> double { return 2 * std::abs(truth.e() - 0.5); }

inline auto reward(double novelty, double utility) -> double
{
    novelty = std::clamp(std::sqrt(novelty) * 1.75, 0.0, 1.0);
    return (utility + 1) * novelty - 1;
}

} // namespace seqnars::nal
