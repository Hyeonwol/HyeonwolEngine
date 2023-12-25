﻿// Editor_Window.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Editor_Window.h"
#include "..\\HyeonwolEngine_Source\HyeonApplication.h"
#include "..\\HyeonwolEngine_Source\HyeonResources.h"
#include "..\\HyeonwolEngine_Source\HyeonTexture.h"
#include "..\\HyeonwolEngine_Source\HyeonSceneManager.h"

#include "..\\HyeonwolEngine_Window\HyeonLoadResources.h"
#include "..\\HyeonwolEngine_Window\HyeonLoadScenes.h"
#include "..\\HyeonwolEngine_Window\HyeonToolScene.h"

Hyeon::HyeonApplication Application;

ULONG_PTR gpToken;
Gdiplus::GdiplusStartupInput gpsi;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance, const wchar_t* name, WNDPROC proc);
BOOL                InitInstance(HINSTANCE, int);
BOOL                InitToolScene(HINSTANCE);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, //프로그램의 인스턴스 핸들
    _In_opt_ HINSTANCE hPrevInstance, // 바로앞에 실행된 현재 프로그램의 인스턴스 핸들, 없을경우에는 NULL 
    // 지금은 신경쓰지 않아도 되는 값이다.
    _In_ LPWSTR    lpCmdLine, //명령행 으로 입력된 프로그램 인수라고 하는데
    _In_ int       nCmdShow) //프로그램이 실행될 형태이며, 보통 모양정보등이 전달된다.
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    ///

    ///
    //
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance, szWindowClass, WndProc);
    MyRegisterClass(hInstance, L"TILEWINDOW", WndTileProc);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));
    MSG msg;

    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            Application.Run();
        }
    }
    Gdiplus::GdiplusShutdown(gpToken);

    Gdiplus::GdiplusShutdown(gpToken);
    Application.Release();

    return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance, const wchar_t* name, WNDPROC proc)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = proc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;//MAKEINTRESOURCEW(IDC_EDITORWINDOW);
    wcex.lpszClassName  = name;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    const UINT width = 1200;
    const UINT height = 1000;

    //배경 원래 해상도
    //766, 752

    //const UINT width = 300;    //원래 해상도
    //const UINT height = 250;

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, width, height, nullptr, nullptr, hInstance, nullptr);

    Application.Initialize(hWnd, width, height);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    Gdiplus::GdiplusStartup(&gpToken, &gpsi, NULL);

    Hyeon::LoadResources();
    Hyeon::LoadScenes();

    InitToolScene(hInstance);

    int a = 0;
    srand(UINT(&a));

    return TRUE;
}

BOOL InitToolScene(HINSTANCE hInstance)
{
    Hyeon::HyeonScene* activeScene = Hyeon::HyeonSceneManager::GetActiveScene();
    wstring name = activeScene->GetName();

    if (name == L"ToolScene")
    {
        HWND ToolHWnd = CreateWindowW(L"TILEWINDOW", L"Tilewindow", WS_OVERLAPPEDWINDOW,
            0, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

        Hyeon::graphics::HyeonTexture* texture
            = Hyeon::HyeonResources::Find<Hyeon::graphics::HyeonTexture>(L"BlackOmen");

        RECT rect = { 0, 0, texture->GetWidth(), texture->GetHeight() };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

        UINT toolWidth = rect.right - rect.left;
        UINT toolHeight = rect.bottom - rect.top;

        SetWindowPos(ToolHWnd, nullptr, 1200, 0, toolWidth, toolHeight, 0);
        ShowWindow(ToolHWnd, true);
        UpdateWindow(ToolHWnd);
    }

    return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
