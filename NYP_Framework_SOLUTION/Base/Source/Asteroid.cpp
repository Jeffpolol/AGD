#include "Asteroid.h"
#include "MeshBuilder.h"
#include "EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"

Asteroid::Asteroid(void)
: modelMesh(NULL)
, m_vel(0, 0, 0)
, m_speed(10.0f)
{
}

Asteroid::Asteroid(Mesh* _modelMesh)
: modelMesh(_modelMesh)
, m_vel(0, 0, 0)
, m_speed(10.0f)
{
	SetMesh(_modelMesh);
}

Asteroid::~Asteroid(void)
{
	modelMesh = NULL;

}



// Get the direction of the projectile
Vector3 Asteroid::GetVel(void)
{
	return m_vel;
}

// Set the direction of the projectile
void Asteroid::SetVel(Vector3 theNewDirection)
{
	m_vel = theNewDirection;
}

void Asteroid::SetSpeed(float theNewDirection)
{
	m_speed = theNewDirection;
}


// Update the status of this projectile
void Asteroid::Update(double dt)
{
		//SetStatus(false);
		//SetIsDone(true);	// This method is to inform the EntityManager that it should remove this instance
	// Update Position
	m_vel.Normalize();
	position.Set(position.x + (float)(m_vel.x * dt * m_speed),
		position.y + (float)(m_vel.y * dt * m_speed),
		position.z + (float)(m_vel.z * dt * m_speed));
}




// Create a projectile and add it into EntityManager
Asteroid* Create::asteroid(const std::string& _meshName,
	const Vector3& _position,
	const Vector3& _direction,
	const Vector3& _Scale,
	const float m_fSpeed)
{
	Mesh* modelMesh = MeshBuilder::GetInstance()->GetMesh(_meshName);
	if (modelMesh == nullptr)
		return nullptr;

	Asteroid* result = new Asteroid(modelMesh);
	result->SetPosition(_position);
	result->SetScale(_Scale);
	result->SetVel(_direction);
	result->SetSpeed(m_fSpeed);
	result->SetCollider(true);
	result->SetIsBall(false);
	result->SetType(type);
	EntityManager::GetInstance()->AddEntity(result);
	return result;
}