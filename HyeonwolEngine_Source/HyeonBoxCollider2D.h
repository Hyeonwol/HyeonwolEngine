#pragma once
#include "HyeonCollider.h"

namespace Hyeon
{
    class HyeonBoxCollider2D : public HyeonCollider
    {
    public:
        HyeonBoxCollider2D();
        ~HyeonBoxCollider2D();

        virtual void Initialize();
        virtual void Update();
        virtual void LateUpdate();
        virtual void Render(HDC hdc);

    private:
    };
}