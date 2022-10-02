#pragma once
#include "Paddle.h"
#include "ball.h"
#include <string>
#include <raylib.h>
#include <assert.h>
using namespace std;


class Game
{
public:

    Game(int screenWidth, int screenHeight);
    ~Game();
    bool GameshouldClose();
    void Tick();
	

private:

    bool start;
    string leftScore, rightScore;
    int score;
    Ball ball;
    Paddle leftPaddle, rightPaddle;
    const char* winnerMassage;

    void Draw();
	

    // Update
    //----------------------------------------------------------------------------------
    void Update();
    

    void  UpdateKey();
	

    

};

