#include <Dorek.h>
#include <Dorek/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Dorek {

	class DorekEngine : public Application
	{
	public:
		DorekEngine(ApplicationCommandLineArgs args)
			: Application("DorekEngine", args)
		{
			PushLayer(new EditorLayer());
		}

		~DorekEngine()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new DorekEngine(args);
	}

}
