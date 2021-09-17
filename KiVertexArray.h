#ifndef __KI_VERTEX_ARRAY_H
#define __KI_VERTEX_ARRAY_H

#include "KiHeader.h"
#include "KiLogger.h"
#include "KiVertexBuffer.h"
#include "KiVertexBufferLayout.h"

class KiVertexArray
{
private:
    unsigned int m_id;

public:
    KiVertexArray();
    ~KiVertexArray();

    void Add(KiVertexBuffer, KiVertexBufferLayout);
    void Bind();
    void Unbind();
};

#endif