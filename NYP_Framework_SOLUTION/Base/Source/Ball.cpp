#include "Ball.h"

#include "MeshBuilder.h"
#include "EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"
#include "SceneGraph\SceneGraph.h"
Ball::Ball(void)
	: modelMesh(NULL)
	, m_bStatus(false)
	, m_vel(0, 0, 0)
	, m_speed(10.0f)
	, ballArm1(NULL)
	, ballArm2(NULL)
	, ballGun(NULL)
	, ballHead(NULL)
	, HeadNode(NULL)
	, Arm1Node(NULL)
	, Arm2Node(NULL)
	, GunNode(NULL)

{
}

Ball::Ball(Mesh* _modelMesh)
	: modelMesh(_modelMesh)
	, m_bStatus(false)
	, m_vel(0, 0, 0)
	, m_speed(10.0f)

{
}
Ball::Ball(Vector3 position)
{
	
		Vector3 vel(0, 0, 0);

		ballHead = Create::Entity("ballHigh", position, Vector3(1, 1, 1));
		ballHead->SetCollider(true);
		ballHead->SetBall(true);
		ballHead->SetAABB(
			Vector3(1, 1, 1),
			Vector3(-1, -1, -1));

		//Animation/Translate for Head
		HeadNode = CSceneGraph::GetInstance()->AddNode(ballHead);
		HeadNode->ApplyTranslate(position.x, position.y, position.z);
		ballHead->SetPosition(position);
		ballHead->InitLOD("ballHigh", "ballMid", "ballLow");
		//Set Entity and Node to the class entity and Node


		ballGun = Create::Entity("ballgunHigh", position, Vector3(1, 1, 1));
		ballGun->SetCollider(true);
		ballGun->SetBall(true);
		ballGun->SetAABB(
			Vector3(1, 1, 1),
			Vector3(-1, -1, -1));
		ballGun->InitLOD("ballgunHigh", "ballgunMid", "ballgunLow");
		GunNode = HeadNode->AddChild(ballGun);
		GunNode->ApplyTranslate(0, 1.8, 2 );
		

		ballArm1 = Create::Entity("ballarmHigh", position, Vector3(1, 1, 1));
		ballArm1->SetCollider(true);
		ballArm1->SetBall(true);
		ballArm1->SetAABB(
			Vector3(1, 1, 1),
			Vector3(-1, -1, -1));
		ballArm1->InitLOD("ballarmHigh", "ballarmMid", "ballarmLow");

		//For Animation
		CUpdateTransformation* baseMtx = new CUpdateTransformation();
		Arm1Node = HeadNode->AddChild(ballArm1);
		Arm1Node->ApplyTranslate(1. , -0.2f , 1.6 );
		baseMtx->ApplyUpdate(1.0f, 1.0f, 0.0f, 0.0f);
		baseMtx->SetSteps(-10, 10);
		Arm1Node->SetUpdateTransformation(baseMtx);

		


		CUpdateTransformation* baseMtx2 = new CUpdateTransformation();

		ballArm2 = Create::Entity("ballarmHigh", position, Vector3(1, 1, 1));
		ballArm2->SetCollider(true);
		ballArm2->SetBall(true);
		ballArm2->SetAABB(
			Vector3(1, 1, 1),
			Vector3(-1, -1, -1));
		ballArm2->InitLOD("ballarmHigh", "ballarmMid", "ballarmLow");

		Arm2Node = HeadNode->AddChild(ballArm2);
		Arm2Node->ApplyTranslate(-1 , -0.2f , 1.6);
		baseMtx2->ApplyUpdate(1.0f, 1.0f, 0.0f, 0.0f);
		baseMtx2->SetSteps(-10, 10);
		Arm2Node->SetUpdateTransformation(baseMtx2);

	
}
Ball::~Ball(void)
{
	modelMesh = NULL;

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
	//std::cout << "Ball Active: " << this->isDone << std::endl;
	if (m_vel != Vector3(0, 0, 0))
	{
		m_vel.Normalize();
		HeadNode->ApplyTranslate((position.x + m_vel.x)*dt, (position.y + m_vel.y)*dt, (position.z + m_vel.z)*dt);
		ballHead->GetPosition().Set((position.x + m_vel.x)*dt, (position.y + m_vel.y)*dt, (position.z + m_vel.z)*dt);
		ballArm1->GetPosition().Set((position.x + m_vel.x)*dt, (position.y + m_vel.y)*dt, (position.z + m_vel.z)*dt);
		ballArm2->GetPosition().Set((position.x + m_vel.x)*dt, (position.y + m_vel.y)*dt, (position.z + m_vel.z)*dt);
		ballGun->GetPosition().Set((position.x + m_vel.x)*dt, (position.y + m_vel.y)*dt, (position.z + m_vel.z)*dt);
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
void Ball::setBallHead(GenericEntity* ballHead)
{
	this->ballHead = ballHead;
}
GenericEntity* Ball::getBallHead()
{
	return ballHead;
}

void Ball::setBallArm1(GenericEntity* ballArm)
{
	this->ballArm1 = ballArm;
}
GenericEntity* Ball::getBallArm()
{
	return ballArm1;
}

void Ball::setBallArm2(GenericEntity* ballArm)
{
	this->ballArm2 = ballArm;
}
GenericEntity* Ball::getBallArm2()
{
	return ballArm2;
}

void Ball::setBallGun(GenericEntity* ballGun)
{
	this->ballGun = ballGun;
}
GenericEntity* Ball::getBallGun()
{
	return ballGun;
}
//
//
//void Ball::setHeadNode(CSceneNode* node)
//{
//	this->HeadNode = node;
//}
//CSceneNode* Ball::getHeadNode()
//{
//	return HeadNode;
//}
//
//void Ball::setArm1Node(CSceneNode* node)
//{
//	this->Arm1Node = node;
//}
//CSceneNode* Ball::getArm1Node()
//{
//	return Arm1Node;
//}
//
//void Ball::setArm2Node(CSceneNode* node)
//{
//	this->Arm2Node = node;
//}
//CSceneNode* Ball::getArm2Node()
//{
//	return Arm2Node;
//}
//
//void Ball::setGunNode(CSceneNode* node)
//{
//
//}
//CSceneNode* getGunNode();
// Create a projectile and add it into EntityManager
Ball* Create::ball(const std::string& _meshName,
	const Vector3& _position,
	const Vector3& _direction,
	const Vector3& _Scale,
	const float m_fSpeed )
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
	result->SetBall(true);

	
	

	EntityManager::GetInstance()->AddEntity(result,true);
	return result;
}

