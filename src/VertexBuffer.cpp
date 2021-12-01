#include "VertexBuffer.h"

namespace kgl
{

VertexBuffer::VertexBuffer(unsigned int max_size)
{
    size = 0;
    buffer = new char[max_size];
    KGLCALL(glGenBuffers(1, &m_id));
}

VertexBuffer::~VertexBuffer()
{
    Unbind();
    KGLCALL(glDeleteBuffers(1, &m_id));
    delete[] buffer;
}

void VertexBuffer::Add(const void *data, unsigned int size)
{
    for (int i = 0 ; i < size; i++)
    {
        buffer[this->size++] = ((char*)data)[i];
    }
}

void VertexBuffer::Attach()
{
    Bind();
    KGLCALL(glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW));
}

void VertexBuffer::Bind()
{
    KGLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_id));
}

void VertexBuffer::Unbind()
{
    KGLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
    
} // namespace kgl