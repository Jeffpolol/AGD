#include "Explosion.h"
#include "MeshBuilder.h"
#include "EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"

Explosion::Explosion(Mesh* _modelmesh)
{
	SetMesh(_modelmesh);
}

Explosion::~Explosion()
{

}

void Explosion::Update(double _dt)
{
	// Does nothing here, can inherit & override or create your own version of this class :D
}

Explosion* Create::explosion(const std::string& _meshName,
	const Vector3& _position)
{
	Mesh* modelMesh = MeshBuilder::GetInstance()->GetMesh(_meshName);
	if (modelMesh == nullptr)
		return nullptr;

	Explosion* result = new Explosion(modelMesh);
	result->SetPosition(_position);
	result->SetScale(Vector3(1,1,1));
	result->SetCollider(false);
	EntityManager::GetInstance()->AddEntity(result, true);
	return result;
}

