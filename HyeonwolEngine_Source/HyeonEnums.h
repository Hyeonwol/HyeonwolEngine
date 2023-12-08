#pragma once

namespace Hyeon::enums
{
	enum class eComponentType
	{
		Transform, 
		Collider, 
		Script,
		SpriteRenderer, 
		Animator, 
		Camera, 
		End
	};

	enum class eLayerType
	{
		None, 
		BackGround, 
		Object, 
		Monster, 
		//Tree(Map?)
		//Character (Monster, NPC, ...)
		Player, 
		Particle, 
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