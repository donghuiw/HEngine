#include "HEngine.h"
#include "imgui/imgui.h"

class ExampleLayer : public HEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}
	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
	void OnUpdate() override
	{
		if (HEngine::Input::IsKeyPressed(HE_KEY_TAB))
			HE_TRACE("Tab key is pressed (poll)!");
	}
	void OnEvent(HEngine::Event& event) override
	{
		if (event.GetEventType() == HEngine::EventType::KeyPressed)
		{
			HEngine::KeyPressedEvent& e = (HEngine::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HE_KEY_TAB)
				HE_TRACE("Tab key is pressed (event)!");
			HE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};
class SandBox : public HEngine::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}
	~SandBox()
	{

	}
};
HEngine::Application* HEngine::CreateApplication()
{
	return new SandBox();
}