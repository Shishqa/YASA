#ifndef SORT_COLLECTION_HPP
#define SORT_COLLECTION_HPP


#include <cstdio>
#include <cstddef>
#include <utility>
#include <stack>

#include <random>
#include <ctime>


template <typename RandomIter>
void fill_random(RandomIter begin, RandomIter end) {

    static const int MAX_INT_BOUND = 1024;
    srand(static_cast<uint32_t>(time(nullptr)));

    for (RandomIter i = begin; i < end; ++i) {
        *i = rand() % MAX_INT_BOUND;
    }
}


template <typename RandomIter>
void merge_sort(RandomIter begin, RandomIter end) {

    const size_t length = end - begin;

    if (length <= 1) {
        return;
    }

    const size_t middle = (length + 1) / 2;

    merge_sort(begin, begin + middle);
    merge_sort(begin + middle, end);

    std::stack<typename RandomIter::value_type> left, right;

    for (RandomIter i = begin; i < begin + middle; ++i) {
        left.push(*i);
    }
    for (RandomIter i = begin + middle; i < end; ++i) {
        right.push(*i);
    }

    RandomIter it = begin;
    for (; it < end && !left.empty() && !right.empty(); ++it) {
        if (left.top() < right.top()) {
            *it = left.top();
            left.pop();
        } else {
            *it = right.top();
            right.pop();
        }
    }
    while (!left.empty()) {
        *it = left.top();
        ++it;
        left.pop();
    }
    while (!right.empty()) {
        *it = right.top();
        ++it;
        right.pop();
    }
}


template <typename RandomIter>
void bubble_sort(RandomIter begin, RandomIter end) {

    const size_t arr_size = end - begin;

    for (size_t i = 0; i < arr_size; ++i) {
        for (size_t j = 0; j < arr_size - i - 1; ++j) {
            if (begin[j + 1] < begin[j]) {
                std::swap(begin[j + 1], begin[j]);
            }
        }
    }
}


template <typename RandomIter>
void id_sort(RandomIter begin, RandomIter end) {

    const size_t MULTIPLIER = 10;
    const size_t ID = MULTIPLIER * (end - begin);

    for (size_t i = 0; i < ID; ++i) {
        *begin < *begin;
        *begin = 0;
    }

}


#endif //SORT_COLLECTION_HPP
