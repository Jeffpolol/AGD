#ifndef WEAPON_ENTITY_H
#define WEAPON_ENTITY_H

#include "GenericEntity.h"
#include "WeaponInfo\WeaponInfo.h"
#include "Vector3.h"

class Mesh;

class WeaponEntity : public EntityBase
{
public:
	WeaponEntity(Mesh* _modelMesh);
	~WeaponEntity();

	virtual void Update(double dt);
	virtual void RenderUI();
	//void SetMaxScale(float scale);

	inline void SetWeapon(CWeaponInfo* weapon){ playerweapon = weapon; };

	inline void SetPosition(const Vector3& _value){ position = _value; };
	inline Vector3 GetPosition(){ return position; };

	inline void SetScale(const Vector3& _value){ scale = _value; };
	inline Vector3 GetScale(){ return scale; };

private:
	Vector3 position;
	Vector3 scale;
	float tilt;
	Mesh* modelMesh;
	CWeaponInfo* playerweapon;

};

namespace Create
{
	WeaponEntity* weapon(const std::string& _meshName,CWeaponInfo* weapon);
};
#endif