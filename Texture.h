#ifndef __KGL_TEXTURE_H
#define __KGL_TEXTURE_H
#include <string>
#include "utils/stb_image/stb_image.h"
#include "Logger.h"

namespace kgl
{

    
class Texture
{
    unsigned int m_id;
    std::string m_filepath;
    unsigned char* m_buffer;
    int m_height;
    int m_width;
    int m_BPP;

public:
    Texture(std::string path);
    ~Texture();
    void Bind(unsigned int slot) const;
    void UnBind() const;
    unsigned int GetWidth() const { return m_width; }
    unsigned int GetHeight() const { return m_height; }
};

    
} // namespace kgl


#endif