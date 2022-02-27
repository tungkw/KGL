#ifndef __KGL_LOGGER_H
#define __KGL_LOGGER_H

#include <iostream>
#include <cstdlib>
#include "Header.h"

namespace kgl
{
    
#define KGL_LOG_ERROR(x) { if(GLCheckError(#x, __FILE__, __LINE__)) { std::cin.get(); exit(-1); } } 
#define KGLCALL(x)  { \
                        GLClearError(); \
                        x; \
                        KGL_LOG_ERROR(x); \
                    }

void GLClearError();
bool GLCheckError(const char *func_name, const char *file, int line);
    
} // namespace name


#endif