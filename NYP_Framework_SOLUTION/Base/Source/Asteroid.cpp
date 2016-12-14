#include "Asteroid.h"

#include "MeshBuilder.h"
#include "EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"

Asteroid::Asteroid(void)
: modelMesh(NULL)
, m_bStatus(false)
, m_vel(0, 0, 0)
, m_speed(10.0f)

{
}

Asteroid::Asteroid(Mesh* _modelMesh)
: modelMesh(_modelMesh)
, m_bStatus(false)
, m_vel(0, 0, 0)
, m_speed(10.0f)

{
}

Asteroid::~Asteroid(void)
{
	modelMesh = NULL;

}

// Activate the projectile. true == active, false == inactive
void Asteroid::SetStatus(const bool m_bStatus)
{
	this->m_bStatus = m_bStatus;
}

// get status of the projectile. true == active, false == inactive
bool Asteroid::GetStatus(void) const
{
	return m_bStatus;
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
	if (m_bStatus == false)
		return;

		//SetStatus(false);
		//SetIsDone(true);	// This method is to inform the EntityManager that it should remove this instance
	// Update Position
	m_vel.Normalize();
	position.Set(position.x + (float)(m_vel.x * dt * m_speed),
		position.y + (float)(m_vel.y * dt * m_speed),
		position.z + (float)(m_vel.z * dt * m_speed));
}


// Render this projectile
void Asteroid::Render(void)
{
	if (m_bStatus == false)
		return;

	MS& modelStack = GraphicsManager::GetInstance()->GetModelStack();
	modelStack.PushMatrix();
	modelStack.Translate(position.x, position.y, position.z);
	modelStack.Scale(scale.x, scale.y, scale.z);
	//RenderHelper::RenderMesh(modelMesh);
	if (GetLODStatus() == true)
	{
		if (theDetailLevel != NO_DETAILS)
			RenderHelper::RenderMesh(GetLODMesh());
	}
	else
		RenderHelper::RenderMesh(modelMesh);
	modelStack.PopMatrix();
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
	result->SetStatus(true);
	result->SetCollider(true);
	EntityManager::GetInstance()->AddEntity(result);
	return result;
}