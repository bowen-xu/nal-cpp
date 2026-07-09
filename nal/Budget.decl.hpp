#pragma once

#include <cstdint>

namespace seqnars::nal
{
struct Budget
{
    inline static constexpr double PRIORITY_DEFAULT = 0.9;
    inline static constexpr double DURABILITY_DEFAULT = 0.9;
    inline static constexpr double QUALITY_DEFAULT = 0.5;

    double priority;
    double durability;
    double quality;
    int64_t ts_update = -1;

    Budget(double priority = PRIORITY_DEFAULT, double durability = DURABILITY_DEFAULT,
           double quality = QUALITY_DEFAULT);

    static auto calc_durability(double half_life_period) -> double;

    auto decay(double ts_now) -> void;
    auto decay0(double ts_now) -> void;
    auto excite_p(double a, double stubbornness = 0.1) -> void;
    auto inhibit_p(double a, double stubbornness = 0.1) -> void;
};

} // namespace seqnars::nal
