#ifndef __KGL_VERTEX_BUFFER_H
#define __KGL_VERTEX_BUFFER_H
#include "Header.h"
#include "Logger.h"

namespace kgl
{

class VertexBuffer{
private:
    unsigned int m_id;
    char * buffer;
    unsigned int size;
    unsigned int capacity;
public:
    VertexBuffer(unsigned int max_size);
    ~VertexBuffer();
    void Add(const void *data, unsigned int size);
    void Clear();
    void Attach();
    void Bind();
    void Unbind();
    unsigned int GetSize() const { return  size; }
};
    
} // namespace kgl

#endif