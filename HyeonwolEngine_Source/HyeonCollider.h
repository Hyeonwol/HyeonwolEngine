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

        virtual void OnCollisionEnter(HyeonCollider* other);
        virtual void OnCollisionStay(HyeonCollider* other);
        virtual void OnCollisionExit(HyeonCollider* other);

        Vector2 GetOffset() { return mOffset; }
        void SetOffset(Vector2 offset) { mOffset = offset; }
        UINT32 GetID() { return mID; }
        Vector2 GetSize() { return mSize; }
        void SetSize(Vector2 size) { mSize = size; }

    private:
        static UINT CollisionID;
        Vector2 mOffset;
        UINT32 mID;
        Vector2 mSize;
    };
}