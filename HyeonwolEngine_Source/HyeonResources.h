#pragma once
#include "HyeonResource.h"

namespace Hyeon
{
	class HyeonResources
	{
	public:
		template <typename T>
		static T* Find(const wstring& key)
		{
			auto iter = mResources.find(key);
			if (iter == mResources.end())
				return nullptr;
			
			return dynamic_cast <T*>(iter->second);
		}

		template <typename T>
		static T* Load(const wstring& key, const wstring& path)
		{
			T* resource = HyeonResources::Find<T>(key);
			if (resource != nullptr)
				return resource;

			resource = new T();
			if (FAILED(resource->Load(path)))
				assert(false);

			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(make_pair(key, resource));

			return resource;
		}

		static void Insert(const wstring& key, HyeonResource* resource)
		{
			if (key == L"")
				return;
			if (resource == nullptr)
				return;

			mResources.insert(make_pair(key, resource));
		}

		static void Release()
		{
			for (auto& iter : mResources)
			{
				delete iter.second;
				iter.second = nullptr;
			}
		}

	private:
		static map<wstring, HyeonResource*> mResources;
	};
}
