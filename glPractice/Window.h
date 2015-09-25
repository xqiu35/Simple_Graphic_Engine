#pragma once
#include <SDL/SDL.h>
#include <string>


enum windowFlag{ INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4, RESIZEABLE=0x8};

namespace Engine{
class Window
{
public:
	Window();
	~Window();

	void create(std::string windowTitle, int width, int height, Uint32 flag);
	void processWindowEvent();
	void close();
	void setFullScreen();
	void resizeWindow(int width,int height);
	void swapBuffer();
	void calculateFPS();
	void clear();

	// Setters


	// Getters
	int getWindowWidth(){ return _width; }
	int setWindowHeight(){ return _height; }
	float getFPS(){ return _fps; }

private:
	SDL_Window *_window;
	SDL_Event _event;
	std::string _title;
	int _width;
	int _height;
	Uint32 _flag;
	float _fps;

	void setWindowFlag(Uint32 flag);
};
}

