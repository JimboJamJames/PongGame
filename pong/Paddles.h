#pragma once

class Paddle1
{
public:
	float x = 750, y = 300;
	float size = 200;

	void init();
	void update();
	void draw() const;
};

class Paddle2
{
public:
	float x = 50, y = 300;
	float size = 200;

	void init();
	void update();
	void draw() const;
};


class Paddle
{
public:
	float x, y;
	float size;
	char up, down;
	unsigned color;


	void init(float a_x, float a_y, float a_size, char a_up, char a_down, unsigned a_color);
	void update();
	void draw() const;
};


