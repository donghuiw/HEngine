#pragma once

#include "HEngine/Renderer/OrthographiCamera.h"
#include "HEngine/Renderer/Texture.h"

namespace HEngine
{
	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographiCamera& camera);
		static void EndScene();
		
		//Primitives
		static void DrawQuad(const glm::vec2& position, const glm::vec2 size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2 size, const glm::vec4& color);
		static void DrawQuad(const glm::vec2& position, const glm::vec2 size, const Ref<Texture2D>& texture);
		static void DrawQuad(const glm::vec3& position, const glm::vec2 size, const Ref<Texture2D>& texture);
	};
}
