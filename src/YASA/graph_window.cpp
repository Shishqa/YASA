#include "YASA/sort_analyser_app.hpp"
#include "YASA/graph_window.hpp"
using namespace SortAnalyser;


GraphWindow::GraphWindow(const Vector2<int>& pos, const Vector2<size_t>& size,
                         const std::string_view& graph_description)
        : Window(size, pos)
        , description(graph_description) { }


uint64_t GraphWindow::initCurve(const Color& color) {

    curves.push_back({color, {}});
    return static_cast<uint64_t>(curves.size()) - 1;

}


void GraphWindow::addPoint(const uint64_t& curve_id, const Vector2<double>& point) {

    curves.at(curve_id).points.push_back(point);

    current_min.x = std::min(point.x, current_min.x);
    current_min.y = std::min(point.y, current_min.y);

    current_max.x = std::max(point.x, current_max.x);
    current_max.y = std::max(point.y, current_max.y);

    refresh();
}


void GraphWindow::clear() {

    curves.clear();
    refresh();

    current_min = { +std::numeric_limits<double>::infinity(),
                    +std::numeric_limits<double>::infinity() };
    current_max = { -std::numeric_limits<double>::infinity(),
                    -std::numeric_limits<double>::infinity() };
}


void GraphWindow::onRender() {
    const Vector2<double> viewport = current_max - current_min;
    renderBegin((1.0 + 2 * GAP_PROPORTION) * viewport);

    ShishGL::fillWithColor(BLACK);

    for (const auto& curve : curves) {

        setColor(curve.line_color);
        glLineWidth(3.0f);

        glBegin(GL_LINE_STRIP);
        for (const auto& point : curve.points) {
            glVertex2d(  point.x +        GAP_PROPORTION  * viewport.x,
                       - point.y + (1.0 + GAP_PROPORTION) * viewport.y);
        }
        glEnd();
    }

    displayText(description,
                {viewport.x / 2, viewport.y * GAP_PROPORTION / 2},
                WHITE);

    // TODO: fix bug: axes are not drawn on first render
    drawAxes(viewport);

    renderEnd();
}


void GraphWindow::onReshape(int width, int height) {
    glViewport(0, 0, width, height);
}


void GraphWindow::drawAxes(const Vector2<double>& viewport) {

    setColor(WHITE);
    glLineWidth(2.0f);
    drawLine({GAP_PROPORTION * viewport.x, (1.0 + GAP_PROPORTION) * viewport.y},
              GAP_PROPORTION * viewport);
    drawLine({GAP_PROPORTION * viewport.x, (1.0 + GAP_PROPORTION) * viewport.y},
             {(1.0 + GAP_PROPORTION) * viewport.x, (1.0 + GAP_PROPORTION) * viewport.y});

}
