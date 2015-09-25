#include "Window.h"
#include "Error.h"
#include <GL/glew.h>
#include <iostream>

namespace Engine{

Window::Window():
	_window(nullptr)
{}

Window::~Window()
{
	delete[] _window;
}

void Window::create(std::string windowTitle, int width, int height, uint32_t flag)
{
	_title = windowTitle;
	_width = width;
	_height = height;
	_flag = SDL_WINDOW_OPENGL;
	setWindowFlag(flag);

	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, _flag);

	if (_window == nullptr)
	{
		dispError("Failed to open" + _title);
	}
		
	//Set up our OpenGL context

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) {
		dispError("SDL_GL context could not be created!");
	}

	//Set up glew (optional but recommended)
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		dispError("Could not initialize glew!");
	}

	//Check the OpenGL version
	std::printf("***   OpenGL Version: %s   ***\n", glGetString(GL_VERSION));

	//Set the background color to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Set VSYNC
	SDL_GL_SetSwapInterval(1);

	//Enable double buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

}

void Window::processWindowEvent()
{
	SDL_PollEvent(&_event);
	if (_event.type==SDL_WINDOWEVENT)
	{
		switch (_event.window.event)
		{
		case SDL_WINDOWEVENT_CLOSE:
			close();
			break;
		case SDL_WINDOWEVENT_RESIZED:
			if (_event.type = SDL_MOUSEBUTTONUP)
			{
				_width = _event.window.data1;
				_height = _event.window.data2;
			}
			break;
		}
	}
}

void Window::close()
{
	SDL_Quit();
	exit(1);
}

void Window::setWindowFlag(Uint32 flag)
{

	if (flag & INVISIBLE) 
	{
		_flag |= SDL_WINDOW_HIDDEN;
		return;
	}
	if (flag & FULLSCREEN) 
	{
		_flag |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		return;
	}
	if (flag & BORDERLESS) 
	{
		_flag |= SDL_WINDOW_BORDERLESS;
		return;
	}
	if (flag&RESIZEABLE)
	{
		_flag |= SDL_WINDOW_RESIZABLE;
		return;
	}

	dispError("Flag does not exist");
}

void Window::setFullScreen()
{
	_flag |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void Window::resizeWindow(int width, int height)
{
	SDL_SetWindowSize(_window, width, height);
	_width = width;
	_height = height;
}

void Window::swapBuffer()
{
	SDL_GL_SwapWindow(_window);
}

void Window::calculateFPS()
{
	//The number of frames to average
	static const int NUM_SAMPLES = 10;

	//Stores all the frametimes for each frame that we will average
	static float frameTimes[NUM_SAMPLES];

	//The current frame we are on
	static int currentFrame = 0;

	//the ticks of the previous frame
	static float prevTicks = SDL_GetTicks();

	//Ticks for the current frame
	float currentTicks = SDL_GetTicks();

	//Calculate the number of ticks (ms) for this frame
	frameTimes[currentFrame % NUM_SAMPLES] = currentTicks - prevTicks;

	//current ticks is now previous ticks
	prevTicks = currentTicks;

	//The number of frames to average
	int count;

	currentFrame++;
	if (currentFrame < NUM_SAMPLES) {
		count = currentFrame;
	}
	else {
		count = NUM_SAMPLES;
	}

	//Average all the frame times
	float frameTimeAverage = 0;
	for (int i = 0; i < count; i++) {
		frameTimeAverage += frameTimes[i];
	}
	frameTimeAverage /= count;

	//Calculate FPS
	if (frameTimeAverage > 0) {
		_fps = 1000.0f / frameTimeAverage;
	}
}

void Window::clear()
{	
	//Set the base depth to 1.0
	glClearDepth(1.0);
	//Clear the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
}

