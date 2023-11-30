#include "HyeonCamera.h"
#include "HyeonApplication.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"

extern Hyeon::HyeonApplication Application;

namespace Hyeon
{
	HyeonCamera::HyeonCamera()
		:HyeonComponent(enums::eComponentType::Camera),
		mDistance(Vector2::Zero),
		mResolution(Vector2::Zero), 
		mLookPosition(Vector2::Zero),
		mTarget(nullptr)
	{
	}
	HyeonCamera::~HyeonCamera()
	{
	}
	void HyeonCamera::Initialize()
	{
		mResolution.X = Application.GetWidth();
		mResolution.Y = Application.GetHeight();
	}
	void HyeonCamera::Update()
	{
		if (mTarget)
		{
			HyeonTransform* tr = mTarget->GetComponent<HyeonTransform>();
			mLookPosition = tr->GetPosition();
		}

		HyeonTransform* cameraTr = GetOwner()->GetComponent<HyeonTransform>();
		mLookPosition = cameraTr->GetPosition();

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	void HyeonCamera::LateUpdate()
	{
	}
	void HyeonCamera::Render(HDC hdc)
	{
	}
}