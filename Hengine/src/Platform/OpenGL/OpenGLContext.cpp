#include "hepch.h"

#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace HEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HE_CORE_ASSERT(windowHandle, "Window handle is numm!")
	}

	void OpenGLContext::Init()
	{
		HE_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HE_CORE_ASSERT(status, "Failed to initialize Glad!");

		HE_CORE_INFO("OpenGL Info:");

		HE_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		HE_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		HE_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

		#ifdef HE_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			HE_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "HEngine requires at least OpenGL version 4.5!");
		#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		HE_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}
