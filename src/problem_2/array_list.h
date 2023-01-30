/*
 * DO NOT TOUCH THIS FILE
 */

#ifndef ARRAY_LIST
#define ARRAY_LIST

#include "list.h"

template<class T>
class ArrayList : public List<T> {
private:
    T *data;
    size_t max_capacity;
    size_t num_of_element;

public:
    ArrayList() = delete;   // disable default constructor

    // constructor
    ArrayList(size_t capacity) : max_capacity(capacity), num_of_element(0) {
        data = new T[capacity];
    }

    // copy constructor
    ArrayList(const ArrayList<T> &other_list) : max_capacity(other_list.max_capacity),
                                                num_of_element(other_list.num_of_element) {
        data = new T[max_capacity];
        for (size_t i = 0; i < other_list.num_of_element; i++) {
            data[i] = other_list.data[i];
        }
    }

    // destructor
    virtual ~ArrayList() {
        delete[]data;
    }

    size_t capacity() const override {
        return max_capacity;
    }

    size_t size() const override {
        return num_of_element;
    }

    T &operator[](size_t index) {
        if (index >= num_of_element) {
            throw std::out_of_range("index out of range");
        }
        return data[index];
    }

    bool operator==(const ArrayList<T> &other_list) {
        // not comparing capacity as eventually array list can be made capacity irrelevant using dynamic allocation
        if (num_of_element != other_list.num_of_element) {
            return false;
        }
        for (int i = 0; i < num_of_element; i++) {
            if (data[i] != other_list.data[i]) {
                return false;
            }
        }
        return true;
    }

    void push_front(const T &value) override;

    void push_back(const T &value) override;

    void pop_back() override;

    void pop_front() override;

    void remove(T &val) override;

    void merge(const List<T> &other) override;

    void reverse_iterative() override;

private:
    void shift_left_to(size_t start) {
        for (size_t i = start; i < num_of_element - 1; i++) {
            data[i] = data[i + 1];
        }
    }

    void swap(size_t i, size_t j) {
        T tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
};

#include "array_list.cpp"

#endif