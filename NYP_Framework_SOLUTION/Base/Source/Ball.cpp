#include "Ball.h"

#include "MeshBuilder.h"
#include "EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"

Ball::Ball(void)
	: modelMesh(NULL)
	, m_bStatus(false)
	, m_vel(0, 0, 0)
	, m_speed(10.0f)

{
}

Ball::Ball(Mesh* _modelMesh)
	: modelMesh(_modelMesh)
	, m_bStatus(false)
	, m_vel(0, 0, 0)
	, m_speed(10.0f)

{
}

Ball::~Ball(void)
{
	modelMesh = NULL;

}
CSceneNode* Ball::getBallNode()
{
	return ballNode;
}
void  Ball::setBallNode(CSceneNode* ball)
{
	this->ballNode = ball;
}
// Activate the projectile. true == active, false == inactive
void Ball::SetStatus(const bool m_bStatus)
{
	this->m_bStatus = m_bStatus;
}

// get status of the projectile. true == active, false == inactive
bool Ball::GetStatus(void) const
{
	return m_bStatus;
}

// Get the direction of the projectile
Vector3 Ball::GetVel(void)
{
	return m_vel;
}

// Set the direction of the projectile
void Ball::SetVel(Vector3 theNewDirection)
{
	m_vel = theNewDirection;
}

void Ball::SetSpeed(float theNewDirection)
{
	m_speed = theNewDirection;
}


// Update the status of this projectile
void Ball::Update(double dt)
{
	if (m_bStatus == false)
		return;

	//SetStatus(false);
	//SetIsDone(true);	// This method is to inform the EntityManager that it should remove this instance
	// Update Position
	if (m_vel != Vector3(0, 0, 0))
	{
		
		m_vel.Normalize();
		ballNode->ApplyTranslate((position.x + m_vel.x)*dt, (position.y + m_vel.y)*dt, (position.z + m_vel.z)*dt);
	}
}


// Render this projectile
void Ball::Render(void)
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
Ball* Create::ball(const std::string& _meshName,
	const Vector3& _position,
	const Vector3& _direction,
	const Vector3& _Scale,
	const float m_fSpeed)
{
	Mesh* modelMesh = MeshBuilder::GetInstance()->GetMesh(_meshName);
	if (modelMesh == nullptr)
		return nullptr;

	Ball* result = new Ball(modelMesh);
	result->SetPosition(_position);
	result->SetScale(_Scale);
	result->SetVel(_direction);
	result->SetSpeed(m_fSpeed);
	result->SetStatus(true);
	result->SetCollider(true);
	result->SetIsBall(true);
	EntityManager::GetInstance()->AddEntity(result,true);
	return result;
}