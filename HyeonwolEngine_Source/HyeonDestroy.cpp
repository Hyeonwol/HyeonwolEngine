#include "HyeonDestroy.h"
#include "HyeonGameObject.h"

namespace Hyeon
{
	void Destroy(HyeonGameObject* obj)
	{
		obj->Death();
	}
}