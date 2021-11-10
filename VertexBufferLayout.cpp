#include "VertexBufferLayout.h"


namespace kgl
{

template<>
void VertexBufferLayout::Push<GLfloat>(GLsizei count)
{
    elements.push_back({elements.size(), GL_FLOAT, count, GL_FALSE});
    stride += sizeof(GL_FLOAT) * count;
}

}

