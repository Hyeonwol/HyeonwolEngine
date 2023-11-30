#include "HyeonSpriteRenderer.h"
#include "HyeonGameObject.h"
#include "HyeonTransform.h"
#include "HyeonTexture.h"
#include "HyeonRenderer.h"


namespace Hyeon
{
	HyeonSpriteRenderer::HyeonSpriteRenderer()
		:HyeonComponent(enums::eComponentType::SpriteRenderer),
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
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CalculatePos(pos);

		if (mTexture->GetTextureType() == 
			graphics::HyeonTexture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.X, pos.Y,
				mTexture->GetWidth() * mSize.X * scale.X, 
				mTexture->GetHeight() * mSize.Y * scale.Y,
				mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(),
				RGB(255, 0, 255));
		}

		else if (mTexture->GetTextureType() ==
			graphics::HyeonTexture::eTextureType::Png)
		{	//투명화시킬 픽셀의 색의 범위
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), 
				Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.X, pos.Y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.X, -pos.Y);

			graphics.DrawImage(mTexture->GetImg(),
				Gdiplus::Rect(
					pos.X, pos.Y, 
					mTexture->GetWidth() * mSize.X * scale.X, 
					mTexture->GetHeight() * mSize.Y * scale.Y
				), 0, 0, 
			mTexture->GetWidth(), mTexture->GetHeight(), 
				Gdiplus::UnitPixel, 
				nullptr);
		}
	}
}