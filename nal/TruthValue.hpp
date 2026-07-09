#pragma once

#include "TruthValue.decl.hpp"

#include "Config.hpp"
#include "UncertaintyMappingFunction.decl.hpp"
#include "Utils.hpp"

#include <cmath>

namespace seqnars::nal
{

inline TruthValue::TruthValue(double f, double c, double k) : f(f), c(c), k(k) {}

inline TruthValue::TruthValue(double k) : f(config::F), c(config::C), k(k) {}

inline auto TruthValue::from_w(double w_p, double w, double k) -> TruthValue
{
    return TruthValue{w_to_f(w_p, w), w_to_c(w, k), k};
}

inline auto TruthValue::e() const -> double { return (this->c * (this->f - 0.5) + 0.5); }

inline auto TruthValue::w() const -> double { return this->k * this->c / (1 - this->c); }

inline auto TruthValue::w_p() const -> double { return this->k * this->f * this->c / (1 - this->c); }

inline auto TruthValue::w_m() const -> double { return this->k * (1 - this->f) * this->c / (1 - this->c); }

inline auto TruthValue::set_w(double w_p, double w) -> void
{
    this->f = w > 0 ? w_p / w : 0.5;
    this->c = w / (w + this->k);
}

inline auto TruthValue::set_fc(double f, double c) -> void
{
    this->f = f;
    this->c = c;
}

inline auto TruthValue::revise(const TruthValue &truth) -> void
{
    const auto w_p1 = this->w_p();
    const auto w1 = this->w();
    const auto w_p2 = truth.w_p();
    const auto w2 = truth.w();

    const auto w = w1 + w2;
    const auto w_p = w_p1 + w_p2;

    this->set_w(w_p, w);
}

inline auto TruthValue::project(const TruthValue &truth, int64_t t_src, int64_t t_tgt, int64_t duration,
                                int64_t thresh_min) -> TruthValue
{
    auto dt = std::abs(t_tgt - t_src);
    if (dt <= thresh_min)
        return truth;
    dt -= thresh_min;
    auto truth_out = TruthValue(truth);
    truth_out.c = utils::decay(truth.c, utils::get_decay_factor(duration), dt);
    return truth_out;
}

inline auto TruthValue::calc_decay_factor(double half_life_period) -> double
{
    return -1.0 / half_life_period * std::log(0.5);
}

} // namespace seqnars::nal
