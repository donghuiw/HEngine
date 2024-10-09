#include "HEngine.h"

class ExampleLayer : public HEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}
	void OnUpdate() override
	{
		HE_INFO("ExampleLayer::Update");
	}
	void OnEvent(HEngine::Event& event) override
	{
		HE_TRACE("{0}", event);
	}
};
class SandBox : public HEngine::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new HEngine::ImGuiLayer());
	}
	~SandBox()
	{

	}
};
HEngine::Application* HEngine::CreateApplication()
{
	return new SandBox();
}