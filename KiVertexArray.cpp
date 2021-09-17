#include <KiVertexArray.h>

KiVertexArray::KiVertexArray()
{
    KICALL(glGenVertexArrays(1, &m_id));
}

KiVertexArray::~KiVertexArray()
{
    KICALL(glDeleteVertexArrays(1, &m_id));
}

void KiVertexArray::Add(KiVertexBuffer vb,  KiVertexBufferLayout vbl)
{
    Bind();
    vb.Bind();
    unsigned int pointer = 0;
    for(int i = 0; i < vbl.elements.size(); i++)
    {
        KICALL(glVertexAttribPointer(
            i, 
            vbl.elements[i].size, 
            vbl.elements[i].type, 
            vbl.elements[i].normalized, 
            vbl.GetStride(), 
            (const void *)pointer
        ));
        KICALL(glEnableVertexAttribArray(i));
        pointer += vbl.elements[i].size;
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