#pragma once
#include "CommonInclude.h"
#include "HyeonBoxCollider2D.h"
#include "HyeonCircleCollider2D.h"

namespace Hyeon
{
	using namespace enums;

	union CollisionID
	{
		struct 
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class HyeonCollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
		static void LayerCollision(class HyeonScene* scene, eLayerType left, eLayerType right);
		static void ColliderCollision(HyeonCollider* left, HyeonCollider* right);
		static bool InterSect(HyeonCollider* left, HyeonCollider* right);
	private:
		static bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
		
		static unordered_map<UINT64, bool> mCollisionMap;
	};
}