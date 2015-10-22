#include "MainGame.h"
#include <Engine/Errors.h>

#include <iostream>
#include <string>
#include <Engine/Engine.h>

//Constructor, just initializes private member variables
MainGame::MainGame() :
	_screenWidth(1024),
	_screenHeight(768),
	_time(0.0f),
	_gameState(GameState::PLAY),
	_maxFPS(60.0f)
{

}

//Destructor
MainGame::~MainGame()
{
}

//This runs the game
void MainGame::run() {
	initSystems();

	//Initialize our sprite. (temporary)
	Rectangle rectangle(glm::vec3(-1.0f, -1.0f, 0), 2.0f, 2.0f);
	_sprite.init(rectangle, "Textures/ohhoho.png");

	//This only returns when the game ends
	gameLoop();
}

//Initialize SDL and Opengl and whatever else we need
void MainGame::initSystems() {
	
	engineInit();

	_window.create("OH HO HO HO", 640, 360, 0);

	

	initShaders();
}

void MainGame::initShaders() {
	_colorProgram.compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.addAttribute("vertexNormal");
	_colorProgram.addAttribute("vertexUV");
	_colorProgram.linkShaders();
}

//This is the main game loop for our program
void MainGame::gameLoop() {

	

	//Will loop until we set _gameState to EXIT
	while (_gameState != GameState::EXIT) {

		float startTicks = SDL_GetTicks();

		processInput();
		_time += 0.01;
		drawGame();
		calculateFPS();

		static int frames = 0;
		if (++frames % 60 == 0)
		{
			std::cout << _fps << std::endl;
		}

		

		float frameTicks = SDL_GetTicks() - startTicks;

		//Limit FPS
		if ((1000.0f / _maxFPS) > frameTicks)
		{
			
			SDL_Delay(1000.0f / _maxFPS - frameTicks);
		}
    }
}

//Processes input with SDL
void MainGame::processInput() {
    SDL_Event evnt;

    //Will keep looping until there are no more events to process
    while (SDL_PollEvent(&evnt)) {
        switch (evnt.type) {
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
            case SDL_MOUSEMOTION:
                std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
                break;
        }
    }
}

//Draws the game using the almighty OpenGL
void MainGame::drawGame() {

    //Set the base depth to 1.0
    glClearDepth(1.0);
    //Clear the color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _colorProgram.use();
	glActiveTexture(GL_TEXTURE0);
	GLint textureLocation = _colorProgram.getUniformLocation("mySampler");
	glUniform1i(textureLocation, 0);

    //GLint timeLocation = _colorProgram.getUniformLocation("time");
    //glUniform1f(timeLocation, _time);

    //Draw our sprite!
    _sprite.draw();

	glBindTexture(GL_TEXTURE_2D, 0);

    _colorProgram.unuse();

	_window.swapBuffers();
}

void MainGame::calculateFPS()
{
	static const int NUM_SAMPLES = 10;
	static float frameTimes[NUM_SAMPLES];
	static int currentFrame = 0;

	static float previousTicks = SDL_GetTicks();
	float currentTicks;
	currentTicks = SDL_GetTicks();
	_frameTime = currentTicks - previousTicks;
	previousTicks = currentTicks;
	frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;

	int count;
	currentFrame++;

	if (currentFrame < NUM_SAMPLES)
	{
		count = currentFrame;
	}
	else
	{
		count = NUM_SAMPLES;
	}

	float frameTimeAverage = 0;
	for (unsigned i = 0; i < count; i++)
	{
		frameTimeAverage += frameTimes[i];
	}

	frameTimeAverage /= count;

	if (frameTimeAverage > 0)
	{
		_fps = 1000.0f / frameTimeAverage;
	}
	
}
