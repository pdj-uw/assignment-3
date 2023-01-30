/*
 * DO NOT TOUCH THIS FILE
 */

#pragma once

#include <string>
#include "../store_media_interface.h"

class Movie : public StoreMediaInterface {
protected:
    std::string title;
    std::string rating;
public:
    Movie(const std::string &title, const std::string &rating, const size_t id) : title(title), rating(rating) {
        inventory_id = id;
    }

    Movie(const Movie &) = delete;

    Movie(const Movie &other_movie, const size_t id) {
        inventory_id = id;
        this->title = other_movie.title;
        this->rating = other_movie.rating;
    }

    virtual ~Movie() {}
};