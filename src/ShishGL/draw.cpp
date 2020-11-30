#include "ShishGL/draw.hpp"

#include <GL/freeglut.h>


void ShishGL::renderBegin(const Vector2<double>& viewport) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(0.f, viewport.x, viewport.y, 0.f, 0.f, 1.f);
}


void ShishGL::renderBegin(const Vector2<size_t>& viewport) {
    renderBegin(Vector2<double>{
        static_cast<double>(viewport.x),
        static_cast<double>(viewport.y)
    });
}


void ShishGL::renderEnd() {
    glutSwapBuffers();
}


void ShishGL::fillWithColor(const Color& color) {
    glClearColor(static_cast<GLclampf>(color.r) / 255.0f,
                 static_cast<GLclampf>(color.g) / 255.0f,
                 static_cast<GLclampf>(color.b) / 255.0f,
                 static_cast<GLclampf>(color.a) / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


void ShishGL::setColor(const Color& color) {
    glColor4ub(color.r, color.g, color.b, color.a);
}


size_t ShishGL::displayText(const std::string_view& text,
                            const Vector2<double>& position,
                            const Color& color) {

    setColor(color);

    static const size_t FONT_HEIGHT = 15,
                        FONT_WIDTH  = 9;

    size_t bitmap_width = FONT_WIDTH * text.size();

    glRasterPos2d(position.x - static_cast<double>(bitmap_width) / 2,
                  position.y + static_cast<double>(FONT_HEIGHT)  / 2);

    for(const auto& symbol : text) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, symbol);
    }

    return bitmap_width;
}


void ShishGL::drawLine(const Vector2<double>& begin,
                       const Vector2<double>& end) {
    glBegin(GL_LINES);
        glVertex2d(begin.x, begin.y);
        glVertex2d(end.x,   end.y);
    glEnd();
}
