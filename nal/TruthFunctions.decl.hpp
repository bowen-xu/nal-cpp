#pragma once

#include "TruthValue.decl.hpp"

#include <utility>

namespace seqnars::nal
{

auto eternalize(const TruthValue &truth) -> TruthValue;
auto eternalize(const TruthValue &truth, TruthValue &truth_out) -> void;

auto revision(double wp1, double wp2, double wm1, double wm2) -> std::pair<double, double>;
auto revision(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void;
auto revision(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue;

auto negation(double f, double c) -> std::pair<double, double>;
auto negation(const TruthValue &truth, TruthValue &truth_out) -> void;
auto negation(const TruthValue &truth) -> TruthValue;

auto deduction(double f1, double f2, double c1, double c2) -> std::pair<double, double>;
auto deduction(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void;
auto deduction(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue;

auto analogy(double f1, double f2, double c1, double c2) -> std::pair<double, double>;
auto analogy(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void;
auto analogy(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue;

auto abduction(double f1, double f2, double c1, double c2) -> std::pair<double, double>;
auto abduction(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void;
auto abduction(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue;

auto induction(double f1, double f2, double c1, double c2) -> std::pair<double, double>;
auto induction(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void;
auto induction(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue;

auto exemplification(double f1, double f2, double c1, double c2) -> std::pair<double, double>;
auto exemplification(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void;
auto exemplification(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue;

auto comparison(double f1, double f2, double c1, double c2) -> std::pair<double, double>;
auto comparison(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void;
auto comparison(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue;

auto choice(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void;
auto choice(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue;

auto intersection(double f1, double f2, double c1, double c2) -> std::pair<double, double>;
auto intersection(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void;
auto intersection(const TruthValue &truth1, const TruthValue &truth2) -> TruthValue;

auto part_whole(double f1, double f2, double c1, double c2, double k = 1.0) -> std::pair<double, double>;
auto part_whole(const TruthValue &truth1, const TruthValue &truth2, TruthValue &truth_out) -> void;

} // namespace seqnars::nal
