#pragma once

#include "TruthValue.decl.hpp"

#include <utility>

namespace seqnars::nal
{

auto fc_to_w_plus(float f, float c, float k) -> float;
auto fc_to_w(float, float c, float k) -> float;
auto fc_to_w_minus(float f, float c, float k) -> float;
auto w_to_f(float w_plus, float w) -> float;
auto w_to_c(float w, float k) -> float;

auto truth_from_w(float w_plus, float w, float k = 1.0) -> TruthValue;
auto w_from_truth(const TruthValue &truth, double &output_w_plus, double &output_w_minus) -> void;
auto w_from_truth(const TruthValue &truth) -> std::pair<double, double>;

} // namespace seqnars::nal
