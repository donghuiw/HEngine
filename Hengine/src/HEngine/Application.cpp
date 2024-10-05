#include "hepch.h"

#include "Application.h"
#include "Log.h"


namespace HEngine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}
	void Application::Run()
	{

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HE_TRACE(e.ToString());
		}

	}
}
