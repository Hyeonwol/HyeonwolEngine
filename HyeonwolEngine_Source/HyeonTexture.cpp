#include "HyeonTexture.h"
#include "HyeonApplication.h"

extern Hyeon::HyeonApplication Application;

namespace Hyeon::graphics
{
	HyeonTexture::HyeonTexture()
		:HyeonResource(enums::eResourceType::Texture)
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
			mBitmap = (HBITMAP)LoadImageW(NULL, path.c_str(), IMAGE_BITMAP
				, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

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

