#pragma once




class Paddle
{
public:
	float x, y;
	float size;
	char up, down;
	unsigned color;
	unsigned font;
	int score = 0;

	void init(float a_x, float a_y, float a_size, char a_up, char a_down, unsigned a_color, unsigned a_font);
	void update();
	void draw() const;
};


