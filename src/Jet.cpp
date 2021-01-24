#include "Jet.h"
#include "Util.h"

Jet::Jet():m_maxSpeed(10.0f)
{
	TextureManager::Instance()->load("../Assets/textures/jet.png", "jet");

	auto size = TextureManager::Instance()->getTextureSize("jet");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(JET);
	setOrientation(glm::vec2(0.0f, -1.0f));
	setRotation(0.0f);
}

Jet::~Jet()
= default;

void Jet::draw()
{
	TextureManager::Instance()->draw("jet", getTransform()->position.x, getTransform()->position.y, getRotation(), 255, true);
	Util::DrawLine(getTransform()->position, (getTransform()->position + m_orientation * 60.0f));
}

void Jet::update()
{
	m_Move();
}

void Jet::clean()
{

}

float Jet::getRotation()
{
	return m_rotationAngle;
}

void Jet::setDestination(const glm::vec2 destination)
{
	m_destination = destination;
}

void Jet::setMaxSpeed(const float speed)
{
	m_maxSpeed = speed;
}

void Jet::setOrientation(const glm::vec2 orientation)
{
	m_orientation = orientation;
}

void Jet::setRotation(float angle)
{
	m_rotationAngle = angle;
}

void Jet::m_Move()
{

	// direction with magnitude
	m_targetDirection = m_destination - getTransform()->position;
	// normalized direction
	m_targetDirection = Util::normalize(m_targetDirection);

	getRigidBody()->velocity = m_targetDirection * m_maxSpeed;

	getTransform()->position += getRigidBody()->velocity;

}