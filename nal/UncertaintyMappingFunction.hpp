#pragma once

#include "UncertaintyMappingFunction.decl.hpp"

#include "TruthValue.hpp"

namespace seqnars::nal
{

inline auto fc_to_w_plus(float f, float c, float k) -> float { return k * f * c / (1 - c); }

inline auto fc_to_w(float, float c, float k) -> float { return k * c / (1 - c); }

inline auto fc_to_w_minus(float f, float c, float k) -> float { return k * (1 - f) * c / (1 - c); }

inline auto w_to_f(float w_plus, float w) -> float { return w > 1e-8 ? w_plus / w : 0.0; }

inline auto w_to_c(float w, float k) -> float { return w / (w + k); }

inline auto truth_from_w(float w_plus, float w, float k) -> TruthValue
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
    return TruthValue(f, c, k);
}

inline auto w_from_truth(const TruthValue &truth, double &output_w_plus, double &output_w_minus) -> void
{
    const auto f = truth.f;
    const auto c = truth.c;
    const auto k = truth.k;
    output_w_plus = fc_to_w_plus(f, c, k);
    output_w_minus = fc_to_w_minus(f, c, k);
}

inline auto w_from_truth(const TruthValue &truth) -> std::pair<double, double>
{
    double w_plus, w_minus;
    w_from_truth(truth, w_plus, w_minus);
    return {w_plus, w_minus};
}

} // namespace seqnars::nal
