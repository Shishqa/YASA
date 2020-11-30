#include <cstdio>
#include <stdexcept>

#include <GL/freeglut.h>

#include "ShishGL/window_manager.hpp"
#include "ShishGL/log.hpp"

using namespace ShishGL;


Window::Window(const Vector2<size_t>& size, const Vector2<int>& pos,
               const std::string_view& win_title)
        : info({win_title, ID_UNDEFINED, pos, size}) {
    printLog("Created window %p at (%d, %d) %lux%lupx",
             reinterpret_cast<void*>(this), pos.x, pos.y, size.x, size.y);
}


Window::~Window() {
    for (auto& win : subwindows) {
        delete win;
    }
}


void Window::display() {
    WindowManager::makeActive(this);
}


void Window::close() {
    WindowManager::makeInactive(this);
}


void Window::dump() {
    printf("{ %d ", info.id);
    for (auto& window : subwindows) {
        window->dump();
    }
    printf("}");
}


const Window::WindowInfo& Window::getInfo() {
    return info;
}


void Window::refresh() const {
    glutSetWindow(info.id);
    glutPostRedisplay();
}
