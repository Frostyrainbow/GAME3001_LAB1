#pragma once
#ifndef __JET__
#define __JET__
#include "DisplayObject.h"
#include "TextureManager.h"

class Jet final : public DisplayObject
{
public:
	// constructor(s)
	Jet();

	// destructor
	~Jet();
	
	// life-cycle methods inherited from DisplayObject
	void draw() override;
	void update() override;
	void clean() override;

	//Getters
	float getRotation();

	//Setters
	void setDestination(glm::vec2 destination);
	void setMaxSpeed(float speed);
	void setOrientation(glm::vec2 orientation);
	void setRotation(float angle);

private:

	glm::vec2 m_destination;
	glm::vec2 m_targetDirection;
	glm::vec2 m_orientation;
	float m_rotationAngle;
	float m_maxSpeed;

	// private function
	void m_Move();
};

#endif /* defined (__SPACE_SHIP__) */
