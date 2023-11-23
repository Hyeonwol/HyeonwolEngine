#pragma once
#include "HyeonEntity.h"
#include "HyeonComponent.h"
#include "HyeonTexture.h"

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

		void SetTexture(graphics::HyeonTexture* Texture) { mTexture = Texture; }
		void SetSize(HyeonMath::Vector2 size) { mSize = size; }
	private:
		graphics::HyeonTexture* mTexture;
		HyeonMath::Vector2 mSize;
	};
}