#pragma once

#include "TruthFunctions.decl.hpp"

#include "ExtendedBooleanFunctions.hpp"
#include "TruthValue.hpp"
#include "UncertaintyMappingFunction.hpp"

namespace seqnars::nal
{

inline auto eternalize(const TruthValue &truth) -> TruthValue
{
    return TruthValue(truth.f, w_to_c(truth.c, truth.k), truth.k);
}

inline auto eternalize(const TruthValue &truth, TruthValue &truth_out) -> void
{
    truth_out.set_fc(truth.f, w_to_c(truth.c, truth.k));
    truth_out.k = truth.k;
}

inline auto revision(double wp1, double wp2, double wm1, double wm2) -> std::pair<double, double>
{
    return {wp1 + wp2, wm1 + wm2};
}

inline auto revision(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void
{
    auto &&[wp, wm] = revision(truth1.w_p(), truth2.w_p(), truth1.w_m(), truth2.w_m());
    truth_out.set_w(wp, wp + wm);
}

inline auto revision(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue
{
    auto truth_out = TruthValue(truth1.k);
    revision(truth1, truth2, truth_out);
    return truth_out;
}

inline auto negation(double f, double c) -> std::pair<double, double> { return {1.0 - f, c}; }

inline auto negation(const TruthValue &truth, TruthValue &truth_out) -> void
{
    auto &&[f, c] = negation(truth.f, truth.c);
    truth_out.set_fc(f, c);
}

inline auto negation(const TruthValue &truth) -> TruthValue
{
    auto truth_out = TruthValue(truth.k);
    negation(truth, truth_out);
    return truth_out;
}

inline auto deduction(double f1, double f2, double c1, double c2) -> std::pair<double, double>
{
    const auto f = and_(f1, f2);
    const auto c = and_(f1, f2, c1, c2);
    return {f, c};
}

inline auto deduction(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void
{
    auto &&[f, c] = deduction(truth1.f, truth2.f, truth1.c, truth2.c);
    truth_out.set_fc(f, c);
}

inline auto deduction(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue
{
    auto truth_out = TruthValue(truth1.k);
    deduction(truth1, truth2, truth_out);
    return truth_out;
}

inline auto analogy(double f1, double f2, double c1, double c2) -> std::pair<double, double>
{
    const auto f = and_(f1, f2);
    const auto c = and_(f2, c1, c2);
    return {f, c};
}

inline auto analogy(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void
{
    auto &&[f, c] = analogy(truth1.f, truth2.f, truth1.c, truth2.c);
    truth_out.set_fc(f, c);
}

inline auto analogy(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue
{
    auto truth_out = TruthValue(truth1.k);
    analogy(truth1, truth2, truth_out);
    return truth_out;
}

inline auto abduction(double f1, double f2, double c1, double c2) -> std::pair<double, double>
{
    const auto wp = and_(f1, f2, c1, c2);
    const auto w = and_(f1, c1, c2);
    return {wp, w};
}

inline auto abduction(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void
{
    auto &&[wp, w] = abduction(truth1.f, truth2.f, truth1.c, truth2.c);
    truth_out.set_w(wp, w);
}

inline auto abduction(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue
{
    auto truth_out = TruthValue(truth1.k);
    abduction(truth1, truth2, truth_out);
    return truth_out;
}

inline auto induction(double f1, double f2, double c1, double c2) -> std::pair<double, double>
{
    const auto wp = and_(f1, f2, c1, c2);
    const auto w = and_(f2, c1, c2);
    return {wp, w};
}

inline auto induction(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void
{
    auto &&[wp, w] = induction(truth1.f, truth2.f, truth1.c, truth2.c);
    truth_out.set_w(wp, w);
}

inline auto induction(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue
{
    auto truth_out = TruthValue(truth1.k);
    induction(truth1, truth2, truth_out);
    return truth_out;
}

inline auto exemplification(double f1, double f2, double c1, double c2) -> std::pair<double, double>
{
    const auto wp = and_(f1, f2, c1, c2);
    const auto w = wp;
    return {wp, w};
}

inline auto exemplification(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void
{
    auto &&[wp, w] = exemplification(truth1.f, truth2.f, truth1.c, truth2.c);
    truth_out.set_w(wp, w);
}

inline auto exemplification(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue
{
    auto truth_out = TruthValue(truth1.k);
    exemplification(truth1, truth2, truth_out);
    return truth_out;
}

inline auto comparison(double f1, double f2, double c1, double c2) -> std::pair<double, double>
{
    const auto wp = and_(f1, f2, c1, c2);
    const auto w = and_(or_(f1, f2), c1, c2);
    return {wp, w};
}

inline auto comparison(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void
{
    auto &&[wp, w] = comparison(truth1.f, truth2.f, truth1.c, truth2.c);
    truth_out.set_w(wp, w);
}

inline auto comparison(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue
{
    auto truth_out = TruthValue(truth1.k);
    comparison(truth1, truth2, truth_out);
    return truth_out;
}

inline auto choice(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void
{
    if (truth1.e() > truth2.e())
        truth_out.set_fc(truth1.f, truth1.c);
    else
        truth_out.set_fc(truth2.f, truth2.c);
}

inline auto choice(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue
{
    auto truth_out = TruthValue(truth1.k);
    choice(truth1, truth2, truth_out);
    return truth_out;
}

inline auto intersection(double f1, double f2, double c1, double c2) -> std::pair<double, double>
{
    const auto f = and_(f1, f2);
    const auto c = and_(c1, c2);
    return {f, c};
}

inline auto intersection(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void
{
    auto &&[f, c] = intersection(truth1.f, truth2.f, truth1.c, truth2.c);
    truth_out.set_fc(f, c);
}

inline auto intersection(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue
{
    auto truth_out = TruthValue(truth1.k);
    intersection(truth1, truth2, truth_out);
    return truth_out;
}

inline auto part_whole(double f1, double f2, double c1, double c2, double k) -> std::pair<double, double>
{
    const auto f = and_(f1, f2);
    const auto w = and_(f1, f2, c1, c2);
    const auto c = w_to_c(w, k);
    return {f, c};
}

inline auto part_whole(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void
{
    auto &&[f, c] = part_whole(truth1.f, truth2.f, truth1.c, truth2.c, truth_out.k);
    truth_out.f = f;
    truth_out.c = c;
}

} // namespace seqnars::nal
