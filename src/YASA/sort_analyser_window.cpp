#include "YASA/sort_analyser_window.hpp"
#include "YASA/graph_container.hpp"
#include "ShishGL/ShishGL.hpp"

using namespace SortAnalyser;


SortAnalyserWindow::SortAnalyserWindow()
        : ShishGL::Window({1024, 720}, {0, 0}, "Sort Analyser") {

    static const size_t
            BUTTON_WIDTH = 100,
            BUTTON_HEIGHT = 40,
            BUTTON_GAP = 10;

    static const int GAP = static_cast<int>(info.size.x - GraphContainer::CONTAINER_WIDTH) / 2;

    Window* graphs = attach<GraphContainer>(Vector2<int>{GAP, GAP});

    Vector2<size_t> button_size{
        BUTTON_WIDTH,
        BUTTON_HEIGHT
    };
    Vector2<int> button_pos{
        GAP,
        static_cast<int>(GAP + GraphContainer::CONTAINER_HEIGHT + BUTTON_GAP)
    };
    ButtonColorScheme color_scheme = {GREEN, MINT_CREAM, WHITE, BLACK};

    for (size_t i = 0; i < Sorts().size(); ++i) {

        color_scheme.bg_default = Sorts()[i].color;

        attach<ShishGL::Button>(
                Sorts()[i].name,
                Event{graphs, static_cast<int>(i)},
                button_pos, button_size,
                color_scheme
        );

        button_pos += Vector2<int>{static_cast<int>(button_size.x + BUTTON_GAP), 0};
    }

    button_pos.x   = GAP;
    button_pos.y  += BUTTON_HEIGHT + BUTTON_GAP;
    button_size.x *= 2;

    for (const auto& util : UTIL_BUTTONS) {

        color_scheme.bg_default = util.color;

        attach<ShishGL::Button>(
                util.name,
                Event{graphs, util.event_signal},
                button_pos, button_size,
                color_scheme
        );

        button_pos += Vector2<int>{static_cast<int>(button_size.x + BUTTON_GAP), 0};
    }
}


void SortAnalyserWindow::onRender() {
    renderBegin(info.size);

    ShishGL::fillWithColor(DIM_GRAY);

    renderEnd();
}


void SortAnalyserWindow::onReshape(int width, int height) {
    glViewport(0, 0, width, height);
}
