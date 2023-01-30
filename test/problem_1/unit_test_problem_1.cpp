/*
 * DO NOT MAKE ANY CHANGES
 */

#include "unit_test_problem_1.h"
#include "problem_1/movies/movie_comedy.h"

TEST(problem_1, singleton_inventory_manager) {
    InventoryManager &manager_first = InventoryManager::manager();
    for (int i = 0; i < 50; i++) {

        // InventoryManager &bad_manager = new InventoryManager();  // won't compile
        InventoryManager &manager = InventoryManager::manager();
        ASSERT_EQ(&manager_first, &manager) << test_case_string(i);
    }
}

TEST(problem_1, unique_id) {
    std::set<size_t> ids;
    for (int i = 0; i < 50; i++) {
        size_t new_id = InventoryManager::manager().get_new_id();
        ASSERT_TRUE(ids.find(new_id) == ids.end()) << test_case_string(i);
        ids.insert(new_id);
    }
}

TEST(problem_1, calculate_late_fees_base_rule) {
    std::vector<StoreMediaInterface *> medias = {
            new BookFiction("t1", "a", "g", 1),
            new BookFiction("t2", "a", "g", 13),
            new BookRomance("t3", "a", "g", 2),
            new BookRomance("t4", "a", "g", 26),
    };

    for (int i = 0; i < medias.size(); i++) {
        auto &media = medias[i];

        // generate the condition to apply the mercy rule
        bool has_mercy = (i < 2) && (media->get_inventory_id() % 13 == 0);

        size_t days = 10;
        for (int j = 0; j < days; j++) {
            int num_of_day = j;
            // collect expect and actual fees results
            int expect = has_mercy ? 0 : num_of_day *
                                         media->get_late_fee_per_day_in_dollar();
            int actual = media->calculate_late_fees(num_of_day);
            ASSERT_EQ(expect, actual) << test_case_string(i, j);
        }
    }
    for (auto media: medias) {
        delete media;
    }
}

TEST(problem_1, calculate_late_fees_movie_action) {
    std::vector<StoreMediaInterface *> medias = {
            new MovieAction("t1", "r1", 1),
            new MovieAction("t2", "r2", 13),
            new MovieAction("t2: pulp fiction", "r2", 3),
            new MovieAction("t2: pulp fiction", "r2", 26),
    };

    for (auto media: medias) {
        size_t days = 10;
        for (int i = 0; i < days; i++) {
            int num_of_day = i;
            // collect expect and actual fees results
            int base_fee = num_of_day * media->get_late_fee_per_day_in_dollar();
            int fee = (num_of_day >= 5) ? 2 * base_fee : base_fee;

            bool has_mercy = media->get_inventory_id() % 13 == 0 &&
                             ((MovieAction *) media)->action_movie_mercy_rule_apply();
            int expect = has_mercy ? 0 : fee;
            int actual = media->calculate_late_fees(num_of_day);
            ASSERT_EQ(expect, actual) << test_case_string(i);
        }
    }
    for (auto media: medias) {
        delete media;
    }
}

TEST(problem_1, calculate_late_fees_movie_comedy) {
    std::vector<StoreMediaInterface *> medias = {
            new MovieComedy("t1", "r1", 1),
            new MovieComedy("t2", "r2", 13),
            new MovieComedy("t2: pulp fiction", "r2", 3),
            new MovieComedy("t2: pulp fiction", "r2", 26),
    };

    for (int i = 0; i < medias.size(); i++) {
        auto &media = medias[i];
        size_t days = 10;
        for (int j = 0; j < days; j++) {
            int num_of_day = j;
            // collect expect and actual fees results
            int fee;
            int late_fee_per_day = media->get_late_fee_per_day_in_dollar();
            if (num_of_day == 0) {
                fee = 0;
            } else if (num_of_day <= 5) {
                fee = late_fee_per_day;
            } else if (num_of_day <= 10) {
                fee = late_fee_per_day * 2;
            } else {
                fee = late_fee_per_day * num_of_day;
            }
            ASSERT_EQ(fee, media->calculate_late_fees(num_of_day)) << test_case_string(i, j);
        }
    }
    for (auto media: medias) {
        delete media;
    }
}

