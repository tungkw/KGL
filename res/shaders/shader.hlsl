#shader vertex
#version 330 core
layout(location=0) in vec3 position;
// layout(location=1) in vec2 texCoord;
layout(location=1) in vec4 color;

uniform mat4 mvp;

// out vec2 v_TexCoord;
out vec4 v_color;

void main()
{
   vec4 pos = mvp * vec4(position.xyz, 1);
   // gl_Position = pos / pos.w;
   gl_Position = pos;
   // v_TexCoord = texCoord;
   v_color = color;
}


#shader fragment
#version 330 core

// in vec2 v_TexCoord;
in vec4 v_color;
out vec4 color;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
   // vec4 texColor = texture(u_Texture, v_TexCoord);
   // color = texColor;
   // color = v_color;
   color = vec4(1.0, 1.0, 1.0, 1.0);
}