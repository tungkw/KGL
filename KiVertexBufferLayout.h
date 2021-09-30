#ifndef __KI_VERTEX_BUFFER_LAYOUT_H
#define __KI_VERTEX_BUFFER_LAYOUT_H

#include "KiHeader.h"
#include "KiLogger.h"
#include <vector>

struct KiVertexBufferElement
{
    GLuint index;
    GLenum type;
    GLint count;
    GLboolean normalized;
    KiVertexBufferElement(GLuint _index, GLenum _type, GLint _count, GLboolean _normalized)
        : index(_index), type(_type), count(_count), normalized(_normalized) {}
};

class KiVertexBufferLayout
{
private:
    std::vector<KiVertexBufferElement> elements;
    GLsizei stride;
public:
    KiVertexBufferLayout()
        : stride(0) {};

    template<class T> void Push(GLsizei count);

    GLsizei GetStride() { return stride; }
    int GetSize() { return elements.size(); }
    KiVertexBufferElement& GetElement(int i) { return elements[i];}

};

#endif
