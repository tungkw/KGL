#ifndef __KGL_VERTEX_BUFFER_H
#define __KGL_VERTEX_BUFFER_H
#include "Header.h"
#include "Logger.h"

namespace kgl
{

class VertexBuffer{
private:
    unsigned int m_id;
public:
    VertexBuffer(const void *data, unsigned int size);
    ~VertexBuffer();
    void 
    void Bind();
    void Unbind();
};
    
} // namespace kgl

#endif