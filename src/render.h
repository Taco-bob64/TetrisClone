#pragma once
#include "glad/glad.h"
#include "glfw3.h"
#include "shader.h"
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Render
{
private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int Texture;
	unsigned int texUnits;
	bool isTexture;
	bool isLight;

	unsigned int Program;
	int width, height, nrChannels;
	unsigned char* data;

	glm::vec3 Color;

public:
	Render(std::string shaderPath, std::string texturePath, unsigned int units);
	void draw( glm::mat4 m, glm::vec3 color);
};

