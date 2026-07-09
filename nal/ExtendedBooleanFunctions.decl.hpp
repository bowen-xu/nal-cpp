#pragma once

#include <initializer_list>
#include <vector>

namespace seqnars::nal
{

auto and_(double x1, double x2) -> double;
auto and_(double x1, double x2, double x3) -> double;
auto and_(double x1, double x2, double x3, double x4) -> double;
auto and_(std::initializer_list<double> x) -> double;
auto and_(const std::vector<double> &x) -> double;

auto or_(double x1, double x2) -> double;
auto or_(double x1, double x2, double x3) -> double;
auto or_(double x1, double x2, double x3, double x4) -> double;
auto or_(std::initializer_list<double> x) -> double;
auto or_(const std::vector<double> &x) -> double;

auto not_(double x) -> double;
auto xor_(double x1, double x2) -> double;
auto xnor_(double x1, double x2) -> double;

} // namespace seqnars::nal
