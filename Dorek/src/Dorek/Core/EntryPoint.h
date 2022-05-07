#pragma once
#include "Dorek/Core/Base.h"
#include "Dorek/Core/Application.h"

#ifdef DK_PLATFORM_WINDOWS

extern Dorek::Application* Dorek::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Dorek::Log::Init();

	DK_PROFILE_BEGIN_SESSION("Startup", "DorekProfile-Startup.json");
	auto app = Dorek::CreateApplication({ argc, argv });
	DK_PROFILE_END_SESSION();

	DK_PROFILE_BEGIN_SESSION("Runtime", "DorekProfile-Runtime.json");
	app->Run();
	DK_PROFILE_END_SESSION();

	DK_PROFILE_BEGIN_SESSION("Shutdown", "DorekProfile-Shutdown.json");
	delete app;
	DK_PROFILE_END_SESSION();
}

#endif
