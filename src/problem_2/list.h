/*
 * DO NOT TOUCH THIS FILE
 */

#pragma once

template<class T>
class List {
public:
    // return the capacity of the list
    virtual size_t capacity() const = 0;

    // return the number of elements in the list
    virtual size_t size() const = 0;

    // inserts an element to the beginning
    virtual void push_front(const T &value) = 0;

    // adds an element to the end
    virtual void push_back(const T &value) = 0;

    // removes the last element
    virtual void pop_back() = 0;

    // removes the first element
    virtual void pop_front() = 0;

    // add an element to the end of the list
    virtual void remove(T &val) = 0;

    // merges two sorted lists
    // O(n^2) using an insert function
    // O(n) merge directly
    virtual void merge(const List<T> &other) = 0;

    // reverse using iteration
    virtual void reverse_iterative() = 0;

    virtual ~List() {}
};