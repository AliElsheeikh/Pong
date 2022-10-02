#pragma once
#include <raylib.h>
#include <string>
class Paddle
{

public:
	float x;
	float y;
	float speed;
	float width;
	float height;
	int score;
	


	Paddle();
	

	Paddle(float hight, float width, float speed);
	


	int UpScore();
	


	void position(float x, float y);
	

	Rectangle GetRect();
	

	void Draw(Color c);
	


};

