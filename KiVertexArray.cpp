#include "KiVertexArray.h"

KiVertexArray::KiVertexArray()
{
    KICALL(glGenVertexArrays(1, &m_id));
}

KiVertexArray::~KiVertexArray()
{
    KICALL(glDeleteVertexArrays(1, &m_id));
}

GLsizei KiVertexArray::SizeOf(GLenum type){
    switch (type)
    {
        case GL_FLOAT: return sizeof(GLfloat);
    }
    return 0;
}

void KiVertexArray::Add(KiVertexBuffer& vb,  KiVertexBufferLayout& vbl)
{
    Bind();
    vb.Bind();
    unsigned int pointer = 0;
    GLsizei stride = vbl.GetStride();
    for(int i = 0; i < vbl.GetSize(); i++)
    {
        KiVertexBufferElement e = vbl.GetElement(i);
        KICALL(glVertexAttribPointer(
            e.index,
            e.count, 
            e.type, 
            e.normalized, 
            stride, 
            (const void *)pointer
        ));
        KICALL(glEnableVertexAttribArray(e.index));
        pointer += e.count * SizeOf(e.type);
    }
}

void KiVertexArray::Bind()
{
    KICALL(glBindVertexArray(m_id));
}

void KiVertexArray::Unbind()
{
    KICALL(glBindVertexArray(0));
}