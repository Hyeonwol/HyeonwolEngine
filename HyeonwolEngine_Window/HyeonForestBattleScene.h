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
        static Vector2 GetChronoPos() { return ChronoPos; }
        static Vector2 GetAylaPos() { return AylaPos; }
        static Vector2 GetRoboPos() { return RoboPos; }

    private:
        class HyeonPlayer* Chrono;
        class HyeonPlayer* Ayla;
        class HyeonPlayer* Robo;
        class HyeonPlayer* SelectedChar;
        class HyeonMonster* GreenImp;
        class HyeonMonster* GreenImp2;
        class HyeonMonster* GreenImp3;
        static Vector2 ImpPos;
        static Vector2 Imp2Pos;
        static Vector2 Imp3Pos;
        static Vector2 ChronoPos;
        static Vector2 AylaPos;
        static Vector2 RoboPos;
    };
}