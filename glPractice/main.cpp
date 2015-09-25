#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <algorithm>

#include <GL/glew.h>
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "Sprite.h"
#include "Camera.h"
#include "Cube.h"
#include "GLSLProgram.h"
#include "Vertex.h"
#include "Window.h"


void dispFPS(Engine::Window &window);


int main(int argc, char* argv[])
{

	//*****************  Window ************************
	Engine::Window window;
	window.create("Cube", 1024, 768, RESIZEABLE);

	//*****************  Sprite *************************
	//Engine::Sprite sprite;
	//sprite.init(-1.0f, -1.0f, 1, 1);

	Engine::Cube cube;
	cube.init(0.5);

	//***************** GLSL Program **********************
	Engine::GLSLProgram program;
	program.loadShader("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	program.link();

	//***************** Timer ********************

	clock_t timmer;

	//***************** Camera ********************
	Engine::Camera camera;
	camera.init(program.getUniformLocation("MVP"));

	while (1)
	{
		// ************** Window *****************
		window.clear();
		window.processWindowEvent();
		window.calculateFPS();
		dispFPS(window);

		// ************** Timer *******************

		timmer = clock();
		static float count;
		count += 0.005;
		
		// ************* Use GLSL Program **********************
		program.use();

		// ****************** Camera Control ************************
		camera.cameraPosition = glm::vec3(5 * cos(0.0005*timmer), count, 5 * sin(0.0005*timmer));
		camera.update();


		// ********************* Draw Sprite  *************************
		//sprite.draw();
		cube.draw();

		//**************** Swap Buffer ***************
		window.swapBuffer();
	}

	system("pause");
	return 0;
}

void dispFPS(Engine::Window &window)
{
	static int frameCount = 0;
	if (frameCount++ == 10)
	{
		std::cout << window.getFPS() << std::endl;
		frameCount = 0;
	}
}
