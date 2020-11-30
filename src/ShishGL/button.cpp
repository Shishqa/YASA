#include <cstring>
#include <stdexcept>

#include <GL/freeglut.h>

#include "ShishGL/button.hpp"
#include "ShishGL/log.hpp"
#include "ShishGL/draw.hpp"
#include "ShishGL/event.hpp"

using namespace ShishGL;


Button::Button(const std::string_view& button_label, const Event& click_event,
               const Vector2<int>& position, const Vector2<size_t>& size,
               const ButtonColorScheme& colors)
        : Window(size, position)
        , on_click(click_event)
        , label(button_label)
        , color_scheme(colors)
        , bg_current(color_scheme.bg_default) {}


void Button::onRender() {
    renderBegin(info.size);

    fillWithColor(bg_current);

    displayText( label,
                 {static_cast<double>(info.size.x) / 2,
                  static_cast<double>(info.size.y) / 2},
                 color_scheme.fg_default );

    renderEnd();
}


void Button::onEntry(int state) {

    if (state == GLUT_ENTERED) {
        bg_current = color_scheme.bg_hover;
    } else {
        bg_current = color_scheme.bg_default;
    }

    refresh();
}


void Button::onMouseClick(int button, int state, int, int) {

    if (button != GLUT_LEFT_BUTTON) {
        return;
    }

    switch (state) {
        case GLUT_DOWN:
            bg_current = color_scheme.bg_click;
            EventSystem::addEvent(on_click);
            break;

        case GLUT_UP:
            bg_current = color_scheme.bg_hover;
            break;

        default:
            throw std::runtime_error("Error: unknown state of mouse button\n");
    }

    refresh();
}

