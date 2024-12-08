#include "HEngine.h"
#include "HEngine/Core/EntryPoint.h"

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class SandBox : public HEngine::Application
{
public:
	SandBox(HEngine::ApplicationCommandLineArgs args)
		: Application("Sandbox", args)
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D);
	}
	~SandBox()
	{
	}
};
HEngine::Application* HEngine::CreateApplication(ApplicationCommandLineArgs args)
{
	return new SandBox(args);
}
