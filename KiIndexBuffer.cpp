#include "KiIndexBuffer.h"


KiIndexBuffer::KiIndexBuffer(const void *data, unsigned int count)
    : m_count(count)
{
    KICALL(glGenBuffers(1, &m_id));
    Bind();
    KICALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(GLuint), data, GL_STATIC_DRAW));
}

KiIndexBuffer::~KiIndexBuffer(){
    Unbind();
    KICALL(glDeleteBuffers(1, &m_id));
}

void KiIndexBuffer::Bind(){
    KICALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
}
void KiIndexBuffer::Unbind(){
    KICALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int KiIndexBuffer::GetCount(){
    return m_count;
}