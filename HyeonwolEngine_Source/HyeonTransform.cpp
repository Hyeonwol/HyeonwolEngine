#include "HyeonTransform.h"

namespace Hyeon
{
	HyeonTransform::HyeonTransform()
		:HyeonComponent(enums::eComponentType::Transform), 
		mScale(Vector2::One), 
		mRotation(0.0f)
	{
	}
	HyeonTransform::~HyeonTransform()
	{
	}
	void HyeonTransform::Initialize()
	{
	}
	void HyeonTransform::Update()
	{
	}
	void HyeonTransform::LateUpdate()
	{
	}
	void HyeonTransform::Render(HDC hdc)
	{
	}
}