#pragma once
#include "..//HyeonwolEngine_Source/HyeonScene.h"

namespace Hyeon
{
    class HyeonForestBattleScene : public HyeonScene
    {
    public:
        HyeonForestBattleScene();
        ~HyeonForestBattleScene();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        void OnEnter() override;
        void OnExit() override;

        static Vector2 GetMonsterPos() { return ImpPos; }

    protected:
        bool isImpAttacked;

    private:
        class HyeonPlayer* Chrono;
        class HyeonPlayer* Ayla;
        class HyeonPlayer* Robo;
        class HyeonPlayer* RoboEffector;
        class HyeonMonster* GreenImp;
        static Vector2 ImpPos;
    };
}