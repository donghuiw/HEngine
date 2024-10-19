#include "hepch.h"
#include "VertxArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertxArray.h"

namespace HEngine
{
	VertexArray* VertexArray::Create()
	{	
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:  HE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLVertexArray();	
		}
		HE_CORE_ASSERT(false, "Unknow RendererAPI!");
		return nullptr;
	}
}