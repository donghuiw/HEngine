#pragma once

#include <filesystem>

#include "HEngine/Core/Base.h"
#include "HEngine/Renderer/Texture.h"

namespace HEngine
{
	struct MSDFData;
	
	class Font
	{
	public:
		Font(const std::filesystem::path& font);
		~Font();

		Ref<Texture2D> GetAtlasTexture() const { return m_AtlasTexture; }
	private:
		MSDFData* m_Data;
		Ref<Texture2D> m_AtlasTexture;
	};
}