#include <cstdio>
#include <cstdarg>

#include "ShishGL/log.hpp"


FILE* ShishGL::LOG_FILE = nullptr;


enum {
    LOG_SUCCESS = 1,
    LOG_FAILURE = 0
};


int ShishGL::openLog() {

    LOG_FILE = fopen(".ShishGL_log", "w");

    return (LOG_FILE ? LOG_SUCCESS : LOG_FAILURE);
}


int ShishGL::closeLog() {

    return fclose(LOG_FILE);
}


// TODO: add urgency!
__attribute__((format(printf, 1, 2)))
int ShishGL::printLog(const char* format, ...) {
#ifdef DEBUG
    fprintf(LOG_FILE, "### ");

    va_list arg_list;
    va_start(arg_list, format);
    int res = vfprintf(LOG_FILE, format, arg_list);
    va_end(arg_list);

    fprintf(LOG_FILE, "\n");
    fflush(LOG_FILE);

    return res;
#else
    return 0;
#endif
}
