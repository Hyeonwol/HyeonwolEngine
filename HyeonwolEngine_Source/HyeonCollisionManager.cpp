#include "HyeonCollisionManager.h"
#include "HyeonScene.h"
#include "HyeonSceneManager.h"
#include "HyeonGameObject.h"
#include "HyeonCollider.h"

namespace Hyeon
{
	bitset<(UINT)eLayerType::Max> HyeonCollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};

	void HyeonCollisionManager::Initialize()
	{
		int a = 1;
		int b = a << 1;
	}
	void HyeonCollisionManager::Update()
	{
		HyeonScene* scene = HyeonSceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++) 
			{
				if (mCollisionLayerMatrix[row][col] == true)
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
			}
		}
	}
	void HyeonCollisionManager::LateUpdate()
	{
	}
	void HyeonCollisionManager::Render(HDC hdc)
	{
	}
	void HyeonCollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}
	void HyeonCollisionManager::LayerCollision(HyeonScene* scene, eLayerType left, eLayerType right)
	{
		const vector<HyeonGameObject*>& lefts = scene->GetLayer(left)->GetGameObject();
		const vector<HyeonGameObject*>& rights = scene->GetLayer(right)->GetGameObject();

		for (HyeonGameObject* left : lefts)
		{
			if (left->isActive() == false)
				continue;
			HyeonCollider* leftCol = left->GetComponent<HyeonCollider>();
			if (leftCol == nullptr)
				continue;

			for (HyeonGameObject* right : rights)
			{
				if (right->isActive() == false)
					continue;
				HyeonCollider* rightCol = right->GetComponent<HyeonCollider>();
				if (rightCol == nullptr)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}
	}
	void HyeonCollisionManager::ColliderCollision(HyeonCollider* left, HyeonCollider* right)
	{

	}
}