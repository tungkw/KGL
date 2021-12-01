#shader vertex
#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec4 color;
layout(location=2) in vec3 normal;

out vec3 v_normal;
out vec4 v_color;

uniform mat4 mv;
uniform mat4 proj;

void main()
{
   vec4 pos = proj * mv * vec4(position.xyz, 1);
   gl_Position = pos;
   v_color = color;
   // v_normal = normalize((mv * vec4(normal, 0)).xyz);
   v_normal = normal;
}


#shader fragment
#version 330 core

in vec3 v_normal;
in vec4 v_color;

out vec4 color;

uniform vec3 light;

void main()
{
   float ctheta = dot(v_normal, -normalize(light));
   // color = vec4(0.1 * v_color.xyz + 0.9 * max(0, ctheta) * v_color.xyz, v_color.w);
   // color = vec4(max(0.1, ctheta) * v_color.xyz, 1);
   color = v_color;
}