#include "Texture.h"

namespace kgl
{

Texture::Texture(std::string path)
    : m_filepath(path)
{
    // opengl image indexing from bottom left
    stbi_set_flip_vertically_on_load(1);
    m_buffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);

    KGLCALL(glGenTextures(1, &m_id));
    KGLCALL(glBindTexture(GL_TEXTURE_2D, m_id));

    KGLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    KGLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    KGLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP));
    KGLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP));

    KGLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_buffer));
    KGLCALL(glBindTexture(GL_TEXTURE_2D, 0));

    if(m_buffer) stbi_image_free(m_buffer);
}

Texture::~Texture()
{
    KGLCALL(glDeleteTextures(1, &m_id));
}

void Texture::Bind(unsigned int slot) const
{
    // slot
    KGLCALL(glActiveTexture(GL_TEXTURE0 + slot));
    KGLCALL(glBindTexture(GL_TEXTURE_2D, m_id));
}

void Texture::UnBind() const
{
    KGLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}

}