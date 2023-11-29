#pragma once

namespace Hyeon::enums
{
	enum class eComponentType
	{
		Transform, 
		SpriteRenderer, 
		Animator, 
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
		Animation, 
		Prefab,
		End
	};
}