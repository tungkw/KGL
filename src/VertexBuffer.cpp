
#include "VertexBuffer.h"

namespace kgl
{

VertexBuffer::VertexBuffer(unsigned int max_size)
{
    size = 0;
    capacity = max_size;
    buffer = new char[max_size];
    KGLCALL(glGenBuffers(1, &m_id));
    Bind();
    KGLCALL(glBufferData(GL_ARRAY_BUFFER, capacity, nullptr, GL_DYNAMIC_DRAW));
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

void VertexBuffer::Clear()
{
    size = 0;
}

void VertexBuffer::Attach()
{
    Bind();
    KGLCALL(glBufferSubData(GL_ARRAY_BUFFER, 0, capacity, (const void *)buffer));
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