#pragma once
#include "EntityBase.h"
#include "Vector3.h"
#include "Collider/Collider.h"
#include "LevelOfDetails\LevelOfDetails.h"
#include "SceneGraph\SceneNode.h"
#include "GenericEntity.h"
class Mesh;
//class CPlayerInfo;

class Ball : public EntityBase, public CCollider, public CLevelOfDetails
{
public:

	Ball(void);
	Ball(Mesh* _modelMesh);
	Ball(Vector3 Position);
	~Ball();


public:

	void SetSpeed(const float sped);

	// Activate the projectile. true == active, false == inactive
	void SetStatus(const bool m_bStatus);
	// get status of the projectile. true == active, false == inactive
	bool GetStatus(void) const;
	// Set the position and direction of the projectile
	Vector3 GetVel(void);

	void SetVel(Vector3 newvel);


	void setBallHead(GenericEntity* ballHead);
	GenericEntity* getBallHead();

	void setBallArm1(GenericEntity* ballArm);
	GenericEntity* getBallArm();
	
	void setBallArm2(GenericEntity* ballArm);
	GenericEntity* getBallArm2();

	void setBallGun(GenericEntity* ballGun);
	GenericEntity* getBallGun();


	//void setHeadNode(CSceneNode* node);
	//CSceneNode* getHeadNode();

	//void setArm1Node(CSceneNode* node);
	//CSceneNode* getArm1Node();

	//void setArm2Node(CSceneNode* node);
	//CSceneNode* getArm2Node();

	//void setGunNode(CSceneNode* node);
	//CSceneNode* getGunNode();



	// Update the status of this projectile
	virtual void Update(double dt = 0.0333f);
	// Render this projectile
	virtual void Render(void);


protected:
	// The model mesh for this projectile
	Mesh* modelMesh;
	Mesh* DeathMesh;
	// Boolean flag to indicate if this projectile is active. If not active, then do not compute/update
	bool m_bStatus;

	float m_speed;
	// The direction of the projectile
	Vector3 m_vel;


	CSceneNode* HeadNode;// = CSceneGraph::GetInstance()->AddNode(ballRobot);
	CSceneNode* Arm1Node;
	CSceneNode* Arm2Node;
	CSceneNode* GunNode;

	GenericEntity* ballHead;
	GenericEntity* ballArm1;
	GenericEntity* ballArm2;
	GenericEntity* ballGun;



};

namespace Create
{
	Ball* ball(const std::string& _meshName,
		const Vector3& _position,
		const Vector3& _velocity,
		const Vector3& _Scale,
		const float m_Speed );
};

