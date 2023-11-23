#pragma once
#include "HyeonResource.h"

namespace Hyeon::graphics
{
	class HyeonTexture : public HyeonResource
	{
	public:
		enum class eTextureType
		{
			Bmp, 
			Png, 
			None
		};

		HyeonTexture();
		virtual ~HyeonTexture();

		virtual HRESULT Load(const wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHDC; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImg() { return mImg; }

	private:
		UINT mWidth;
		UINT mHeight;

		HDC mHDC;
		eTextureType mType;
		Gdiplus::Image* mImg;
		HBITMAP mBitmap;
	};
}
