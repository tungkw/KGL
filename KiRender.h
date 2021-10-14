#ifndef __KI_RENDER_H
#define __KI_RENDER_H

#include "KiVertexArray.h"
#include "KiIndexBuffer.h"
#include "KiShader.h"
#include "KiLogger.h"
#include "KiTexture.h"

class KiRender
{

public:
    void Clear() const {KICALL(glClear(GL_COLOR_BUFFER_BIT);)}
    void Draw(KiVertexArray& va, KiIndexBuffer& ib, KiShader& shader);
};

void KiRender::Draw(KiVertexArray& va, KiIndexBuffer& ib, KiShader& shader)
{
    va.Bind();
    ib.Bind();
    shader.Bind();
    KICALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);)
}
#endif