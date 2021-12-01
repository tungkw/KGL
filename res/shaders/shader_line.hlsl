#shader vertex
#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec4 color;

out vec4 v_color;

uniform mat4 mv;
uniform mat4 proj;

void main()
{
   vec4 pos = proj * mv * vec4(position.xyz, 1);
   gl_Position = pos;
   v_color = color;
}


#shader fragment
#version 330 core

in vec4 v_color;

out vec4 color;

void main()
{
   color = v_color;
}