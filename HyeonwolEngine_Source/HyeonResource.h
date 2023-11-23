#pragma once
#include "HyeonEntity.h"

namespace Hyeon
{
	class HyeonResource abstract : public HyeonEntity
	{
	public:
		HyeonResource(enums::eResourceType type);
		virtual ~HyeonResource();

		virtual HRESULT Load(const wstring& path) = 0;

		const wstring& GetPath() { return mPath; }
		void SetPath(const wstring& path) { mPath = path; }
	private:
		const enums::eResourceType mType;
		wstring mPath;
	};
}
