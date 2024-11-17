#include "HEngine.h"
#include "HEngine/Core/EntryPoint.h"

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class SandBox : public HEngine::Application
{
public:
	SandBox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D);
	}
	~SandBox()
	{
	}
};
HEngine::Application* HEngine::CreateApplication()
{
	return new SandBox();
}