#pragma once

class Ball
{
public:
	float ballX = 400, ballY = 300;
	float momentumX = 6;
	float momentumY = 6;

	void init();
	void update();
	void draw() const;
};