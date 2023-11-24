#pragma once

namespace Hyeon::enums
{
	enum class eComponentType
	{
		Transform, 
		SpriteRenderer, 
		Script, 
		Camera, 
		End
	};

	enum class eLayerType
	{
		None, 
		BackGround, 
		Object, 
		//Tree(Map?)
		//Character (Monster, NPC, ...)
		Player, 
		Max = 16
	};

	enum class eResourceType
	{
		Texture, 
		AudioClip,
		Prefab,
		End
	};
}