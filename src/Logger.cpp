
#include "Logger.h"

namespace kgl
{
    
void GLClearError()
{
    while(glGetError() != GL_NO_ERROR );
}

bool GLCheckError(const char *func_name, const char *file, int line)
{
    GLenum error_code;
    while(error_code = glGetError()){
        std::cout << "[ERROR] " << error_code << " " << file << " " << "line " << line << " " << func_name << std::endl;
        return true;
    }
    return false;
}

}
