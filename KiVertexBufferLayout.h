#ifndef __KI_VERTEX_BUFFER_LAYOUT_H
#define __KI_VERTEX_BUFFER_LAYOUT_H

#include "KiHeader.h"
#include "KiLogger.h"
#include <vector>

struct KiVertexBufferElement
{
    GLuint index;
    GLint size;
    GLenum type;
    GLboolean normalized;
};

class KiVertexBufferLayout
{
private:
    std::vector<KiVertexBufferElement> elements;
    GLsizei stride;
public:
    KiVertexBufferLayout()
        : stride(0) {};
    ~KiVertexBufferLayout();

    GLsizei GetStride() { return stride; }
    KiVertexBufferElement& GetElement(int i) { return elements[i]; }

    template<class>
    void Push<float>(unsigned int count)
    {
        GLint size = typeof(GL_FLOAT) * count
        elements.push_back({ elements.size(), size, GL_FLOAT, GL_TRUE});
    }
};

#endif
