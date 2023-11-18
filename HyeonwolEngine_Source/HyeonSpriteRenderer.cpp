#include "HyeonSpriteRenderer.h"
#include "HyeonGameObject.h"
#include "HyeonTransform.h"


namespace Hyeon
{
	HyeonSpriteRenderer::HyeonSpriteRenderer()
		:mImage(nullptr)
		,mWidth(0)
		,mHeight(0)
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
		HyeonTransform* tr = GetOwner()->GetComponent<HyeonTransform>();
		Vector2 pos = tr->GetPos();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.X, pos.Y, mWidth, mHeight));
	}
	void HyeonSpriteRenderer::ImageLoad(const wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}