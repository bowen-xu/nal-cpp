#pragma once
#include "../truth_value/truth_value.decl.hpp"

namespace NAL
{

float fc_to_w_plus(const float f, const float c, const float k);
float fc_to_w(const float f, const float c, const float k);
float fc_to_w_minus(const float f, const float c, const float k);
float w_to_f(const float w_plus, const float w);
float w_to_c(const float w, const float k);

TruthV truth_from_w(float w_plus, float w, float k);
void w_from_truth(TruthV &truth, double &o__w_plus, double &o__w_minus);

} // namespace NAL
