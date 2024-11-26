#pragma once

#include "HEngine/Core/Base.h"
#include "HEngine/Core/Log.h"
#include "HEngine/Scene/Scene.h"
#include "HEngine/Scene/Entity.h"

namespace HEngine
{
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}