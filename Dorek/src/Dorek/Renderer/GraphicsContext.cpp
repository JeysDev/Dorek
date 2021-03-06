#include "dkpch.h"
#include "Dorek/Renderer/GraphicsContext.h"

#include "Dorek/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Dorek {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    DK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		DK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}