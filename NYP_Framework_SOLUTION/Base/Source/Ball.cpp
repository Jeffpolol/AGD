#include "Ball.h"

#include "MeshBuilder.h"
#include "EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"
#include "SceneGraph\SceneGraph.h"
#include "PlayerInfo\PlayerInfo.h"
Ball::Ball(void)
	:
	  m_bStatus(false)
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

Ball::Ball(Mesh* _modelMesh):
	  m_bStatus(false)
	, m_vel(0, 0, 0)
	, m_speed(10.0f)

{
}
Ball::Ball(Vector3 position)
{
	
		m_vel = Vector3(0, 0, 40);

		ballHead = Create::Entity("ballHigh", position, Vector3(10, 10, 10) );
		ballHead->SetCollider(true);
		ballHead->SetAABB(Vector3(5, 5, 5), Vector3(-5, -5, -5));
		//HeadNode->ApplyTranslate(position.x, position.y, position.z);
		//ballHead->SetPosition(position);
		ballHead->InitLOD("ballHigh", "ballMid", "ballLow");
		HeadNode = CSceneGraph::GetInstance()->AddNode(ballHead);
		//ballHead->SetBall(true);
	
		//Animation/Translate for Head
		

		//Set Entity and Node to the class entity and Node
		ballGun = Create::Entity("ballgunHigh", position, Vector3(10, 10, 10));
		ballGun->SetPosition(Vector3(position.x, position.y + 15.8, position.z));
		ballGun->SetCollider(true);
		ballGun->SetBall(true);
		ballGun->SetAABB(Vector3(3, 3, 3),Vector3(-3, -3, -3)); 
		GunNode = HeadNode->AddChild(ballGun);		
		ballGun->InitLOD("ballgunHigh", "ballgunMid", "ballgunLow");
		//GunNode->ApplyTranslate(0, 15.8, 0 );
		

		ballArm1 = Create::Entity("ballarmHigh",Vector3(position.x+10,position.y,position.z+18), Vector3(10, 10, 10));
		ballArm1->SetCollider(true);
		ballArm1->SetBall(true);
		ballArm1->SetAABB(Vector3(3, 3, 3), Vector3(-3, -3, -3));
		ballArm1->InitLOD("ballarmHigh", "ballarmMid", "ballarmLow");
		Arm1Node = HeadNode->AddChild(ballArm1);
		////For Animation
		//CUpdateTransformation* baseMtx = new CUpdateTransformation();
		
		//Arm1Node->ApplyTranslate(1. , -0.1f , 1.6 );
		//baseMtx->ApplyUpdate(1.0f, 1.0f, 0.0f, 0.0f);
		//baseMtx->SetSteps(-10, 10);
		//Arm1Node->SetUpdateTransformation(baseMtx);

		//


		
		ballArm2 = Create::Entity("ballarmHigh",Vector3(position.x-10,position.y,position.z+18), Vector3(10, 10, 10));
		ballArm2->SetCollider(true);
		ballArm2->SetBall(true);
		ballArm2->SetAABB(Vector3(3, 3, 3), Vector3(-3, -3, -3));
		ballArm2->InitLOD("ballarmHigh", "ballarmMid", "ballarmLow");
		Arm2Node = HeadNode->AddChild(ballArm2);
		//
		//CUpdateTransformation* baseMtx2 = new CUpdateTransformation();
		
		//Arm2Node->ApplyTranslate(-1 , -0.1f , 1.6);
		//baseMtx2->ApplyUpdate(1.0f, 1.0f, 0.0f, 0.0f);
		//baseMtx2->SetSteps(-10, 10);
		//Arm2Node->SetUpdateTransformation(baseMtx2);

	
}
Ball::~Ball(void)
{
	

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

	//if (m_bStatus == false)
	//return;

	//SetStatus(false);
	//SetIsDone(true);	// This method is to inform the EntityManager that it should remove this instance
	// Update Position
	//std::cout << "Ball Active: " << this->isDone << std::endl;


	position += m_vel*dt;

	//if(ballHead->);
	//ballHead->SetPosition(position);
	//if (!ballGun == NULL);
	//ballGun->SetPosition(Vector3(position.x, position.y + 15.8, position.z));
	//if (!ballArm1 == NULL)
	//ballArm1->SetPosition(Vector3(position.x + 10, position.y, position.z + 18));
	//if (!ballArm2 == NULL)
	//ballArm2->SetPosition(Vector3(position.x - 10, position.y, position.z + 18));

	Vector3 dispalcement = CPlayerInfo::GetInstance()->GetPos() - position;
	if (dispalcement.LengthSquared() < 500)
	{
		
	}

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
Ball* Create::ball(const Vector3& _position)
{
	//Mesh* modelMesh = MeshBuilder::GetInstance()->GetMesh(_meshName);
	//if (modelMesh == nullptr)
		//return nullptr;

	Ball* result = new Ball(_position);
	result->SetPosition(_position);
	//result->SetScale(_Scale);
	//result->SetVel(_direction);
	//result->SetSpeed(m_fSpeed);
	result->SetStatus(true);
	result->SetCollider(false);
	result->SetBall(true);
	EntityManager::GetInstance()->AddEntity(result,true);
	return result;
}

