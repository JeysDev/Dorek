#include <Dorek.h>
#include <Dorek/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Dorek::Application
{
public:
	Sandbox(Dorek::ApplicationCommandLineArgs args)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Dorek::Application* Dorek::CreateApplication(Dorek::ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}
