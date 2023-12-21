#pragma once
#include "HyeonComponent.h"
#include "HyeonTexture.h"
#include "HyeonEntity.h"

namespace Hyeon
{
    class HyeonTileMapRenderer : public HyeonComponent
    {
    public:
        HyeonTileMapRenderer();
        ~HyeonTileMapRenderer();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void SetTexture(graphics::HyeonTexture* texture) { mTexture = texture; }
        void SetSize(Vector2 size) { mSize = size; }
        void SetIndex(Vector2 index) { mIndex = index; }

    public:
        static Vector2 TileSize;
        static Vector2 OriginTileSize;
        static Vector2 SelectedIndex;

    private:
        graphics::HyeonTexture* mTexture;
        Vector2 mSize;
        Vector2 mTileSize;
        Vector2 mIndex;
    };
}
