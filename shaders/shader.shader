//shader vertex
#version 430 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;
//uniform mat4 transform;
uniform mat4 model;

out vec2 TexCoord;
void main()
{
	gl_Position = model * vec4(aPos, 1.0);
	TexCoord = aTexCoord;
}


//shader fragment
#version 430 core
out vec4 FragColor;
in vec2 TexCoord;


uniform vec3 objectColor;
uniform sampler2D texture1;

void main()
{
	FragColor = texture(texture1, TexCoord) * vec4(objectColor, 1.0);

	//FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);

}
