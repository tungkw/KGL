#ifndef __KI_VERTEX_BUFFER_H
#define __KI_VERTEX_BUFFER_H
#include "KiHeader.h"
#include "KiLogger.h"

class KiVertexBuffer{
private:
    unsigned int m_id;
public:
    KiVertexBuffer(const void *data, unsigned int size);
    ~KiVertexBuffer();
    void Bind();
    void Unbind();
};

#endif