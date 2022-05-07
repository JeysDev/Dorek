#include "dkpch.h"
#include "Dorek/Renderer/RenderCommand.h"

namespace Dorek {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}