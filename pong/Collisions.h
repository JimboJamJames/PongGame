#pragma once


class Ball;
class Paddle;

void Collision(Ball &circle);
void Collision2(Ball &circle, const Paddle LeftPaddle);
void Collision3(Ball &circle, const Paddle RightPaddle);