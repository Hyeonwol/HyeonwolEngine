#include "HyeonDestroy.h"
#include "HyeonGameObject.h"

namespace Hyeon::object
{
	void Destroy(HyeonGameObject* obj)
	{
		obj->Death();
	}
}