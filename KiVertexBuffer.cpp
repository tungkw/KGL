#include "KiVertexBuffer.h"


KiVertexBuffer::KiVertexBuffer(const void *data, unsigned int size){
    KICALL(glGenBuffers(1, &m_id));
    Bind();
    KICALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

KiVertexBuffer::~KiVertexBuffer(){
    Unbind();
    KICALL(glDeleteBuffers(1, &m_id));
}

void KiVertexBuffer::Bind(){
    KICALL(glBindBuffer(GL_ARRAY_BUFFER, m_id));
}
void KiVertexBuffer::Unbind(){
    KICALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}