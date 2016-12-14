#pragma once
#include "GenericEntity.h"


class Mesh;
//class CPlayerInfo;

class Asteroid : public GenericEntity
{
public:
	Asteroid(void);
	Asteroid(Mesh* _modelMesh);
	~Asteroid();
public:

	void SetSpeed(const float sped);
	// Activate the projectile. true == active, false == inactive
	// Set the position and direction of the projectile
	Vector3 GetVel(void);
	void SetVel(Vector3 newvel);
	virtual void Update(double dt = 0.0333f);


protected:
	// The model mesh for this projectile
	Mesh* modelMesh;
	// Boolean flag to indicate if this projectile is active. If not active, then do not compute/update
	float m_speed;
	// The direction of the projectile
	Vector3 m_vel;

};

namespace Create
{
	Asteroid* asteroid(const std::string& _meshName,
		const Vector3& _position,
		const Vector3& _velocity,
		const Vector3& _Scale,
		const float m_Speed);
};

