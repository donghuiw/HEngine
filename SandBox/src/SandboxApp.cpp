#include "HEngine.h"

class SandBox : public HEngine::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};
HEngine::Application* HEngine::CreateApplication()
{
	return new SandBox();
}