#include "HyeonCollider.h"
#include "HyeonScript.h"
#include "HyeonGameObject.h"

namespace Hyeon
{
	UINT HyeonCollider::CollisionID = 1;
	HyeonCollider::HyeonCollider(eCollidertype type)
		:HyeonComponent(enums::eComponentType::Collider),
		 mType(type), 
		 mID(CollisionID++),
		 mSize(Vector2::One)
	{
	}
	HyeonCollider::~HyeonCollider()
	{
	}
	void HyeonCollider::Initialize()
	{
	}
	void HyeonCollider::Update()
	{
	}
	void HyeonCollider::LateUpdate()
	{
	}
	void HyeonCollider::Render(HDC hdc)
	{
	}
	void HyeonCollider::OnCollisionEnter(HyeonCollider* other)
	{
		HyeonScript* script = GetOwner()->GetComponent<HyeonScript>();
		script->OnCollisionEnter(other);
	}
	void HyeonCollider::OnCollisionStay(HyeonCollider* other)
	{
		HyeonScript* script = GetOwner()->GetComponent<HyeonScript>();
		script->OnCollisionStay(other);
	}
	void HyeonCollider::OnCollisionExit(HyeonCollider* other)
	{
		HyeonScript* script = GetOwner()->GetComponent<HyeonScript>();
		script->OnCollisionExit(other);
	}
}