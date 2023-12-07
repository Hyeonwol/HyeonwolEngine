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

		static HyeonTexture* Create(const wstring& name, UINT width, UINT height);

		HyeonTexture();
		virtual ~HyeonTexture();

		virtual HRESULT Load(const wstring& path) override;

		UINT GetWidth() { return mWidth; }
		void SetWidth(UINT width) { mWidth = width; }
		UINT GetHeight() { return mHeight; }
		void SetHeight(UINT height) { mHeight = height; }
		HDC GetHdc() { return mHDC; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImg() { return mImg; }

	private:
		bool mbAlpha;
		UINT mWidth;
		UINT mHeight;

		HDC mHDC;
		eTextureType mType;
		Gdiplus::Image* mImg;
		HBITMAP mBitmap;
	};
}
