#include "dkpch.h"
#include "Dorek/Renderer/Framebuffer.h"

#include "Dorek/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Dorek {
	
	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    DK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
		}

		DK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}

