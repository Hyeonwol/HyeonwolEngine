#include "HyeonSpriteRenderer.h"
#include "HyeonGameObject.h"
#include "HyeonTransform.h"
#include "HyeonTexture.h"


namespace Hyeon
{
	HyeonSpriteRenderer::HyeonSpriteRenderer()
		:HyeonComponent(),
		mTexture(nullptr),
		mSize(Vector2::One)
	{
	}
	HyeonSpriteRenderer::~HyeonSpriteRenderer()
	{
	}
	void HyeonSpriteRenderer::Initialize()
	{
	}
	void HyeonSpriteRenderer::Update()
	{
	}
	void HyeonSpriteRenderer::LateUpdate()
	{
	}
	void HyeonSpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);


		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPos();

		if (mTexture->GetTextureType() == 
			graphics::HyeonTexture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.X, pos.Y,
				mTexture->GetWidth() * mSize.X, mTexture->GetHeight() * mSize.Y,
				mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(),
				RGB(255, 0, 255));
		}

		else if (mTexture->GetTextureType() ==
			graphics::HyeonTexture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImg(),
				Gdiplus::Rect(pos.X, pos.Y, 
					mTexture->GetWidth() * mSize.X, mTexture->GetHeight() * mSize.Y));
		}
	}
}