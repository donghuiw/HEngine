#pragma once

#include "HEngine/Core/Window.h"
#include "HEngine/Core/Base.h"
#include "HEngine/Core/LayerStack.h"
#include "HEngine/Events/Event.h"
#include "HEngine/Events/ApplicationEvent.h"
#include "HEngine/ImGui/ImGuiLayer.h"

namespace HEngine
{
	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			HE_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};

	class  Application
	{
	public:
		Application(const std::string& name = "HEngine App", ApplicationCommandLineArgs args = ApplicationCommandLineArgs());
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window;  }
		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance;  }

		ApplicationCommandLineArgs GetCommandLineArgs() const { return m_CommandLineArgs; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		ApplicationCommandLineArgs m_CommandLineArgs;
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication(ApplicationCommandLineArgs args);
}
