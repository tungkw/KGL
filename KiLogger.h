#ifndef __KI_LOGGER_H
#define __KI_LOGGER_H
#include "KiHeader.h"
#include <iostream>
#include <cstdlib>

#define GL_LOG_ERROR(x) {if(GLCheckError(#x, __FILE__, __LINE__)) {std::cin.get();exit(-1);}} 
#define KICALL(x) {\
    GLClearError();\
    x;\
    GL_LOG_ERROR(x);\
}\

void GLClearError();
bool GLCheckError(const char *func_name, const char *file, int line);

#endif