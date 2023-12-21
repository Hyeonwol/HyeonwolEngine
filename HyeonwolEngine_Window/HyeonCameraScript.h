#pragma once
#include "..//HyeonwolEngine_Source/HyeonScript.h"
#include "..//HyeonwolEngine_Source/HyeonTransform.h"

namespace Hyeon
{
    class HyeonCameraScript : public HyeonScript
    {
    public:
        HyeonCameraScript();
        ~HyeonCameraScript();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

    private:

    };
}
