#ifndef __KGL_BUFFER_H
#define __KGL_BUFFER_H
#include "Header.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Geometry/Object.h"
#include "Geometry/Vertice.h"

namespace kgl
{


#define VERTEX_BUFFER_MAX_SIZE  5000000
#define INDEX_BUFFER_MAX_SIZE   5000000


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

    void Add(kgl::ObjectBase* obj) 
    {
        if (obj == nullptr) return;
        this->vb->Add(obj->GetVertexData(), sizeof(T) * obj->GetVertexNum());
        this->ib->Add((unsigned int *)(obj->GetPrimitivesData()), this->num_vertice_per_primitive * obj->GetPrimitivesNum(), this->count);
        this->count += obj->GetVertexNum();
    }

    void Terminate()
    {
        delete vb;
        delete va;
        delete ib;
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


template<typename T>
class PointBuffer
    : public Buffer<T>
{
public:
    PointBuffer(): Buffer<T>(1) {}
};


} // namespace kgl


#endif