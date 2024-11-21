#include "HEngine.h"
#include "HEngine/Core/EntryPoint.h"

#include "EditorLayer.h"

namespace HEngine
{
	class HEngineEditor : public Application
	{
	public:
		HEngineEditor()
			: Application("HEngine Editor")
		{
			PushLayer(new EditorLayer());
		}
		~HEngineEditor()
		{
		}
	};
	Application* CreateApplication()
	{
		return new HEngineEditor();
	}
}