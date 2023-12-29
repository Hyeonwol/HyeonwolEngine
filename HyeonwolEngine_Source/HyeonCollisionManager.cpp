#include "HyeonCollisionManager.h"
#include "HyeonScene.h"
#include "HyeonSceneManager.h"
#include "HyeonGameObject.h"
#include "HyeonCollider.h"
#include "HyeonTransform.h"

namespace Hyeon
{
	bitset<(UINT)eLayerType::Max> HyeonCollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	unordered_map<UINT64, bool> HyeonCollisionManager::mCollisionMap = {};

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
	void HyeonCollisionManager::Clear()
	{
		mCollisionMap.clear();
		mCollisionLayerMatrix->reset();
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
		const vector<HyeonGameObject*>& lefts = HyeonSceneManager::GetGameObjects(left);
		const vector<HyeonGameObject*>& rights = HyeonSceneManager::GetGameObjects(right);

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
		//두 충돌체 번호로 가져온 ID를 확인하여 CollisionID 세팅
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		//이전 충돌 정보를 검색하여
		//만약 충돌 정보가 없다면
		//충돌 정보를 생성한다.

		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		//충돌 여부 check
		if (InterSect(left, right))
		{
			//떨어져 있다 충돌
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);

				iter->second = true;
			}

			//충돌한 상태를 계속 유지중
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			//충돌한 상태에서 벗어남(충돌한 상태였다가 서로 떨어짐)
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}
	bool HyeonCollisionManager::InterSect(HyeonCollider* left, HyeonCollider* right)
	{
		HyeonTransform* leftTr = left->GetOwner()->GetComponent<HyeonTransform>();
		HyeonTransform* rightTr = right->GetOwner()->GetComponent<HyeonTransform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		//size 세팅을 1, 1로 하면 기본 크기는 100pixel
		Vector2 leftSize = left->GetSize() * 70.0f;
		Vector2 rightSize = right->GetSize() * 70.0f;

		//AABB Collision

		enums::eCollidertype leftType = left->GetColliderType();
		enums::eCollidertype rightType = right->GetColliderType();

		if (leftType == enums::eCollidertype::Rect2D
			&& rightType == enums::eCollidertype::Rect2D)
		{
			if (fabs(leftPos.X - rightPos.X) < fabs(leftSize.X / 2.0f + rightSize.X / 2.0f)
				&& fabs(leftPos.Y - rightPos.Y) < fabs(leftSize.Y / 2.0f + rightSize.Y / 2.0f))
			{
				return true;
			}
		}

		if (leftType == enums::eCollidertype::Circle2D
			&& rightType == enums::eCollidertype::Circle2D)
		{
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);
			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= (leftSize.X / 2.0f + rightSize.X / 2.0f))
			{
				return true;
			}
		}

		if (leftType == enums::eCollidertype::Rect2D && rightType == enums::eCollidertype::Circle2D
			|| leftType == enums::eCollidertype::Circle2D && rightType == enums::eCollidertype::Rect2D)
		{
			//숙제
		}

		return false;
	}
}