#pragma once
#include "HyeonScene.h"

namespace Hyeon
{
    class HyeonDontDestroyOnLoad : public HyeonScene
    {
    public:
        HyeonDontDestroyOnLoad();
        ~HyeonDontDestroyOnLoad();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void OnEnter() override;
        void OnExit() override;

    private:

    };
}
