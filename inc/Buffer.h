#ifndef __KGL_BUFFER_H
#define __KGL_BUFFER_H

#include "Geometry/Object.h"
#include "Geometry/Vertice.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

namespace kgl
{



template<typename T>
class Buffer
{
public:
    unsigned int count;
    kgl::VertexBuffer *vb;
    kgl::IndexBuffer *ib;
    kgl::VertexArray *va;

public:
    Buffer()
    {
        count = 0;
        vb = new VertexBuffer(sizeof(T) * 1000);
        va = new VertexArray();
        va->Add(*vb, T::GetLayout());
    }

    ~Buffer()
    {
        delete vb;
        delete va;
    }

    void Attach()
    {
        vb->Bind();
        ib->Bind();
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

    virtual void Add(Object<T>* obj) = 0;
};



template<typename T>
class TriangleBuffer
    : public Buffer<T>
{
public:
    TriangleBuffer(){
        this->ib = new IndexBuffer(3 * 1000);
    }

    ~TriangleBuffer(){
        delete this->ib;
    }

    virtual void Add(Object<T>* obj) 
    {
        this->vb->Add(obj->vertex, sizeof(T) * obj->num_vertex);
        this->ib->Add(obj->primitives, 3 * obj->num_primitives, this->count);
        this->count += obj->num_vertex;
    }
};


template<typename T>
class LineBuffer
    : public Buffer<T>
{
public:
    LineBuffer(){
        this->ib = new IndexBuffer(2 * 1000);
    }

    ~LineBuffer(){
        delete this->ib;
    }

    virtual void Add(Object<T>* obj)
    {
        this->vb->Add(obj->vertex, sizeof(T) * obj->num_vertex);
        this->ib->Add(obj->primitives, 2 * obj->num_primitives, this->count);
        this->count += obj->num_vertex;
    }
};


} // namespace kgl


#endif