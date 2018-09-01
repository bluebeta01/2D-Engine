#version 400

layout (location = 0)in vec2 pos;
uniform mat4 projMat;

void main()
{
	gl_Position = projMat * vec4(pos.x, pos.y, 1.0f, 1.0f);
}