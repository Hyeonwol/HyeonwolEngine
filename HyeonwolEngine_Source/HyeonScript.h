#pragma once
#include "HyeonComponent.h"

namespace Hyeon
{
    class HyeonScript : public HyeonComponent
    {
    public:
        HyeonScript();
        ~HyeonScript();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

    private:

    };
}
