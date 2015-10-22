#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

#include <Engine/GLSLProgram.h>
#include <Engine/Sprite.h>
#include <Engine/GLTexture.h>
#include <Engine/Window.h>
enum class GameState {PLAY, EXIT};

class MainGame
{
public:
    MainGame();
    ~MainGame();

    void run();

private:
    void initSystems();
    void initShaders();
    void gameLoop();
    void processInput();
    void drawGame();
	void calculateFPS();

    Window _window;
    int _screenWidth;
    int _screenHeight;
    GameState _gameState;

    Sprite _sprite;

    GLSLProgram _colorProgram;

	float _fps;
	float _frameTime;
    float _time;
	float _maxFPS;
};

