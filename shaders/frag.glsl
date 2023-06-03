#version 450 core
layout (location = 0) out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

layout (location = 0) uniform sampler2D ourTexture00;
layout (location = 1) uniform sampler2D ourTexture01;


void main(){
  FragColor = mix(texture(ourTexture00, TexCoord),
                  texture(ourTexture01, TexCoord), 0.5);
}
