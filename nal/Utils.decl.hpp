#pragma once

#include <cstdint>

namespace seqnars::nal::utils
{

auto get_decay_factor(double half_life_period) -> double;
auto decay(double value, double alpha, int64_t dt) -> double;

} // namespace seqnars::nal::utils
