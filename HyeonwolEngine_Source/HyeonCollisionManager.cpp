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
		//�� �浹ü ��ȣ�� ������ ID�� Ȯ���Ͽ� CollisionID ����
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		//���� �浹 ������ �˻��Ͽ�
		//���� �浹 ������ ���ٸ�
		//�浹 ������ �����Ѵ�.

		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		//�浹 ���� check
		if (InterSect(left, right))
		{
			//������ �ִ� �浹
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);

				iter->second = true;
			}

			//�浹�� ���¸� ��� ������
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}

		//�浹�� ���¿��� ���(�浹�� ���¿��ٰ� ���� ������)
		if (iter->second == true)
		{
			left->OnCollisionExit(right);
			right->OnCollisionExit(left);

			iter->second = false;
		}
	}
	bool HyeonCollisionManager::InterSect(HyeonCollider* left, HyeonCollider* right)
	{
		HyeonTransform* leftTr = left->GetOwner()->GetComponent<HyeonTransform>();
		HyeonTransform* rightTr = right->GetOwner()->GetComponent<HyeonTransform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		//size ������ 1, 1�� �ϸ� �⺻ ũ��� 100pixel
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 righttSize = right->GetSize() * 100.0f;

		//AABB Collision
		if (fabs(leftPos.X - rightPos.X) < fabs(leftPos.X / 2.0f + rightPos.X / 2.0f)
			&& fabs(leftPos.Y - rightPos.Y) < fabs(leftPos.Y / 2.0f + rightPos.Y / 2.0f))
		{
			return true;
		}

		return false;
	}
}