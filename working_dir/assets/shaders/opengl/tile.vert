#version 400

layout (location = 0)in vec2 pos;
layout (location = 1)in vec2 inTexCoord;

uniform mat4 projMat;

out vec2 texCoord;

void main()
{
	gl_Position = projMat * vec4(pos.x, pos.y, 1.0f, 1.0f);
	texCoord = inTexCoord;
}