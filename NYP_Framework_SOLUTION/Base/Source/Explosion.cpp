#include "Explosion.h"
#include "MeshBuilder.h"
#include "EntityManager.h"
#include "GraphicsManager.h"
#include "RenderHelper.h"

Explosion::Explosion(Mesh* _modelmesh)
{
	SetMesh(_modelmesh);
	ismax = false;
	m_lifetime = 1.2;
}

Explosion::~Explosion()
{
	ismax = false;
	m_lifetime = 1.2;
}

void Explosion::SetMaxScale(float size)
{
	m_maxscale = size;
}

void Explosion::Update(double _dt)
{
	if (GetScale().x < m_maxscale * 5 && !ismax)
		SetScale(Vector3(GetScale().x + _dt * 200, GetScale().y + _dt * 200, GetScale().z + _dt * 200));
	else
		ismax = true;

	if (ismax)
	{
		m_lifetime -= _dt;
		SetScale(Vector3(GetScale().x - _dt * 10, GetScale().y - _dt * 10, GetScale().z - _dt * 10));
		if (m_lifetime < 0.0f)
		{
			SetIsDone(true);	// This method is to inform the EntityManager that it should remove this instance
			return;
		}

	}
	



	// Does nothing here, can inherit & override or create your own version of this class :D
}

Explosion* Create::explosion(const std::string& _meshName, const Vector3& _scale,
	const Vector3& _position)
{
	Mesh* modelMesh = MeshBuilder::GetInstance()->GetMesh(_meshName);
	if (modelMesh == nullptr)
		return nullptr;

	Explosion* result = new Explosion(modelMesh);
	result->SetPosition(_position);
	result->SetScale(Vector3(1,1,1));
	result->SetMaxScale(_scale.x);
	result->SetCollider(false);
	EntityManager::GetInstance()->AddEntity(result, true);
	return result;
}

