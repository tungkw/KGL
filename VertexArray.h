#ifndef __KGL_VERTEX_ARRAY_H
#define __KGL_VERTEX_ARRAY_H

#include "Header.h"
#include "Logger.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace kgl
{


class VertexArray
{
private:
    unsigned int m_id;
    GLsizei SizeOf(GLenum type);

public:
    VertexArray();
    ~VertexArray();

    void Add(VertexBuffer&, VertexBufferLayout&);
    void Bind();
    void Unbind();
};
    
} // namespace kgl

#endif