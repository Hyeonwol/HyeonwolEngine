#pragma once
#include "HyeonEntity.h"

namespace Hyeon
{
    using namespace enums;
    class HyeonUIBase : public HyeonEntity
    {
    public:
        struct Event
        {
            void operator=(function<void()> func)
            {
                mEvent = move(func);
            }
            void operator()()
            {
                if (mEvent)
                    mEvent();
            }

            function<void()> mEvent;
        };

        HyeonUIBase(eUIType type);
        virtual ~HyeonUIBase();

        //UI가 처음 로드 될 때 실행
        void Initialize();

        //UI가 활성화될 때 실행
        void Active();
        //UI가 비활성화되면 실행
        void InActive();

        void Update();
        void LateUpdate();
        void Render(HDC hdc);

        //UI가 사라지면 실행
        void UIClear();

        virtual void OnInit();
        virtual void OnActive();
        virtual void OnInActive();
        virtual void OnUpdate();
        virtual void OnLateUpdate();
        virtual void OnRender(HDC hdc);
        virtual void OnClear();

        eUIType GetType() { return mType; }
        void SetType(eUIType type) { mType = type; }
        void SetFullScreen(bool enable) { mbFullScreen = enable; }
        bool IsFullScreen() { return mbFullScreen; }
        Vector2 GetPos() { return mPosition; }
        void SetPos(Vector2 pos) { mPosition = pos; }
        Vector2 GetSize() { return mSize; }
        void SetSize(Vector2 size) { mSize = size; }

    protected:
        Vector2 mPosition;
        Vector2 mSize;
        bool mbMouseOn;
    private:
        eUIType mType;
        bool mbFullScreen;
        bool mbEnabled;

        HyeonUIBase* mParent;
    };
}
