#ifndef __KI_TEXTURE_H
#define __KI_TEXTURE_H
#include <string>
#include "utils/stb_image/stb_image.h"
#include "KiLogger.h"

class KiTexture
{
    unsigned int m_id;
    std::string m_filepath;
    unsigned char* m_buffer;
    int m_height;
    int m_width;
    int m_BPP;

public:
    KiTexture(std::string path);
    ~KiTexture();
    void Bind(unsigned int slot) const;
    void UnBind() const;
    unsigned int GetWidth() const { return m_width; }
    unsigned int GetHeight() const { return m_height; }
};

#endif