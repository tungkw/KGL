#include "VertexBuffer.h"

namespace kgl
{

VertexBuffer::VertexBuffer(const void *data, unsigned int size){
    KGLCALL(glGenBuffers(1, &m_id));
    Bind();
    KGLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer(){
    Unbind();
    KGLCALL(glDeleteBuffers(1, &m_id));
}

void VertexBuffer::Bind(){
    KGLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_id));
}
void VertexBuffer::Unbind(){
    KGLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
    
} // namespace kgl