#include "VertexBufferLayout.h"


namespace kgl
{

template<>
void VertexBufferLayout::Push<GLfloat>(GLsizei place_hold, GLsizei count)
{
    VertexBufferElement element = {elements.size(), GL_FLOAT, count, place_hold, GL_FALSE};
    elements.push_back(element);
    stride += place_hold;
}

}

