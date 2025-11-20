#pragma once

#include <cmath>
#include <algorithm>
#include <numeric>
#include <initializer_list>
#include <tuple>
#include <utility>
#include "Truth.h"

namespace NAL
{
    using NAL::Truth;
    using namespace std;

    using NAL::fc_to_w;
    using NAL::fc_to_w_minus;
    using NAL::fc_to_w_plus;
    using NAL::w_to_c;
    using NAL::w_to_f;

    inline Truth truth_from_w(float w_plus, float w, float k = 1.0)
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
        return Truth(f, c, k);
    }

    inline void w_from_truth(Truth &truth, double &o__w_plus, double &o__w_minus)
    {
        auto &f = truth.f;
        auto &c = truth.c;
        auto &k = truth.k;
        o__w_plus = fc_to_w_plus(f, c, k);
        o__w_minus = fc_to_w_minus(f, c, k);
    }

    inline pair<double, double> w_from_truth(Truth &truth)
    {
        double w_plus, w_minus;
        w_from_truth(truth, w_plus, w_minus);
        return {w_plus, w_minus};
    }

} // namespace NAL