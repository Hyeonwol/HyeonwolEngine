#pragma once
#include "..//HyeonwolEngine_Source/HyeonScene.h"

namespace Hyeon
{
    class HyeonBattleScene : public HyeonScene
    {
    public:
        HyeonBattleScene();
        ~HyeonBattleScene();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void OnEnter() override;
        void OnExit() override;

    private:
        class HyeonPlayer* Chrono;
        class HyeonPlayer* Ayla;
        class HyeonMonster* GreenImp;
    };
}