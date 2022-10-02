#include"ball.h"

Ball::Ball()
{
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    radius = 10;
    ballSpeed_X = 400;
    ballSpeed_Y = 400;

}

void Ball::initBall(int x_speed, int y_speed, int radius)
{
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    this->radius = radius;
    ballSpeed_X = x_speed;
    ballSpeed_Y = y_speed;

}

void Ball::speed(int x_speed, int y_speed)
{
    ballSpeed_X = x_speed;
    ballSpeed_Y = y_speed;
}

void Ball::Radius(int val)
{
    radius = val;
}

void Ball::Draw()
{
    DrawCircle((int)x, (int)y, radius, RAYWHITE);
}
