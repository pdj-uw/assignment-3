/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "problem_2/linked_list.h"
#include "unit_test_list.h"

TEST(problem_2, new_linked_list) {
    test_new_list_with_capacity<LinkedList<int>>();
}

TEST(problem_2, linkedlist_copy_constructor) {
    test_copy_constructor<LinkedList<int>>();
}

TEST(problem_2, linkedlist_push_back) {
    test_push_back<LinkedList<int>>();
}

TEST(problem_2, linkedlist_push_front) {
    test_push_front<LinkedList<int>>();
}

TEST(problem_2, linkedlist_pop_back) {
    test_pop_back<LinkedList<int>>();
}

TEST(problem_2, linkedlist_pop_front) {
    test_pop_front<LinkedList<int>>();
}

TEST(problem_2, linkedlist_merge) {
    test_merge_int<LinkedList<int>>();
    test_merge_string<LinkedList<std::string>>();
    test_merge_float<LinkedList<float>>();
}

TEST(problem_2, linkedlist_remove) {
    test_remove_primitive_number<LinkedList<int>, int>();
    test_remove_primitive_number<LinkedList<float>, float>();
    test_remove_string<LinkedList<std::string>>();
}

TEST(problem_2, linkedlist_equal) {
    test_equal_int<LinkedList<int>>();
    test_equal_string<LinkedList<std::string>>();
}

TEST(problem_2, linked_list_subscriptor) {
    test_subscriptor_access<LinkedList<int>>();
}

TEST(problem_2, linked_list_reverse) {
    test_reverse<LinkedList<int>>();
}