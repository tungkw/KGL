#include "KiTexture.h"


KiTexture::KiTexture(std::string path)
    : m_filepath(path)
{
    // opengl image indexing from bottom left
    stbi_set_flip_vertically_on_load(1);
    m_buffer = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 4);

    KICALL(glGenTextures(1, &m_id));
    KICALL(glBindTexture(GL_TEXTURE_2D, m_id));

    KICALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    KICALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    KICALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP));
    KICALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP));

    KICALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_buffer));
    KICALL(glBindTexture(GL_TEXTURE_2D, 0));

    if(m_buffer) stbi_image_free(m_buffer);
}

KiTexture::~KiTexture()
{
    KICALL(glDeleteTextures(1, &m_id));
}

void KiTexture::Bind(unsigned int slot) const
{
    // slot
    KICALL(glActiveTexture(GL_TEXTURE0 + slot));
    KICALL(glBindTexture(GL_TEXTURE_2D, m_id));
}

void KiTexture::UnBind() const
{
    KICALL(glBindTexture(GL_TEXTURE_2D, 0));
}