#ifndef GameObjects_H
#define GameObjects_H

#include "Object.h"

Vector2f RotateVector(Vector2f vec, float alpha);

enum FeatureType      //Block features
{
	None,
	Unbreakable,
	WithBonus,
	Accelerating
};

class Block : public Object
{
public:
	Block(int i, int j);
	Block() {};

	virtual Vector2i getSize();

	void DecreaseHP();
	void CheckDeath();
	bool isDead();
	void setTexture(int health);
	void ScreenCheck();

	FeatureType getFeature();

	//~Block() {};

private:
	FeatureType feature;
	int health;
	Vector2i size;
	bool Dead = false;
};

class Ball : public Object
{
private:
	Vector2i size;
	bool OnPaddle = 0;
	   
public:
	Ball();

	virtual Vector2i getSize();
	virtual void Move(Vector2f speed);

	void InitBall();
	void ResetBall();
	void SetUnInit();
	bool isOnPaddle();
	void MirrorSpeed(char axis);


};

class Paddle : public Object
{
private:
	Vector2i size;
	int sticky_duration = 0;

public:
	Paddle();

	virtual void Move();
	virtual Vector2i getSize();
	void setRNDScale();
	void setSticky();
	bool isSticky();
};


class Bonus;

#endif GameObjects_H