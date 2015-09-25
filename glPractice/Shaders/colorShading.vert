#version 330

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;

out vec3 fragmentColor;
 
uniform mat4 MVP;

void main()
{
	//gl_Position.xyz=vertexPosition;
	//gl_Position.w=1;
	
	vec4 v = vec4(vertexPosition,1); 
    gl_Position = MVP * v;

	fragmentColor = vertexColor;
}
