#ifndef __KGL_Index_BUFFER_H
#define __KGL_Index_BUFFER_H
#include "Header.h"
#include "Logger.h"


namespace kgl
{
    
class IndexBuffer{
private:
    unsigned int m_id;
    unsigned int m_count;
public:
    IndexBuffer(const void *data, unsigned int size);
    ~IndexBuffer();
    void Bind();
    void Unbind();
    unsigned int GetCount();
};

} // namespace kog


#endif