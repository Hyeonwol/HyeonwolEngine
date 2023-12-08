#pragma once
#include "HyeonCollider.h"

namespace Hyeon
{
    class HyeonCircleCollider2D : public HyeonCollider
    {
    public:
        HyeonCircleCollider2D();
        ~HyeonCircleCollider2D();

        virtual void Initialize();
        virtual void Update();
        virtual void LateUpdate();
        virtual void Render(HDC hdc);

    private:
        float radius;
    };
}