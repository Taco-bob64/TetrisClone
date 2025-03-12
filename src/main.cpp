#include "glad\glad.h"
#include "glfw3.h"
#include "render.h"
#include "piece.h"
#include "iostream"
#include <string>
#include "shader.h"


bool play = false;
float Xp;
float Yp;
bool p = false;
int viewWidth = 1920;
int viewHeight = 1080;
int totLines = 0;

void RenderText(Shader& shader, std::string text, float x, float y, float scale, glm::vec3 color);

unsigned int VAO, VBO;


void framebuffer_size_callback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);
	viewWidth = w;
	viewHeight = h;

}

void processInput(GLFWwindow* window)
{
	

}
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Xp = xpos;
	Yp = ypos;
}



int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


	GLFWwindow* window = glfwCreateWindow(1920, 1080, "YAHHHHHHH", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << '\n';
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << '\n';
		return -1;
	}

	glViewport(0, 0, 1920, 1080);

	glm::vec3 white(1.0f, 1.0f, 1.0f);
	Render bg("shaders/shader.shader", "textures/testbg.png", 1);
	Render frame("shaders/shader.shader", "textures/testFrame.png", 2);
	Render grid("shaders/shader.shader", "textures/testGrid.png", 3);
	Render piece("shaders/shader.shader", "textures/tetrisBlockTexture1.png", 4);
	Render proj("shaders/shader.shader", "textures/tetrisProj.png", 5);
	Render menue("shaders/shader.shader", "textures/menue.png", 6);
	Render loss("shaders/shader.shader", "textures/tetrisLoss.png", 7);



	Piece l(LL);
	glm::mat4 Bgm = glm::mat4(1.0f);
	Bgm = glm::scale(Bgm, glm::vec3(2.0f, 2.0f, 2.0f));

	float time2 = 0;
	float diff = 0.0f;
	int elapsedTime = 0;
	float sec = 0.0f;
	float secMove = 0.0f;
	float sec2 = 0.0f;


	bool r = false;
	bool rr = false;
	bool ff = false;
	bool f = false;
	bool h = false;

	int rCount = 0;
	int movCount = 0;
	int dCount = 0;
	bool firstD = true;




	




















	//glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	while (!glfwWindowShouldClose(window))
	{
		if (movCount < 0)
			movCount = 0;

		if (rCount < 0)
			rCount = 0;

		float timeValue = glfwGetTime();

		diff = timeValue - time2;
		sec += diff;
		sec2 += diff;
		secMove += diff;
		//std::cout << "fps = " << 1 / diff << '\n';
		//std::cout << "destroyed lines: " << l.totalLines << '\n';
		std::cout << "Lines destroyed: " << totLines << '\n';
		time2 = timeValue;

		//process Inputs
		processInput(window);
		glfwSetCursorPosCallback(window, cursor_position_callback);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		if (play)
		{
			int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);

			if (state == GLFW_PRESS && !rr)
			{
				l.rotate();
				if (rCount <= 200)
					rCount = 200;
				rr = true;
			}

			if (state == GLFW_RELEASE)
			{
				rr = false;
			}

			state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);

			if (state == GLFW_PRESS && !ff)
			{
				l.fastDrop();
				ff = true;
			}

			if (state == GLFW_RELEASE)
			{
				ff = false;
			}


			if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && !r)
			{
				r = true;

				l.rotate();
				if (rCount <= 200)
					rCount = 200;
			}
			if (glfwGetKey(window, GLFW_KEY_R) == GLFW_RELEASE)
			{
				r = false;
				firstD = false;
			}

			if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && secMove >= 0.07f)
			{
				l.left();
				if (movCount <= 100)
					movCount = 100;
				firstD = false;
			}
			else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && secMove >= 0.07f)
			{
				l.left();
				if (movCount <= 100)
					movCount = 100;
				firstD = false;
			}

			if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && secMove >= 0.07f)
			{
				l.right();
				if (movCount <= 100)
					movCount = 100;
				firstD = false;
			}
			else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && secMove >= 0.07f)
			{
				l.right();
				if (movCount <= 100)
					movCount = 100;
				firstD = false;
			}

			if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && secMove >= 0.07f)
			{
				l.down();
			}


			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && !f)
			{
				f = true;
				l.fastDrop();
			}
			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE)
			{
				f = false;
			}


			if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && !l.h)
			{
				l.h = true;
				l.hold();
			}

			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			{
				play = false;
			}


			if (sec2 * l.speedMultiplier >= 1.0f)
			{
				l.increaseTest(0, -1);
				if (!l.noCollide())
				{
					if (firstD)
					{
						dCount = 20;
						firstD = false;
					}
					//if any inputs going on dont collide yet
					if (movCount <= 0 && rCount <= 0 && dCount <= 0)
					{
						//ok collide, no moving going on
						l.down();
						sec2 = 0.0f;
						firstD = true;
					}
					
						

				}
				else
				{
					l.down();
					sec2 = 0.0f;
				}

			}
		}
		else
		{
		l.reset();
			
			int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
			if (state == GLFW_PRESS)
			{
				if (Xp > 650 && Xp < 1313 && Yp < 639 && Yp > 454)
					play = true;
				else if (Xp > 730 && Xp < 1200 && Yp > 718 && Yp < 853)
				{
					glfwSetWindowShouldClose(window, true);
				}
			}
		}

			
			if (l.loss)
			{
				play = false;
				int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
				if (state == GLFW_PRESS)
				{
					if (Xp > 158 && Xp < 800 && Yp < 642 && Yp > 440)
					{
						play = true;
						l.loss = false;
					}
					else if (Xp > 158 && Xp < 800 && Yp > 678 && Yp < 876)
					{
						glfwSetWindowShouldClose(window, true);
					}
				}
			}

			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			

			if (play)
			{
				bg.draw(Bgm, white);
				grid.draw(Bgm, white);
				l.draw(piece);
				l.Proj(proj);
				frame.draw(Bgm, white);
				
			}
			else if (l.loss)
			{
				loss.draw(Bgm, white);
			}
			else {
				menue.draw(Bgm, white);
			}

			//RenderText(shader, "This is sample text", 5.0f, 5.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
			//RenderText(shader, "LearnOpenGL.com", 0.5f, 1.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));
			
		

			glfwSwapBuffers(window);
			glfwPollEvents();

			if (sec >= 1.0f)
			{
				elapsedTime += 1.0f;
				sec = 0.0f;
			}

			if (secMove >= 0.07f)
			{
				secMove = 0.0f;
			}


			rCount--;
			movCount--;
			dCount--;
			if(l.totalLines != 0)
			totLines = l.totalLines;
		}

		glfwTerminate();
	}
	


