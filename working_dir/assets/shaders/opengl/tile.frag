#version 400

in vec2 texCoord;

uniform sampler2D ourTexture;

out vec4 color;

void main()
{
	color = texture(ourTexture, texCoord);
}