#include "MainGame.h"
#include "Errors.h"

#include <iostream>
#include <string>


//Constructor, just initializes private member variables
MainGame::MainGame() :
	_screenWidth(1024),
	_screenHeight(768),
	_time(0.0f),
	_window(nullptr),
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
	Rectangle rectangle(glm::vec3(-0.5f, -0.5f, 0), 1.0f, 1.0f);
	_sprite.init(rectangle, "Textures/profile.png");

	//This only returns when the game ends
	gameLoop();
}

//Initialize SDL and Opengl and whatever else we need
void MainGame::initSystems() {
	//Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Open an SDL window
	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
	if (_window == nullptr) {
		fatalError("SDL Window could not be created!");
	}

	//Set up our OpenGL context
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) {
		fatalError("SDL_GL context could not be created!");
	}

	//Set up glew (optional but recommended)
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("Could not initialize glew!");
	}

	std::printf("***    OpenGL Version: %s    ****\n", glGetString(GL_VERSION));

	//Tell SDL that we want a double buffered window so we dont get
	//any flickering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//Set the background color to blue
	glClearColor(0.0f, 0.6f, 0.8f, 1.0f);
	//vsync
	SDL_GL_SetSwapInterval(1);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

    //Swap our buffer and draw everything to the screen!
    SDL_GL_SwapWindow(_window);
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
