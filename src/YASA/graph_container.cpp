#include "ShishGL/ShishGL.hpp"
#include "YASA/graph_container.hpp"
#include "YASA/graph_window.hpp"

using namespace SortAnalyser;


GraphContainer::GraphContainer(const Vector2<int>& pos)
        : ShishGL::Window({GRAPH_WINDOW_WIDTH * 2 + GRAPH_WINDOWS_GAP * 3,
                           GRAPH_WINDOW_HEIGHT + GRAPH_WINDOWS_GAP * 2},
                          pos)
        , assignments_graph(nullptr)
        , comparisons_graph(nullptr)
        , curr_sort(Sorts()[0])
        , curr_animation_size(0)
        , assignment_curve_id(0)
        , comparison_curve_id(0)
        , is_drawing(false) {

    assignments_graph = attach<GraphWindow>(
            Vector2<int>{GRAPH_WINDOWS_GAP, GRAPH_WINDOWS_GAP},
            Vector2<size_t>{GRAPH_WINDOW_WIDTH, GRAPH_WINDOW_HEIGHT},
            "Assignments"
            );

    comparisons_graph = attach<GraphWindow>(
            Vector2<int>{GRAPH_WINDOWS_GAP * 2 + GRAPH_WINDOW_WIDTH, GRAPH_WINDOWS_GAP},
            Vector2<size_t>{GRAPH_WINDOW_WIDTH, GRAPH_WINDOW_HEIGHT},
            "Comparisons"
            );
}


void GraphContainer::onRender() {
    renderBegin(info.size);

    ShishGL::fillWithColor(DARK_SLATE_GRAY);

    renderEnd();
}


void GraphContainer::onReshape(int width, int height) {
    glViewport(0, 0, width, height);
}


bool GraphContainer::getEvent(const Event& event) {

    switch (event.event_code) {

        case CLEAR_SIGNAL:
            clear();
            break;

        case NORMAL_RANGE:
            printf("not yet implemented: normal range [0; 1000] (step = 10)\n");
            break;

        case BIG_RANGE:
            printf("not yet implemented: big range [0; 100000] (step = 1000)\n");
            break;

        default:

            if (event.event_code >= static_cast<int>(Sorts().size()) ||
                0 > event.event_code) {
                printLog("Warning: tried to display curve with id %d", event.event_code);
                return false;
            } else if (is_drawing) {
                return false;
            }

            displaySortStat(Sorts()[event.event_code]);
    }

    return true;
}


void GraphContainer::clear() {

    assignments_graph->clear();
    comparisons_graph->clear();
    is_drawing = false;

}


void GraphContainer::displaySortStat(const Sort& sort) {

    assignment_curve_id = assignments_graph->initCurve(sort.color);
    comparison_curve_id = comparisons_graph->initCurve(sort.color);

    is_drawing = true;
    curr_sort  = sort; // TODO:: implement copy constructor

    curr_animation_size = MIN_ARRAY_SIZE;
}


void GraphContainer::onIdle() {

    if (!is_drawing) {
        return;
    }

    auto MAX_SIZE = static_cast<size_t>(curr_sort.correction_factor * static_cast<double>(MAX_ARRAY_SIZE));

    if (curr_animation_size >= MAX_SIZE) {
        is_drawing = false;
        return;
    }

    Stat stat = curr_sort.stat_function(curr_animation_size);

    assignments_graph->addPoint(assignment_curve_id, {static_cast<double>(curr_animation_size),
                                            static_cast<double>(stat.assign_cnt)});

    comparisons_graph->addPoint(comparison_curve_id, {static_cast<double>(curr_animation_size),
                                             static_cast<double>(stat.compare_cnt)});

    curr_animation_size += STEP;
}
