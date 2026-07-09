#pragma once

#include <cstdint>
#include <string>

namespace seqnars::nal
{

struct TruthValue
{
    double f;
    double c;
    double k;

    TruthValue(double f, double c, double k = 1.0);
    TruthValue(double k = 1.0);

    static auto from_w(double w_p, double w, double k = 1.0) -> TruthValue;
    auto e() const -> double;
    auto w() const -> double;
    auto w_p() const -> double;
    auto w_m() const -> double;
    auto set_w(double w_p, double w) -> void;
    auto set_fc(double f, double c) -> void;
    auto revise(const TruthValue &truth) -> void;

    static auto project(const TruthValue &truth, int64_t t_src, int64_t t_tgt, int64_t duration = 20,
                        int64_t thresh_min = 5) -> TruthValue;
    static auto calc_decay_factor(double half_life_period) -> double;

    auto repr() const -> std::string;
};

using TruthV = TruthValue;
using DesireValue = TruthValue;
using DesireV = DesireValue;

} // namespace seqnars::nal
