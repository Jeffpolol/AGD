#ifndef ENTITY_BASE_H
#define ENTITY_BASE_H

#include "Vector3.h"

class EntityBase
{
public:

	enum Entity_Type
	{
		GO_BALL,
		GO_ASTEROID,
		GO_BULLET,
		GO_DEFAULT,
		GO_PLAYER,
		GO_UI,
	};

	EntityBase();
	virtual ~EntityBase();

	virtual void Update(double _dt);
	virtual void Render();
	virtual void RenderUI();
	virtual void RenderText();

	inline void SetPosition(const Vector3& _value){ position = _value; };
	inline Vector3 GetPosition(){ return position; };

	inline void SetScale(const Vector3& _value){ scale = _value; };
	inline Vector3 GetScale(){ return scale; };


	inline void SetIsBall(const bool ball){ this->isBall = ball; }
	inline bool GetBall(){ return isBall; }

	inline void SetType(Entity_Type type){ this->type = type; }
	inline Entity_Type GetType(){ return type; }


	bool IsDone();
	void SetIsDone(const bool _value);

	// Check if this entity has a collider class parent
	virtual bool HasCollider(void) const;
	// Set the flag to indicate if this entity has a collider class parent
	virtual void SetCollider(const bool _value);
	// Set the flag, bLaser
	virtual void SetIsLaser(const bool bLaser);
	// Get the flag, bLaser
	virtual bool GetIsLaser(void) const;

protected:
	Vector3 position;
	Vector3 scale;

	Entity_Type type;
	bool isDone;
	bool m_bCollider;
	bool bLaser;
};

#endif // ENTITY_BASE_H