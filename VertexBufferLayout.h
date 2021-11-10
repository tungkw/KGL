#ifndef __KGL_VERTEX_BUFFER_LAYOUT_H
#define __KGL_VERTEX_BUFFER_LAYOUT_H

#include "Header.h"
#include "Logger.h"
#include <vector>

namespace kgl
{

struct VertexBufferElement
{
    GLuint index;
    GLenum type;
    GLint count;
    GLboolean normalized;
    VertexBufferElement(GLuint _index, GLenum _type, GLint _count, GLboolean _normalized)
        : index(_index), type(_type), count(_count), normalized(_normalized) {}
};

class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> elements;
    GLsizei stride;
public:
    VertexBufferLayout()
        : stride(0) {};

    template<class T> void Push(GLsizei count);

    GLsizei GetStride() { return stride; }
    int GetSize() { return elements.size(); }
    VertexBufferElement& GetElement(int i) { return elements[i];}

};
    
} // namespace kgl

#endif