TEST(problem_1, media_equal) {
    std::vector<MediaEqualTestCase> cases = {
            MediaEqualTestCase(BookFiction("t", "a", "g", 1), BookFiction("t", "a", "g", 1), true),
            MediaEqualTestCase(BookFiction("t", "a", "g", 1), BookFiction("x", "y", "z", 1), true),
            MediaEqualTestCase(BookFiction("t", "a", "g", 1), BookFiction("t", "a", "g", 2), false),
            MediaEqualTestCase(BookFiction("t", "a", "g", 1), BookFiction("x", "y", "z", 2), false),
            MediaEqualTestCase(BookRomance("t", "a", "g", 6), BookRomance("t", "a", "g", 6), true),
            MediaEqualTestCase(BookRomance("t", "a", "g", 6), BookRomance("x", "y", "z", 6), true),
            MediaEqualTestCase(BookRomance("t", "a", "g", 6), BookRomance("t", "a", "g", 9), false),
            MediaEqualTestCase(BookRomance("t", "a", "g", 6), BookRomance("x", "y", "z", 9), false),
            MediaEqualTestCase(BookFiction("t", "a", "g", 3), BookRomance("t", "a", "g", 3), true),
            MediaEqualTestCase(BookFiction("t", "a", "g", 3), BookRomance("x", "y", "z", 3), true),
            MediaEqualTestCase(BookFiction("t", "a", "g", 3), BookRomance("t", "a", "g", 5), false),
            MediaEqualTestCase(BookFiction("t", "a", "g", 3), BookRomance("x", "y", "z", 5), false),
            MediaEqualTestCase(BookRomance("t", "a", "g", 3), BookFiction("t", "a", "g", 3), true),
            MediaEqualTestCase(BookRomance("t", "a", "g", 3), BookFiction("x", "y", "z", 3), true),
            MediaEqualTestCase(BookRomance("t", "a", "g", 3), BookFiction("t", "a", "g", 5), false),
            MediaEqualTestCase(BookRomance("t", "a", "g", 3), BookFiction("x", "y", "z", 5), false),
            MediaEqualTestCase(MovieAction("t", "r", 1), MovieAction("t", "r", 1), true),
            MediaEqualTestCase(MovieAction("t", "r", 1), MovieAction("p", "q", 1), true),
            MediaEqualTestCase(MovieAction("t", "r", 1), MovieAction("t", "r", 2), false),
            MediaEqualTestCase(MovieAction("t", "r", 1), MovieAction("p", "q", 2), false),
            MediaEqualTestCase(MovieComedy("t", "r", 6), MovieComedy("t", "r", 6), true),
            MediaEqualTestCase(MovieComedy("t", "r", 6), MovieComedy("p", "q", 6), true),
            MediaEqualTestCase(MovieComedy("t", "r", 6), MovieComedy("t", "r", 9), false),
            MediaEqualTestCase(MovieComedy("t", "r", 6), MovieComedy("p", "q", 9), false),
            MediaEqualTestCase(MovieAction("t", "r", 3), MovieComedy("t", "r", 3), true),
            MediaEqualTestCase(MovieAction("t", "r", 3), MovieComedy("p", "q", 3), true),
            MediaEqualTestCase(MovieAction("t", "r", 3), MovieComedy("t", "r", 5), false),
            MediaEqualTestCase(MovieAction("t", "r", 3), MovieComedy("p", "q", 5), false),
            MediaEqualTestCase(MovieComedy("t", "r", 3), MovieAction("t", "r", 3), true),
            MediaEqualTestCase(MovieComedy("t", "r", 3), MovieAction("p", "q", 3), true),
            MediaEqualTestCase(MovieComedy("t", "r", 3), MovieAction("t", "r", 5), false),
            MediaEqualTestCase(MovieComedy("t", "r", 3), MovieAction("p", "q", 5), false),
    };
    for (int i = 0; i < cases.size(); i++) {
        const MediaEqualTestCase &test_case = cases[i];
        ASSERT_EQ(test_case.expect, test_case.media1 == test_case.media2);
    }
}