#pragma once
#include "HyeonComponent.h"

namespace Hyeon
{
    class HyeonCollider : public HyeonComponent
    {
    public:
        HyeonCollider();
        ~HyeonCollider();

        virtual void Initialize();
        virtual void Update();
        virtual void LateUpdate();
        virtual void Render(HDC hdc);

        Vector2 GetOffset() { return mOffset; }
        void SetOffset(Vector2 offset) { mOffset = offset; }
    private:
        Vector2 mOffset;
    };
}