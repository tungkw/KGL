
#include "VertexArray.h"

namespace kgl
{


VertexArray::VertexArray()
{
    KGLCALL(glGenVertexArrays(1, &m_id));
}

VertexArray::~VertexArray()
{
    KGLCALL(glDeleteVertexArrays(1, &m_id));
}

GLsizei VertexArray::SizeOf(GLenum type){
    switch (type)
    {
        case GL_FLOAT: return sizeof(GLfloat);
    }
    return 0;
}

void VertexArray::Add(VertexBuffer& vb,  VertexBufferLayout vbl)
{
    Bind();
    vb.Bind();
    unsigned int pointer = 0;
    GLsizei stride = vbl.GetStride();
    for(int i = 0; i < vbl.GetSize(); i++)
    {
        VertexBufferElement e = vbl.GetElement(i);
        KGLCALL(glVertexAttribPointer(
            e.index,
            e.count, 
            e.type, 
            e.normalized, 
            stride, 
            (const void *)pointer
        ));
        KGLCALL(glEnableVertexAttribArray(e.index));
        pointer += e.placehold;
    }
}

void VertexArray::Bind()
{
    KGLCALL(glBindVertexArray(m_id));
}

void VertexArray::Unbind()
{
    KGLCALL(glBindVertexArray(0));
}

}