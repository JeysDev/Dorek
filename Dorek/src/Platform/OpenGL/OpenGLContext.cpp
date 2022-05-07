#include "dkpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Dorek {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		DK_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		DK_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		DK_CORE_ASSERT(status, "Failed to initialize Glad!");

		DK_CORE_INFO("OpenGL Info:");
		DK_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		DK_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		DK_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		DK_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Dorek requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		DK_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
