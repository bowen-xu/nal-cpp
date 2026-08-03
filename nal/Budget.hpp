#pragma once

#include "Budget.decl.hpp"

#include <algorithm>
#include <cmath>

namespace seqnars::nal
{

inline Budget::Budget(double priority, double durability, double quality, int64_t ts_update)
    : priority(priority), durability(durability), quality(quality), ts_update(ts_update)
{
}

inline auto Budget::calc_durability(double half_life_period) -> double
{
    return 1.0 + std::log(0.5) / half_life_period;
}

inline auto Budget::decay(double ts_now) -> void
{
    static const auto Q = 0.3;
    if (ts_now > this->ts_update)
    {
        const auto dt = ts_now - this->ts_update;
        this->ts_update = ts_now;
        const auto q = this->quality * Q;
        this->priority = q + (this->priority - q) * std::exp(-(1 - this->durability) * dt);
    }
}

inline auto Budget::decay0(double ts_now) -> void
{
    if (ts_now > this->ts_update)
    {
        const auto dt = ts_now - this->ts_update;
        this->ts_update = ts_now;
        this->priority = this->priority * std::exp(-(1 - this->durability) * dt);
    }
}

inline auto Budget::excite_p(double a, double stubbornness) -> void
{
    const auto s = std::clamp(stubbornness, 0.0, 1.0);
    const auto dp = a * (1 - this->priority) * (1 - (1 - this->priority) * s);
    this->priority += dp;
    this->priority = std::min(1.0, this->priority);
}

inline auto Budget::inhibit_p(double a, double stubbornness) -> void
{
    const auto s = std::clamp(stubbornness, 0.0, 1.0);
    const auto dp = -a * this->priority * (1 - this->priority * s);
    this->priority += dp;
    this->priority = std::max(0.0, this->priority);
}

} // namespace seqnars::nal
