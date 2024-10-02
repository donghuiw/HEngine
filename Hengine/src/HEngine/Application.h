#pragma once

#include "Core.h"

namespace HEngine
{
	class HENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}
