#ifndef __KI_Index_BUFFER_H
#define __KI_Index_BUFFER_H
#include "KiHeader.h"
#include "KiLogger.h"

class KiIndexBuffer{
private:
    unsigned int m_id;
    unsigned int m_count;
public:
    KiIndexBuffer(const void *data, unsigned int size);
    ~KiIndexBuffer();
    void Bind();
    void Unbind();
    unsigned int GetCount();
};

#endif