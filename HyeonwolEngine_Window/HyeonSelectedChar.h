#pragma once
#include "HyeonBattlePlayerScript.h"

namespace Hyeon
{
    class HyeonSelectedChar : public HyeonBattlePlayerScript
    {
    public:
        HyeonSelectedChar();
        ~HyeonSelectedChar();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render(HDC hdc) override;

    private:
        Vector2 mChosenCharPos;
    };
}
