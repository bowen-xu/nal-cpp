#pragma once

#include "TruthValue.decl.hpp"

namespace seqnars::nal
{

auto novelty(const TruthValue &truth_src, const TruthValue &truth_tgt) -> double;

auto novelty(const TruthValue &truthv) -> double;

auto novelty_v1(const TruthValue &truth_src, const TruthValue &truth_tgt) -> double;

auto utility(const TruthValue &truth) -> double;

auto achieving_level(const TruthValue &truth, const DesireValue &desire) -> double;
auto achieving_level(const DesireValue &desire) -> double;
auto sharpness(const TruthValue &truth) -> double;
auto reward(double novelty, double utility) -> double;

} // namespace seqnars::nal
