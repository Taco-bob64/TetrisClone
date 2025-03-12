#include "render.h"

float vertices[]{
	//cords           //texcords
 -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
 -0.5f, -0.5f,0.0f, 0.0f, 0.0f,
 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
 -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
 0.5f, 0.5f, 0.0f, 1.0f, 1.0f

};

Render::Render(std::string shaderPath,std::string texturePath, unsigned int texunits)
{
	
	if (texturePath == "none")
		isTexture = false;
	else
		isTexture = true;
	
	texUnits = texunits;
	//creates object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	Shader shad(shaderPath);
	Program = shad.getProgram();

	if (isTexture)
	{
		glGenTextures(1, &Texture);
		glActiveTexture(GL_TEXTURE0 + texUnits);
		glBindTexture(GL_TEXTURE_2D, Texture);


		//perameters for currently bound texture
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		//load and generate texture
		stbi_set_flip_vertically_on_load(GL_TEXTURE_2D);
		data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 4);
		


			if (data)
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

			}
			else
				std::cout << "Texture failed to load" << '\n';
		

			glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);
	}
	
}

void Render::draw (glm::mat4 m, glm::vec3 color)
{
	Color = color;
	
	unsigned int modelLoc = glGetUniformLocation(Program, "model");
	int squareColorLocation;
	squareColorLocation = glGetUniformLocation(Program, "objectColor");
		
	

	glUseProgram(Program);

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(m));

	
		glUniform3f(squareColorLocation, Color.r, Color.g, Color.b);
	if (isTexture)
	{
		glUniform1i(glGetUniformLocation(Program, "texture1"), texUnits);
		glActiveTexture(GL_TEXTURE0 + texUnits);
		glBindTexture(GL_TEXTURE_2D, Texture);
	}
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	
}
