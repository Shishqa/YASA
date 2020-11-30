#ifndef GRAPH_CONTAINER_HPP
#define GRAPH_CONTAINER_HPP

#include "ShishGL/ShishGL.hpp"
using namespace ShishGL;

#include "sort_analyser_app.hpp"
#include "graph_window.hpp"

#include <limits>

namespace SortAnalyser {

    class GraphContainer : public ShishGL::Window {
    public:

        GraphContainer() = delete;

        explicit GraphContainer(const Vector2<int>& pos);

        ~GraphContainer() override = default;

        enum {
            GRAPH_WINDOWS_GAP   = 30,
            GRAPH_WINDOW_WIDTH  = 400,
            GRAPH_WINDOW_HEIGHT = 400,
            CONTAINER_WIDTH     = 3 * GRAPH_WINDOWS_GAP + 2 * GRAPH_WINDOW_WIDTH,
            CONTAINER_HEIGHT    = 2 * GRAPH_WINDOWS_GAP +     GRAPH_WINDOW_WIDTH
        };

    private:

        GraphWindow* assignments_graph;
        GraphWindow* comparisons_graph;

        Sort   curr_sort;
        size_t curr_animation_size;
        uint64_t assignment_curve_id;
        uint64_t comparison_curve_id;
        bool   is_drawing;

        void onRender() override;

        void onIdle() override;

        void onReshape(int width, int height) override;

        bool getEvent(const Event &) override;

        void displaySortStat(const Sort& sort);

        void clear();
    };
}


#endif //GRAPH_CONTAINER_HPP
