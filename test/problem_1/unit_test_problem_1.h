/*
 * DO NOT MAKE ANY CHANGES
 */

#include "problem_1/books/book_fiction.h"
#include "problem_1/books/book_romance.h"
#include "problem_1/movies/movie_action.h"
#include "problem_1/inventory_manager.h"
#include "gtest/gtest.h"

class MediaEqualTestCase {
public:
    const StoreMediaInterface &media1;
    const StoreMediaInterface &media2;
    const bool expect;

    MediaEqualTestCase(const StoreMediaInterface &media1, const StoreMediaInterface &media2, const bool expect)
            : media1(media1), media2(media2), expect(expect) {}
};

std::string test_case_string(int id1, int id2) {
    return "test case (" + std::to_string(id1) + ", " + std::to_string(id2) + ")";
}

std::string test_case_string(int id) {
    return "test case (" + std::to_string(id) + ")";
}