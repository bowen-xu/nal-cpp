#pragma once

#include "ExtendedBooleanFunctions.decl.hpp"

#include <initializer_list>
#include <numeric>
#include <vector>

namespace seqnars::nal
{
/* Extended Boolean Functions */
inline auto and_(double x1, double x2) -> double { return x1 * x2; }

inline auto and_(double x1, double x2, double x3) -> double { return x1 * x2 * x3; }

inline auto and_(double x1, double x2, double x3, double x4) -> double { return x1 * x2 * x3 * x4; }

inline auto and_(std::initializer_list<double> x) -> double
{
    return std::accumulate(x.begin(), x.end(), 1.0, [](double acc, double xi) { return acc * xi; });
}

inline auto and_(const std::vector<double> &x) -> double
{
    return std::accumulate(x.begin(), x.end(), 1.0, [](double acc, double xi) { return acc * xi; });
}

inline auto or_(double x1, double x2) -> double { return 1 - (1 - x1) * (1 - x2); }

inline auto or_(double x1, double x2, double x3) -> double { return 1 - (1 - x1) * (1 - x2) * (1 - x3); }

inline auto or_(double x1, double x2, double x3, double x4) -> double
{
    return 1 - (1 - x1) * (1 - x2) * (1 - x3) * (1 - x4);
}

inline auto or_(std::initializer_list<double> x) -> double
{
    return 1.0 - std::accumulate(x.begin(), x.end(), 1.0, [](double acc, double xi) { return acc * (1.0 - xi); });
}

inline auto or_(const std::vector<double> &x) -> double
{
    return 1.0 - std::accumulate(x.begin(), x.end(), 1.0, [](double acc, double xi) { return acc * (1.0 - xi); });
}

inline auto not_(double x) -> double { return 1 - x; }

inline auto xor_(double x1, double x2) -> double
{
    /*
    Two candidates for the XOR function:
    1. x1 + x2 - 2 * x1 * x2
    2. or_(and_(x1, not_(x2)), and_(not_(x1), x2));
    The maximal difference is 0.0625, which is achieved when x1 = 0.5 and x2 = 0.5.
    For the moment, the first one is chosen for its simplicity.
    */
    return x1 + x2 - 2 * x1 * x2;
    // The alternative formula uses or_ over two mutually exclusive and_ terms.
}

inline auto xnor_(double x1, double x2) -> double { return not_(xor_(x1, x2)); }

} // namespace seqnars::nal
