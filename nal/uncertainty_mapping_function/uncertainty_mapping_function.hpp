#pragma once

#include <utility>
#include "uncertainty_mapping_function.decl.hpp"
#include "../truth_value/truth_value.hpp"

namespace NAL
{
inline float fc_to_w_plus(const float f, const float c, const float k) { return k * f * c / (1 - c); }
inline float fc_to_w(const float f, const float c, const float k) { return k * c / (1 - c); }
inline float fc_to_w_minus(const float f, const float c, const float k) { return k * (1 - f) * c / (1 - c); }
inline float w_to_f(const float w_plus, const float w) { return w > 1e-8 ? w_plus / w : 0.0; }
inline float w_to_c(const float w, const float k) { return w / (w + k); }

inline TruthV truth_from_w(float w_plus, float w, float k = 1.0)
{
    float f, c;
    if (w != 0)
    {
        f = w_to_f(w_plus, w);
        c = w_to_c(w, k);
    }
    else
    {
        f = 0.5;
        c = 0.0;
    }
    return TruthV(f, c, k);
}

inline void w_from_truth(TruthV &truth, double &o__w_plus, double &o__w_minus)
{
    auto &f = truth.f;
    auto &c = truth.c;
    auto &k = truth.k;
    o__w_plus = fc_to_w_plus(f, c, k);
    o__w_minus = fc_to_w_minus(f, c, k);
}

inline std::pair<double, double> w_from_truth(TruthV &truth)
{
    double w_plus, w_minus;
    w_from_truth(truth, w_plus, w_minus);
    return {w_plus, w_minus};
}

} // namespace NAL
