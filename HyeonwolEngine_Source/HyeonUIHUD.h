#pragma once
#include "HyeonUIBase.h"
#include "HyeonTexture.h"

namespace Hyeon
{
    class HyeonUIHUD : public HyeonUIBase
    {
    public:
        HyeonUIHUD();
        ~HyeonUIHUD();

        virtual void OnInit() override;
        virtual void OnActive() override;
        virtual void OnInActive() override;
        virtual void OnUpdate() override;
        virtual void OnLateUpdate() override;
        virtual void OnRender(HDC hdc) override;
        virtual void OnClear() override;

    private:
        graphics::HyeonTexture* mTexture;
    };
}
