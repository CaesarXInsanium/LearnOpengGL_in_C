#version 450 core
layout (location = 0) out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

layout (location = 0) uniform sampler2D ourTexture00;
layout (location = 1) uniform sampler2D ourTexture01;

void main(){
  // flip the texture coordinates over the y axis
  vec2 new_tex = vec2(TexCoord.x, abs(1 - TexCoord.y));

  FragColor = mix(texture(ourTexture00, new_tex),
                  texture(ourTexture01, new_tex), 0.5);
}
