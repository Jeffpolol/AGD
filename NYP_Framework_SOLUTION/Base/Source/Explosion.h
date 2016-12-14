#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "GenericEntity.h"

class Mesh;

class Explosion: public GenericEntity
{
public:
	Explosion(Mesh* _modelMesh);
	~Explosion();

	virtual void Update(double dt);
	void SetMaxScale(float scale);

private:

	bool ismax;
	float m_lifetime;
	float m_maxscale;

};

namespace Create
{
	Explosion* explosion(const std::string& _meshName,
		const Vector3& _position, const Vector3& _scale);
};
#endif