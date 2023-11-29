#include "HyeonAnimation.h"
#include "HyeonTime.h"
#include "HyeonGameObject.h"
#include "HyeonAnimator.h"
#include "HyeonTransform.h"
#include "HyeonRenderer.h"

namespace Hyeon
{
	HyeonAnimation::HyeonAnimation()
		:HyeonResource(Hyeon::enums::eResourceType::Animation), 
		 mAnimator(nullptr), 
		 mTexture(nullptr),
		 mAnimationSheet{}, 
		 mindex(-1), 
		 mTime(0.0f), 
		 mbComplete(false)
		 
	{
	}
	HyeonAnimation::~HyeonAnimation()
	{
	}
	HRESULT HyeonAnimation::Load(const wstring& path)
	{
		return E_NOTIMPL;
	}
	void HyeonAnimation::Update()
	{
		if (mbComplete)
			return;
		mTime += HyeonTime::GetDelataTime();

		if (mAnimationSheet[mindex].duration < mTime)
		{
			mTime = 0.0f;
			if (mindex < mAnimationSheet.size() - 1)
				mindex++;
			else
				mbComplete = true;
		}
	}
	void HyeonAnimation::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			return;

		HyeonGameObject* gameobj = mAnimator->GetOwner();
		HyeonTransform* tr = gameobj->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPos();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePos(pos);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255; //0(완전투명)~255(완전불투명)

		Sprite sprite = mAnimationSheet[mindex];
		HDC imgHdc = mTexture->GetHdc();

		/*AlphaBlend(hdc,
			pos.X, pos.Y,
			sprite.size.X, sprite.size.Y,
			imgHdc,
			sprite.leftTop.X,
			sprite.leftTop.Y,
			sprite.size.X,
			sprite.size.Y,
			func);*/
		TransparentBlt(hdc, pos.X, pos.Y,
			sprite.size.X, sprite.size.Y,
			imgHdc, sprite.leftTop.X, sprite.leftTop.Y, 
			sprite.size.X, sprite.size.Y,
			RGB(255, 0, 255));
	}
	void HyeonAnimation::CreateAnimation(const wstring& name, 
		graphics::HyeonTexture* spriteSheet, 
		Vector2 leftTop, Vector2 size, 
		Vector2 offset, UINT spriteLength, 
		float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.X = leftTop.X + (size.X * i);
			sprite.leftTop.Y = leftTop.Y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}
	void HyeonAnimation::Reset()
	{
		mindex = 0;
		mTime = 0.0f;
		mbComplete = false;
	}
}