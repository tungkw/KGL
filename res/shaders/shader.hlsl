#shader vertex
#version 330 core
layout(location=0) in vec4 position;
layout(location=1) in vec2 texCoord;

uniform mat4 mvp;

out vec2 v_TexCoord;

void main()
{
   vec4 pos = mvp * position;
   // gl_Position = pos / pos.w;
   gl_Position = pos;
   v_TexCoord = texCoord;
}


#shader fragment
#version 330 core

in vec2 v_TexCoord;
out vec4 color;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
   vec4 texColor = texture(u_Texture, v_TexCoord);
   color = texColor;
}