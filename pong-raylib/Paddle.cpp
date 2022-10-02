#include"Paddle.h"

Paddle::Paddle()
{
	height = 120;
	width = 21;
	speed = 650;
	score = 0;

}

Paddle::Paddle(float hight, float width, float speed)
{
	this->height = hight;
	this->width = width;
	this->speed = speed;
	score = 0;


}

int Paddle::UpScore()
{
	score++;

	return score;


}

void Paddle::position(float x, float y)
{
	this->x = x;
	this->y = y;
}

Rectangle Paddle::GetRect()
{
	return Rectangle{ x - width / 2, y - height / 2, width, height };

}

void Paddle::Draw(Color c)
{
	DrawRectangleRec(GetRect(), c);
}
