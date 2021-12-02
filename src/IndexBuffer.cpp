#include "IndexBuffer.h"

namespace kgl
{

IndexBuffer::IndexBuffer(unsigned int max_count)
{
    size = 0;
    capacity = max_count;
    buffer = new unsigned int[max_count];
    KGLCALL(glGenBuffers(1, &m_id));
    Bind();
    KGLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, max_count*sizeof(GLuint), nullptr, GL_DYNAMIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
    Unbind();
    KGLCALL(glDeleteBuffers(1, &m_id));
    delete[] buffer;
}

void IndexBuffer::Add(const unsigned int *data, unsigned int count, unsigned int offset)
{
    for (int i = 0 ; i < count; i++)
    {
        buffer[this->size++] = data[i]+offset;
    }
}

void IndexBuffer::Clear()
{
    size = 0;
}

void IndexBuffer::Attach()
{
    Bind();
    KGLCALL(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size*sizeof(GLuint), buffer));
}

void IndexBuffer::Bind()
{
    KGLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
}

void IndexBuffer::Unbind()
{
    KGLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::GetCount()
{
    return size;
}
    
} // namespace kgl