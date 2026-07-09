#include "nal/Nal.hpp"

#include <gtest/gtest.h>

#include <cmath>
#include <utility>
#include <vector>

namespace seqnars::nal
{
namespace
{

constexpr auto EPSILON = 1e-7;

auto expect_near(double actual, double expected) -> void { EXPECT_NEAR(actual, expected, EPSILON); }

TEST(ExtendedBooleanFunctions, ComputeBooleanLikeValues)
{
    expect_near(and_(0.5, 0.4), 0.2);
    expect_near(and_({0.2, 0.5, 0.8}), 0.08);
    expect_near(and_(std::vector<double>{0.2, 0.5, 0.8}), 0.08);

    expect_near(or_(0.2, 0.5), 0.6);
    expect_near(or_({0.2, 0.5, 0.8}), 0.92);
    expect_near(or_(std::vector<double>{0.2, 0.5, 0.8}), 0.92);

    expect_near(not_(0.25), 0.75);
    expect_near(xor_(0.25, 0.75), 0.625);
    expect_near(xnor_(0.25, 0.75), 0.375);
}

TEST(TruthValue, ConvertsBetweenFrequencyConfidenceAndWeights)
{
    auto truth = TruthValue(0.75, 0.5, 2.0);

    expect_near(truth.e(), 0.625);
    expect_near(truth.w(), 2.0);
    expect_near(truth.w_p(), 1.5);
    expect_near(truth.w_m(), 0.5);

    truth.set_w(2.0, 4.0);
    expect_near(truth.f, 0.5);
    expect_near(truth.c, 2.0 / 3.0);

    auto from_w = TruthValue::from_w(2.0, 4.0, 2.0);
    expect_near(from_w.f, 0.5);
    expect_near(from_w.c, 2.0 / 3.0);
}

TEST(TruthValue, RevisesAndProjectsTruth)
{
    auto truth = TruthValue(0.75, 0.5, 1.0);
    truth.revise(TruthValue(0.25, 0.5, 1.0));
    expect_near(truth.f, 0.5);
    expect_near(truth.c, 2.0 / 3.0);

    const auto projected = TruthValue::project(TruthValue(0.8, 0.9, 1.0), 0, 10, 5, 0);
    expect_near(projected.f, 0.8);
    expect_near(projected.c, 0.225);
}

TEST(Budget, UpdatesPriority)
{
    auto budget = Budget(0.5, Budget::calc_durability(2.0), 0.5);

    expect_near(Budget::calc_durability(2.0), 1.0 + std::log(0.5) / 2.0);

    budget.ts_update = 0;
    budget.decay(2.0);
    expect_near(budget.priority, 0.325);

    budget.excite_p(0.2, 0.0);
    expect_near(budget.priority, 0.46);

    budget.inhibit_p(0.5, 0.0);
    expect_near(budget.priority, 0.23);
}

TEST(TruthFunctions, ComputeRepresentativeInferenceResults)
{
    auto truth_a = TruthValue(0.8, 0.9, 1.0);
    auto truth_b = TruthValue(0.5, 0.6, 1.0);

    auto [deduction_f, deduction_c] = deduction(0.8, 0.5, 0.9, 0.6);
    expect_near(deduction_f, 0.4);
    expect_near(deduction_c, 0.216);

    auto deduced = deduction(truth_a, truth_b);
    expect_near(deduced.f, deduction_f);
    expect_near(deduced.c, deduction_c);

    auto negated = negation(truth_a);
    expect_near(negated.f, 0.2);
    expect_near(negated.c, 0.9);

    auto revised = revision(TruthValue(0.75, 0.5, 1.0), TruthValue(0.25, 0.5, 1.0));
    expect_near(revised.f, 0.5);
    expect_near(revised.c, 2.0 / 3.0);

    auto intersection_result = intersection(truth_a, truth_b);
    expect_near(intersection_result.f, 0.4);
    expect_near(intersection_result.c, 0.54);
}

TEST(TruthEvaluators, ComputeScoringFunctions)
{
    const auto truth_a = TruthValue(0.8, 0.9, 1.0);
    const auto truth_b = TruthValue(0.2, 0.5, 1.0);
    const auto desire = DesireValue(0.7, 0.8, 1.0);

    expect_near(novelty(truth_a, truth_b), std::abs(truth_a.e() - truth_b.e()));
    expect_near(novelty(truth_a), std::abs(truth_a.e() - 0.5));
    expect_near(novelty_v1(truth_a, truth_b), std::sqrt(std::abs(truth_a.e() - truth_b.e()) * truth_a.c));
    expect_near(utility(truth_a), truth_a.e() - 0.5);
    expect_near(achieving_level(truth_a, desire), 1.0 - std::abs(desire.e() - truth_a.e()));
    expect_near(sharpness(truth_a), 2.0 * std::abs(truth_a.e() - 0.5));
    expect_near(reward(0.25, 0.5), 0.3125);
}

} // namespace
} // namespace seqnars::nal

auto main(int argc, char **argv) -> int
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
