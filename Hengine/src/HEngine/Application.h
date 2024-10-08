#pragma once

#include "Window.h"
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace HEngine
{
	class HENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}
