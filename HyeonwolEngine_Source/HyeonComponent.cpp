#include "HyeonComponent.h"

namespace Hyeon
{
	HyeonComponent::HyeonComponent(enums::eComponentType type)
		:mType(type)
	{
	}

	HyeonComponent::~HyeonComponent()
	{
	}
	void HyeonComponent::Initialize()
	{
	}
	void HyeonComponent::Update()
	{
	}
	void HyeonComponent::LateUpdate()
	{
	}
	void HyeonComponent::Render(HDC hdc)
	{
	}
}