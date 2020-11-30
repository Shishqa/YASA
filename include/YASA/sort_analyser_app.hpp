#ifndef SORT_ANALYSER_APP_HPP
#define SORT_ANALYSER_APP_HPP


#include "../ShishGL/ShishGL.hpp"
using namespace ShishGL;

#include "Sorts/sorting_wrap.hpp"
#include "Sorts/sort_collection.hpp"

#include <algorithm>
#include <string_view>


namespace SortAnalyser {

    struct ButtonDescription {
        std::string_view name;
        int event_signal;
        Color color;
    };

    enum {
        CLEAR_SIGNAL = -100,
        NORMAL_RANGE,
        BIG_RANGE
    };

    constexpr ButtonDescription UTIL_BUTTONS[] = {
            {"Clear",      CLEAR_SIGNAL, WHITE},
            {"Normal rng", NORMAL_RANGE, DARK_SEA_GREEN},
            {"Big range",  BIG_RANGE,    FIRE_BRICK}
    };

    struct Sort {
        std::string_view name;
        SortingWrap stat_function;
        Color color;
        double correction_factor;
    };

    constexpr size_t MIN_ARRAY_SIZE = 0,
                     MAX_ARRAY_SIZE = 1000,
                     NUM_OF_DOTS    = 100,
                     STEP           = (MAX_ARRAY_SIZE - MIN_ARRAY_SIZE) / NUM_OF_DOTS;

    const std::vector<Sort>& Sorts();
}


#endif //SORT_ANALYSER_APP_HPP
