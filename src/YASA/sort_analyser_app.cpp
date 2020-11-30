#include "YASA/sort_analyser_app.hpp"

using namespace SortAnalyser;


const std::vector<SortAnalyser::Sort>& SortAnalyser::Sorts() {
    static const std::vector<Sort> SORTS {
        {"Bubble Sort", SortingWrap(bubble_sort, fill_random), FIRE_BRICK,        0.2},
        {"Merge Sort",  SortingWrap(merge_sort,  fill_random), MEDIUM_AQUAMARINE, 1.0},
        {"Std Sort",    SortingWrap(std::sort,   fill_random), LAVENDER,          1.0},
        {"Id (sort)",   SortingWrap(id_sort,     fill_random), KHAKI,             1.0}
    };
    return SORTS;
}
