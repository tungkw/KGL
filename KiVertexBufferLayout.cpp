#include "KiVertexBufferLayout.h"




template<>
void KiVertexBufferLayout::Push<GLfloat>(GLsizei count)
{
    elements.push_back({elements.size(), GL_FLOAT, count, GL_FALSE});
    stride += sizeof(GL_FLOAT) * count;
}

// void KiVertexBufferLayout::
