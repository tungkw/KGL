#ifndef __KGL_INDEX_BUFFER_H
#define __KGL_INDEX_BUFFER_H
#include "Header.h"
#include "Logger.h"


namespace kgl
{
    
class IndexBuffer{
private:
    unsigned int m_id;
    unsigned int * buffer;
    int size;
public:
    IndexBuffer(unsigned int max_count);
    ~IndexBuffer();
    void Add(const unsigned int *data, unsigned int count, unsigned int offset);
    void Attach();
    void Bind();
    void Unbind();
    unsigned int GetCount();
};

} // namespace kog


#endif