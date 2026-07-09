#pragma once

namespace seqnars::nal::config
{
constexpr float F = 1.0;

constexpr float PRIORITY = 0.8;
constexpr float DURABILITY = 0.8;
constexpr float QUALITY = 0.5;
constexpr unsigned int NUM_BUCKETS = 100;
constexpr unsigned int MAX_DURATION = 10000;
constexpr float C = 0.9;
constexpr float C_JUDGEMENT = 0.9;
constexpr float C_GOAL = 0.9;
constexpr float K = 1;
constexpr float P_JUDGEMENT = 0.8;
constexpr float D_JUDGEMENT = 0.5;
constexpr float P_QUESTION = 0.9;
constexpr float D_QUESTION = 0.9;
constexpr float P_QUEST = 0.9;
constexpr float D_QUEST = 0.9;
constexpr float P_GOAL = 0.9;
constexpr float D_GOAL = 0.9;
constexpr float P_FEEDBACK = 0.9;
constexpr float D_FEEDBACK = 0.5;
constexpr float BUDGET_THRESH = 0.01;
constexpr unsigned int NLEVELS_TASK_LINK = 10;
constexpr unsigned int CAPACITY_TASK_LINK = 100;
constexpr unsigned int NLEVELS_TERM_LINK = 10;
constexpr unsigned int CAPACITY_TERM_LINK = 100;
constexpr unsigned int CAPACITY_TABLE = 100;
constexpr float QUALITY_MIN = 0.3;
constexpr unsigned int CYCLES_PER_DURATION = 5;
constexpr unsigned int N_FORGET_DURATIONS = 2;
constexpr unsigned int CYCLES_FORGET = CYCLES_PER_DURATION * N_FORGET_DURATIONS;
constexpr unsigned int REVISION_MAX_OCCURENCE_DISTANCE = 10;
constexpr float TRUTH_EPSILON = 0.01;
constexpr float BUDGET_EPSILON = 0.0001;
constexpr float COMPLEXITY_UNIT = 1.0;
constexpr bool VARIABLE_REPR_NORMALIZED = false;
constexpr float RATE_DISCOUNT_C = 0.5;
constexpr float RATE_DISCOUNT_P_INTERNAL_EXP = 0.1;
constexpr float RATE_DISCOUNT_D_INTERNAL_EXP = 0.1;
constexpr unsigned int TEMPORAL_DURATION = 5;
constexpr unsigned int N_SEQUENCE_ATTEMPTS = 10;
constexpr unsigned int N_OP_CONDITION_ATTEMPTS = 10;
constexpr unsigned int MAXIMUM_EVIDENTIAL_BASE_LENGTH = 20000;
} // namespace seqnars::nal::config
