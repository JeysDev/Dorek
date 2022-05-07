#include "dkpch.h"
#include "Dorek/Renderer/VertexArray.h"

#include "Dorek/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Dorek {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    DK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		DK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}