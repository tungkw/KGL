#shader vertex
#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec4 color;
layout(location=2) in vec3 normal;

out vec4 v_color;
out float ctheta;

uniform mat4 mv;
uniform mat4 proj;
uniform vec3 light;

void main()
{
   vec3 I = vec3(1, 1, 1), Ia = color.xyz;
   float kd = 20, ks = 20, ka = 0.5;
   float r = distance(position, light);
   vec3 color_ = vec3(0, 0, 0);
   vec3 pos_eye = (inverse(mv) * vec4(0, 0, 0, 1)).xyz - position;
   vec3 h = (normalize(pos_eye) + normalize(light-position)) / 2.0f;
   color_ += kd * (I/(r*r)) * max(0, dot(normalize(normal), normalize(light)));
   color_ += ks * (I/(r*r)) * max(0, dot(normalize(normal), normalize(h)));
   color_ += ka * Ia;
   v_color = vec4(color_, color.w);
   gl_Position = proj * mv * vec4(position, 1);
}


#shader fragment
#version 330 core

in vec4 v_color;
in float ctheta;

out vec4 color;

void main()
{
   color = v_color;
}