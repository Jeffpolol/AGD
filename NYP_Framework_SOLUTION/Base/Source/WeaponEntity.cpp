#include "WeaponEntity.h"
#include "MeshBuilder.h"
#include "EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"

WeaponEntity::WeaponEntity(Mesh* _modelmesh):
modelMesh(_modelmesh),
position(0.0f, 0.0f, 0.0f),
scale(1.0f, 1.0f, 1.0f),
tilt(0)
{


}

WeaponEntity::~WeaponEntity()
{

}

void WeaponEntity::Update(double dt)
{

	//if (playerweapon->GetIsreload())
	//{
	//	tilt += dt * 40;
	//	position.y -= dt * 3;
	//	return;
	//}
	//else
	//{
	//	if (position.y < -1.4)
	//		position.y += dt * 5;

	//		tilt = 0;
	//}
	
	if (!playerweapon->GetCanFire() && position.z > -1.7)
		position.z -= dt*5;
	else
		position.z = -1.0;

}
void WeaponEntity::RenderUI(void)
{

	MS& modelStack = GraphicsManager::GetInstance()->GetModelStack();
	modelStack.PushMatrix();
	modelStack.Translate(position.x, position.y, position.z);
	modelStack.Rotate(5, 0, 1, 0);
	modelStack.Rotate(10+tilt, 1, 0, 0);
	modelStack.Scale(scale.x, scale.y, scale.z);
	RenderHelper::RenderMesh(modelMesh);
	modelStack.PopMatrix();

}

WeaponEntity* Create::weapon(const std::string& _meshName, CWeaponInfo* weapon)
{
	Mesh* modelMesh = MeshBuilder::GetInstance()->GetMesh(_meshName);
	if (modelMesh == nullptr)
		return nullptr;

	WeaponEntity* result = new WeaponEntity(modelMesh);
	result->SetPosition(Vector3(0.2, -1.4, -1.7));
	result->SetScale(Vector3(1, 1, 1));
	result->SetCollider(false);
	result->SetWeapon(weapon);
	EntityManager::GetInstance()->AddEntity(result, true);
	return result;
}

