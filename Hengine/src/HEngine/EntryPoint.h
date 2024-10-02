#pragma once

#ifdef HE_PLATFORM_WINDOWS

extern HEngine::Application* HEngine::CreateApplication();

int main()
{
	auto app = HEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif