#pragma once

#define _LIST_BOOST 0
#define _LIST_STD 1
#define SRC_LIST _LIST_BOOST //_LIST_STD

namespace NAL
{
    namespace CONFIG
    {
        constexpr float priority = 0.8;
        constexpr float durability = 0.8;
        constexpr float quality = 0.5;
        constexpr unsigned int num_buckets = 100;
        constexpr unsigned int max_duration = 10000;

        static float f = 1.0;
        constexpr float c = 0.9;
        constexpr float c_judgement = 0.9;
        constexpr float c_goal = 0.9;
        constexpr float k = 1;
        constexpr float p_judgement = 0.8;
        constexpr float d_judgement = 0.5;
        constexpr float p_question = 0.9;
        constexpr float d_question = 0.9;
        constexpr float p_quest = 0.9;
        constexpr float d_quest = 0.9;
        constexpr float p_goal = 0.9;
        constexpr float d_goal = 0.9;
        constexpr float p_feedback = 0.9;
        constexpr float d_feedback = 0.5;
        constexpr float budget_thresh = 0.01;
        constexpr unsigned int nlevels_task_link = 10;
        constexpr unsigned int capacity_task_link = 100;
        constexpr unsigned int nlevels_term_link = 10;
        constexpr unsigned int capacity_term_link = 100;
        constexpr unsigned int capacity_table = 100;

        // constexpr float complexity_unit =1.0 # 1.0 - oo;
        constexpr float quality_min = 0.3;
        constexpr unsigned int cycles_per_duration = 5;
        constexpr unsigned int n_forget_durations = 2;
        constexpr unsigned int cycles_forget = cycles_per_duration * n_forget_durations;
        constexpr unsigned int revision_max_occurence_distance = 10;
        constexpr float truth_epsilon = 0.01;
        constexpr float budget_epsilon = 0.0001;
        constexpr float complexity_unit = 1.0;
        constexpr bool variable_repr_normalized = false;
        constexpr float rate_discount_c = 0.5;
        constexpr float rate_discount_p_internal_exp = 0.1;
        constexpr float rate_discount_d_internal_exp = 0.1;
        constexpr unsigned int temporal_duration = 5;
        constexpr unsigned int n_sequence_attempts = 10;
        constexpr unsigned int n_op_condition_attempts = 10;
        constexpr unsigned int maximum_evidential_base_length = 20000;

    } // namespace CONFIG

} // namespace NAL
