#pragma once
#include "HyeonEntity.h"
#include "HyeonComponent.h"

namespace Hyeon
{
	class HyeonSpriteRenderer : public HyeonComponent
	{
	public:
		HyeonSpriteRenderer();
		~HyeonSpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void ImageLoad(const wstring& path);
	private:
		Gdiplus::Image* mImage;
		UINT mWidth;
		UINT mHeight;
	};
}