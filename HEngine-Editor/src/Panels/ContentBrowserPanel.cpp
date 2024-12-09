#include "hepch.h"
#include "ContentBrowserPanel.h"

#include <imgui/imgui.h>

namespace HEngine
{
	//Once we have projects, change this
	static const std::filesystem::path s_AssetPath = "assets";//��ʾ�ļ�ϵͳ�е�·��

	ContentBrowserPanel::ContentBrowserPanel()
		:m_CurrentDirectory(s_AssetPath)
	{
	}

	void ContentBrowserPanel::OnImGuiRender()
	{
		ImGui::Begin("Content Browser");

		if (m_CurrentDirectory != std::filesystem::path(s_AssetPath))
		{
			if (ImGui::Button("<-"))
			{
				m_CurrentDirectory = m_CurrentDirectory.parent_path();
			}
		}
		for (auto& directorEntry : std::filesystem::directory_iterator(m_CurrentDirectory))//���ڵ����ļ�ϵͳ�е�Ŀ¼
		{
			const auto& path = directorEntry.path();
			auto relativePath = std::filesystem::relative(path, s_AssetPath);
			std::string filenameString = relativePath.filename().string();
			if (directorEntry.is_directory())
			{
				if (ImGui::Button(filenameString.c_str()))
				{
					m_CurrentDirectory /= path.filename();
				}
			}
			else
			{
				if(ImGui::Button(filenameString.c_str()))
				{ }
			}
		}
		ImGui::End();
	}
}