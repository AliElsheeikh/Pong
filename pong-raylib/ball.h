#pragma once
#include "raylib.h"
class Ball
{
public:
    float x;
    float y;
    float radius;
    float ballSpeed_X;
    float ballSpeed_Y;

    Ball();
    

    void initBall(int x_speed, int y_speed, int radius);
    

    void speed(int x_speed, int y_speed);
   

    void Radius(int val);
    
    void Draw();
   
};

