#ifndef __KGL_BUFFER_H
#define __KGL_BUFFER_H

#include "Geometry/Object.h"
#include "Geometry/Vertice.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

namespace kgl
{


#define VERTEX_BUFFER_MAX_SIZE  10000
#define INDEX_BUFFER_MAX_SIZE   10000


template<typename T>
class Buffer
{
public:
    unsigned int count;
    unsigned int num_vertice_per_primitive;
    kgl::VertexBuffer *vb;
    kgl::IndexBuffer *ib;
    kgl::VertexArray *va;

public:
    Buffer(unsigned int num_vertice_per_primitive)
    {
        count = 0;
        this->num_vertice_per_primitive = num_vertice_per_primitive;
        vb = new VertexBuffer(sizeof(T) * VERTEX_BUFFER_MAX_SIZE);
        va = new VertexArray();
        va->Add(*vb, T::GetLayout());

        ib = new IndexBuffer(num_vertice_per_primitive * INDEX_BUFFER_MAX_SIZE);
    }

    ~Buffer()
    {
        delete vb;
        delete va;
        delete ib;
    }

    void Attach()
    {
        vb->Attach();
        ib->Attach();
    }

    void Bind()
    {
        va->Bind();
        ib->Bind();
    }

    unsigned int GetNumIndex()
    {
        return ib->GetCount();
    }

    void Clear()
    {
        vb->Clear();
        ib->Clear();
        this->count = 0;
    }

    void Add(Object<T>* obj) 
    {
        this->vb->Add(obj->GetVertexData(), sizeof(T) * obj->GetVertexNum());
        this->ib->Add((unsigned int *)obj->GetPrimitivesData(), this->num_vertice_per_primitive * obj->GetPrimitivesNum(), this->count);
        this->count += obj->GetVertexNum();
    }
};



template<typename T>
class TriangleBuffer
    : public Buffer<T>
{
public:
    TriangleBuffer() : Buffer<T>(3) {}
};


template<typename T>
class LineBuffer
    : public Buffer<T>
{
public:
    LineBuffer(): Buffer<T>(2) {}
};


} // namespace kgl


#endif