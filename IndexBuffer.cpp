#include "IndexBuffer.h"

namespace kgl
{

IndexBuffer::IndexBuffer(unsigned int max_count)
{
    KGLCALL(glGenBuffers(1, &m_id));
    buffer = new unsigned int[max_count];
    size = 0;
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

void IndexBuffer::Attach()
{
    Bind();
    KGLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size*sizeof(GLuint), buffer, GL_STATIC_DRAW));
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