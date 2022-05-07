#include "dkpch.h"
#include "Entity.h"

namespace Dorek {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}