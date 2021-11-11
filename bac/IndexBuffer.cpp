#include "IndexBuffer.h"

namespace kgl
{

IndexBuffer::IndexBuffer(const void *data, unsigned int count)
    : m_count(count)
{
    KGLCALL(glGenBuffers(1, &m_id));
    Bind();
    KGLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(GLuint), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer(){
    Unbind();
    KGLCALL(glDeleteBuffers(1, &m_id));
}

void IndexBuffer::Bind(){
    KGLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
}
void IndexBuffer::Unbind(){
    KGLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::GetCount(){
    return m_count;
}
    
} // namespace kgl