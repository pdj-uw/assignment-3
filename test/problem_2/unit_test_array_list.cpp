/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "problem_2/array_list.h"
#include "unit_test_list.h"

TEST(problem_2, new_array_list_with_capacity) {
    test_new_list_with_capacity<ArrayList<int>>();
}

TEST(problem_2, arraylist_copy_constructor) {
    test_copy_constructor<ArrayList<int>>();
}

TEST(problem_2, arraylist_push_back) {
    test_push_back<ArrayList<int>>();
}

TEST(problem_2, arraylist_push_front) {
    test_push_front<ArrayList<int>>();
}

TEST(problem_2, arraylist_pop_back) {
    test_pop_back<ArrayList<int>>();
}

TEST(problem_2, arraylist_pop_front) {
    test_pop_front<ArrayList<int>>();
}

TEST(problem_2, arraylist_merge) {
    test_merge_int<ArrayList<int>>();
    test_merge_string<ArrayList<std::string>>();
    test_merge_float<ArrayList<float>>();
}

TEST(problem_2, arraylist_remove) {
    test_remove_primitive_number<ArrayList<int>, int>();
    test_remove_primitive_number<ArrayList<float>, float>();
    test_remove_string<ArrayList<std::string>>();
}

TEST(problem_2, arraylist_equal) {
    test_equal_int<ArrayList<int>>();
    test_equal_string<ArrayList<std::string>>();
}

TEST(problem_2, push_back_arraylist_over_limit) {
    const int CAPACITY = 5;

    // push to its limit
    ArrayList<int> list(CAPACITY);
    fill_list_from_back_with_sequence(CAPACITY, list);
    ASSERT_EQ(CAPACITY, list.size());
    ASSERT_EQ(CAPACITY, list.capacity());

    // continue pushing over its limit
    // nothing should change.
    fill_list_from_back_with_sequence(2 * CAPACITY, list);
    ASSERT_EQ(CAPACITY, list.size());
    ASSERT_EQ(CAPACITY, list.capacity());

    for (int i = 0; i < CAPACITY; i++) {
        ASSERT_EQ(i, list[i]);
    }
}

TEST(problem_2, push_front_arraylist_over_limit) {
    const int CAPACITY = 5;

    // push to its limit
    ArrayList<int> list(CAPACITY);
    for (int i = 0; i < CAPACITY; i++) {
        list.push_front(i);
    }
    ASSERT_EQ(CAPACITY, list.size());
    ASSERT_EQ(CAPACITY, list.capacity());

    // continue pushing over its limit
    // nothing should change
    for (int i = 0; i < CAPACITY * 2; i++) {
        list.push_front(i);
    }
    ASSERT_EQ(CAPACITY, list.size());
    ASSERT_EQ(CAPACITY, list.capacity());

    for (int i = 0; i < CAPACITY; i++) {
        ASSERT_EQ(CAPACITY - i - 1, list[i]);
    }
}

TEST(problem_2, array_list_subscriptor) {
    test_subscriptor_access<ArrayList<int>>();
}

TEST(problem_2, array_list_reverse) {
    test_reverse<ArrayList<int>>();
}
