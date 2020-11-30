#include <stdexcept>


#include <GL/glew.h>
#include <GL/freeglut.h>


#include "ShishGL/essential.hpp"
#include "ShishGL/log.hpp"


int ShishGL::init(int* argc_ptr, char** argv) {

#ifdef DEBUG
    if (!openLog()) {
        throw std::runtime_error("Error: failed to open log file!");
    }
#endif

    printLog("ShishGL initialization started");

    glutInit(argc_ptr, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

    printLog("ShishGL initialized");

    return 0;
}


int ShishGL::enterMainLoop() {
    glutMainLoop();
    return 0;
}


void ShishGL::terminate() {

    printLog("Terminating ShishGL");

#ifdef DEBUG
    closeLog();
#endif

}
