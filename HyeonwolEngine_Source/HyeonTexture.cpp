#include "HyeonTexture.h"
#include "HyeonApplication.h"
#include "HyeonResources.h"

extern Hyeon::HyeonApplication Application;

namespace Hyeon::graphics
{
	HyeonTexture* HyeonTexture::Create(const wstring& name, UINT width, UINT height)
	{
		HyeonTexture* image = HyeonResources::Find<HyeonTexture>(name);

		if (image)
			return image;

		image = new HyeonTexture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);

		HDC hdc = Application.GetHdc();
		HWND hwnd = Application.GetHwnd();

		image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
		image->mHDC = CreateCompatibleDC(hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHDC, image->mBitmap);
		DeleteObject(oldBitmap);

		HyeonResources::Insert(name + L"Image", image);

		return image;
	}
	HyeonTexture::HyeonTexture()
		:HyeonResource(enums::eResourceType::Texture), 
		 mbAlpha(false)
	{
	}
	HyeonTexture::~HyeonTexture()
	{
	}
	HRESULT HyeonTexture::Load(const wstring& path)
	{
		wstring ext = path.substr(path.find_last_of(L".") + 1);

		//확장자: bmp  //현재 mBitmap이 항상 nullptr인 현상 있음. 질문할 것
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC(Application.GetHdc());
			mHDC = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHDC, mBitmap);
			DeleteObject(oldBitmap);
		}

		//확장자: png
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImg = Gdiplus::Image::FromFile(path.c_str());

			if (mImg == nullptr)
				return S_FALSE;

			mWidth = mImg->GetWidth();
			mHeight = mImg->GetHeight();
		}

		return S_OK;
	}
}

