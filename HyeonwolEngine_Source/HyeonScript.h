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

        virtual void OnCollisionEnter(class HyeonCollider* other);
        virtual void OnCollisionStay(class HyeonCollider* other);
        virtual void OnCollisionExit(class HyeonCollider* other);
        
        Vector2 CollisionLocation;
    private:
        
    };
}
