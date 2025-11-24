#pragma once
#include "truth_value.decl.hpp"
#include "../uncertainty_mapping_function/uncertainty_mapping_function.decl.hpp"

namespace NAL
{

struct TruthV
{
public:
    double f;
    double c;
    double k;

    int64_t ts_update = -1;
    bool is_eternal = true;

    TruthV(double f, double c, double k = 1.0) : f(f), c(c), k(k) {};
    TruthV(double f, double c, bool is_temporal, int64_t ts_update = -1, double k = 1.0)
        : f(f), c(c), k(k), is_eternal(!is_temporal), ts_update(ts_update) {};
    TruthV(double k = 1.0) : f(CONFIG::f), c(CONFIG::c), k(k) {};

    static auto from_w(double w_p, double w, double k = 1.0) { return TruthV{w_to_f(w_p, w), w_to_c(w, k), k}; }
    inline double e() const { return (c * (f - 0.5) + 0.5); }

    inline double w() const { return k * c / (1 - c); }

    inline double w_p() const { return k * f * c / (1 - c); }

    inline double w_m() const { return k * (1 - f) * c / (1 - c); }

    inline void set_w(double w_p, double w)
    {
        this->f = w > 0 ? w_p / w : 0.5;
        this->c = w / (w + k);
    }

    inline void set_w(double w_p, double w, int64_t ts_update)
    {
        this->set_w(w_p, w);
        if (!is_eternal)
            this->ts_update = ts_update;
        else
            throw std::runtime_error("Cannot set timestamp for eternal truth");
    }

    inline void set_fc(double f, double c)
    {
        this->f = f;
        this->c = c;
    }

    inline void set_fc(double f, double c, int64_t ts_update)
    {
        this->set_fc(f, c);
        if (!is_eternal)
            this->ts_update = ts_update;
        else
            throw std::runtime_error("Cannot set timestamp for eternal truth");
    }

    inline void revise(const TruthV &truth)
    {
        auto w_p1 = this->w_p();
        auto w1 = this->w();
        auto w_p2 = truth.w_p();
        auto w2 = truth.w();

        auto w = w1 + w2;
        auto w_p = w_p1 + w_p2;

        this->set_w(w_p, w);
    }

    // inline void revise(TruthV &truth, int64_t ts_now, int64_t duration = 20)
    // {
    //     this->project(ts_now, duration);
    //     this->revise(truth);
    // }

    // inline void revise_w(double w_p, double w)
    // {
    //     w_p = this->w_p() + w_p;
    //     w = this->w() + w;
    //     this->set_w(w_p, w);
    // }

    // inline void revise_w(std::common_type_t<double, int> w_p, std::common_type_t<double, int> w, int64_t ts_now,
    //                      int64_t duration = 20)
    // {
    //     this->project(ts_now, duration);
    //     this->revise_w(w_p, w);
    // }

    // inline void project(int64_t ts_now, int64_t duration = 20, bool forward_only = true)
    // {
    //     if (!this->is_eternal)
    //     {
    //         if (!forward_only || this->ts_update < ts_now)
    //         {
    //             auto dt = std::abs(ts_now - this->ts_update);
    //             this->c = UTILS::decay(this->c, UTILS::get_decay_factor(duration), dt);
    //         }
    //         this->ts_update = ts_now;
    //     }
    // }

    static TruthV
    project(const TruthV &truth, int64_t t_src, int64_t t_tgt, int64_t duration = 20)
    {
        auto truth_out = TruthV(truth);
        auto dt = std::abs(t_tgt - t_src);
        truth_out.c = UTILS::decay(truth.c, UTILS::get_decay_factor(duration), dt);
        return truth_out;
    }

    inline static double calc_decay_factor(double half_life_period)
    {
        /*
         *  The decay factor is calculated as follows
         *      x(t) = e^(-a*t)
         *      x(t+hlp) / x(t) = 0.5
         *      e^(-a*(t+hlp)) / e^(-a*t) = 0.5
         *      e^(-a*hlp) = 0.5
         *      -a*hlp = ln(0.5)
         *      a = -ln(0.5) / hlp
         */
        return -1.0 / half_life_period * std::log(0.5);
    }

    inline std::string __repr__() { return fmt::format("<Truth: %{:.2f}, {:.2f}% (k={})>", this->f, this->c, this->k); }
};

} // namespace NAL
