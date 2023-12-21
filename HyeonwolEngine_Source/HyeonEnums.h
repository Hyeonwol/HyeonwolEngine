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
		Tile, 
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

	enum class eCollidertype
	{
		Circle2D, 
		Rect2D, 
		End
	};
}