#pragma once

#include "Utils.decl.hpp"

#include <cmath>

namespace seqnars::nal::utils
{

inline auto get_decay_factor(double half_life_period) -> double { return -1.0 / half_life_period * std::log(0.5); }

inline auto decay(double value, double alpha, int64_t dt) -> double { return value * std::exp(-alpha * dt); }

} // namespace seqnars::nal::utils
