#ifndef GRAPH_WINDOW_HPP
#define GRAPH_WINDOW_HPP


#include <string_view>

#include "ShishGL/ShishGL.hpp"
using namespace ShishGL;


namespace SortAnalyser {

    class GraphWindow : public ShishGL::Window {
    public:

        struct Curve {
            Color line_color;
            std::vector<Vector2<double>> points;
        };

        GraphWindow() = delete;

        GraphWindow(const Vector2<int>& pos, const Vector2<size_t>& size,
                    const std::string_view& graph_description);

        ~GraphWindow() override = default;

        uint64_t initCurve(const Color& color);

        void addPoint(const uint64_t& curve_id, const Vector2<double>& point);

        void clear();

    private:

        const std::string_view description;

        static constexpr double GAP_PROPORTION = 0.1; // in [0; 0.5]

        std::vector<Curve> curves;

        Vector2<double> current_min = { +std::numeric_limits<double>::infinity(),
                                        +std::numeric_limits<double>::infinity() },
                        current_max = { -std::numeric_limits<double>::infinity(),
                                        -std::numeric_limits<double>::infinity() };

        void onRender() override;

        void onReshape(int width, int height) override;

        static void drawAxes(const Vector2<double>& viewport);

        //

        void onIdle() override {}

        void onEntry(int) override {}

        void onKeyPress(unsigned char, int, int) override {}

        void onMouseClick(int, int, int, int) override {}

        bool getEvent(const Event &) override { return false; }

    };
}


#endif //GRAPH_WINDOW_HPP
