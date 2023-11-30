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
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePos(pos);

		Sprite sprite = mAnimationSheet[mindex];

		graphics::HyeonTexture::eTextureType type = mTexture->GetTextureType();
		if (type == graphics::HyeonTexture::eTextureType::Bmp)
		{

			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255; //0(완전투명)~255(완전불투명)

			HDC imgHdc = mTexture->GetHdc();


			TransparentBlt(hdc, pos.X, pos.Y,
				sprite.size.X * scale.X, sprite.size.Y * scale.Y,
				imgHdc, sprite.leftTop.X, sprite.leftTop.Y,
				sprite.size.X, sprite.size.Y,
				RGB(255, 0, 255));


			//현재 알파블렌드 사용 시 마젠타색이 지워지지 않는 증상 있음. 
			//선생님께 질문드릴 것

			/*AlphaBlend(hdc,
				pos.X, pos.Y,
				sprite.size.X, sprite.size.Y,
				imgHdc,
				sprite.leftTop.X,
				sprite.leftTop.Y,
				sprite.size.X,
				sprite.size.Y,
				func);*/

			
		}
		
		else if (type == graphics::HyeonTexture::eTextureType::Png)
		{
			Gdiplus::Graphics GdiGraphics(hdc);
			GdiGraphics.TranslateTransform(pos.X, pos.Y);
			GdiGraphics.RotateTransform(rot);
			GdiGraphics.TranslateTransform(-pos.X, -pos.Y);
			
			GdiGraphics.DrawImage(mTexture->GetImg(),
				Gdiplus::Rect(
					pos.X - (sprite.size.X / 2.0f),
					pos.Y - (sprite.size.Y / 2.0f),
					sprite.size.X * scale.X,
					sprite.size.Y * scale.Y
				),
				sprite.leftTop.X,
				sprite.leftTop.Y,
				sprite.size.X,
				sprite.size.Y,
				Gdiplus::UnitPixel,
				nullptr
			);
		}
		
		
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