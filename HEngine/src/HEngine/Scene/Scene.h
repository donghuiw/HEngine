#pragma once

#include "HEngine/Core/Timestep.h"

#include <entt.hpp>

namespace HEngine
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();

		//TEMP
		entt::registry& Reg() { return m_Registry; }

		void OnUpdate(Timestep ts);
	private:
		entt::registry m_Registry;
	};
}