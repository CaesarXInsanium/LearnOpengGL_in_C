#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture00;
uniform sampler2D ourTexture01;

void main(){
  FragColor = mix(texture(ourTexture00, TexCoord),
                  texture(ourTexture01, TexCoord), 0.5);
}
