#include "HEngine.h"
#include "HEngine/Core/EntryPoint.h"

#include "EditorLayer.h"

namespace HEngine
{
	class HEngineEditor : public Application
	{
	public:
		HEngineEditor(ApplicationCommandLineArgs args)
			: Application("HEngineEditor", args)
		{
			PushLayer(new EditorLayer());
		}
		~HEngineEditor()
		{
		}
	};
	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new HEngineEditor(args);
	}
}