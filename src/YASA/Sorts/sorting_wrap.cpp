#include <stdexcept>

#include "YASA/Sorts/sorting_wrap.hpp"


SortingWrap::SortingWrap(void (*sort)(Iterator, Iterator),
                         void (*fill_array)(Iterator, Iterator))
        : sorting_function(sort)
        , filling_function(fill_array) { }


void SortingWrap::set_func(void (*sort)(Iterator, Iterator)) {
    if (!sort) {
        throw std::runtime_error("Passing NULL pointer to a function");
    }
    sorting_function = sort;
}


Stat SortingWrap::operator()(const size_t& arr_size) const {

    if (!sorting_function) {
        throw std::runtime_error("Passing NULL pointer to a function");
    }

    std::vector<StatWrap<int>> array(arr_size);
    filling_function(array.begin(), array.end());

    StatWrap<int>::reset();
    sorting_function(array.begin(), array.end());

    return StatWrap<int>::stat;
}
