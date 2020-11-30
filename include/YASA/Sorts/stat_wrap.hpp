#ifndef STAT_WRAP_HPP
#define STAT_WRAP_HPP

#include <cstdio>
#include <iostream>

#include "stat.hpp"


template <typename T>
struct StatWrap {

    T value;

    static Stat stat;


    static void reset();
    static void print_stat();

    StatWrap();

    StatWrap(T value);

    StatWrap(const StatWrap<T>& other);
    StatWrap& operator=(const StatWrap<T>& other);

    StatWrap(StatWrap<T>&& other);
    StatWrap& operator=(StatWrap<T>&& other);
};


template <typename T>
bool operator<(const StatWrap<T>& a, const StatWrap<T>& b);

template <typename T>
std::ostream& operator<<(std::ostream& out, const StatWrap<T>& value);


//==============================================================================


template <typename T>
Stat StatWrap<T>::stat = {0, 0};


template <typename T>
StatWrap<T>::StatWrap() : value(T()) {}


template <typename T>
StatWrap<T>::StatWrap(T val) : value(val) {}


template <typename T>
StatWrap<T>::StatWrap(const StatWrap<T>& other) {
    ++stat.assign_cnt;
    value = other.value;
}


template <typename T>
StatWrap<T>& StatWrap<T>::operator=(const StatWrap<T>& other) {
    if (&other == this) {
        return *this;
    }
    ++stat.assign_cnt;
    value = other.value;
    return *this;
}


template <typename T>
StatWrap<T>::StatWrap(StatWrap<T>&& other) {
    ++stat.assign_cnt;
    value = std::move(other.value);
}


template <typename T>
StatWrap<T>& StatWrap<T>::operator=(StatWrap<T>&& other) {
    ++stat.assign_cnt;
    value = std::move(other.value);
    return *this;
}


template <typename T>
void StatWrap<T>::reset() {
    stat.assign_cnt  = 0;
    stat.compare_cnt = 0;
}


template <typename T>
void StatWrap<T>::print_stat() {
    printf("%lu;%lu\n",
           stat.assign_cnt, stat.compare_cnt);
}


template <typename T>
bool operator<(const StatWrap<T>& a, const StatWrap<T>& b) {
    ++StatWrap<T>::stat.compare_cnt;
    return (a.value < b.value);
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const StatWrap<T>& item) {
    out << item.value;
    return out;
}


#endif //STAT_WRAP_HPP
