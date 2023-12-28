#include "HyeonTileMapRenderer.h"
#include "HyeonTransform.h"
#include "HyeonGameObject.h"
#include "HyeonRenderer.h"

namespace Hyeon
{
	Vector2 HyeonTileMapRenderer::TileSize = Vector2::One;
	Vector2 HyeonTileMapRenderer::OriginTileSize = Vector2::One;
	Vector2 HyeonTileMapRenderer::SelectedIndex = Vector2::One;

	HyeonTileMapRenderer::HyeonTileMapRenderer()
		:HyeonComponent(enums::eComponentType::SpriteRenderer), 
		 mTexture(nullptr), 
		 mSize(3.0f, 3.0f),
		 mIndex(0, 0),
		 mTileSize(16.0f, 16.0f)
	{
		TileSize = mTileSize * mSize;
		OriginTileSize = mTileSize;
	}
	HyeonTileMapRenderer::~HyeonTileMapRenderer()
	{
	}
	void HyeonTileMapRenderer::Initialize()
	{
	}
	void HyeonTileMapRenderer::Update()
	{
	}
	void HyeonTileMapRenderer::LateUpdate()
	{
	}
	void HyeonTileMapRenderer::Render(HDC hdc)
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
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; //0(완전투명)~255(완전불투명)

				AlphaBlend(hdc,
					pos.X,
					pos.Y,
					mTileSize.X * mSize.X * scale.X,
					mTileSize.Y * mSize.Y * scale.Y,
					mTexture->GetHdc(),
					mIndex.X * mTileSize.X, mIndex.Y * mTileSize.Y,
					mTileSize.X,
					mTileSize.Y,
					func);
			}

			else
			{
				TransparentBlt(hdc,
					pos.X,
					pos.Y,
					mTileSize.X * mSize.X * scale.X,
					mTileSize.Y * mSize.Y * scale.Y,
					mTexture->GetHdc(),
					mIndex.X * mTileSize.X, mIndex.Y * mTileSize.Y,
					mTileSize.X,
					mTileSize.Y,
					RGB(179, 38, 195));
			}
		}
	}
}