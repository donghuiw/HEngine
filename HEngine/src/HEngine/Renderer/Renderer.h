#pragma once

#include "RenderCommand.h"
#include "OrthographiCamera.h"
#include "Shader.h"

namespace HEngine
{
	class Renderer
	{
	public:
		static void BeginScene(OrthographiCamera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI();  }
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};
		static SceneData* m_SceneData;
	};
}

