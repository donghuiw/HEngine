#pragma once

#include "HEngine/Renderer/OrthographiCamera.h"
#include "HEngine/Core/Timestep.h"

#include "HEngine/Events/ApplicationEvent.h"
#include "HEngine/Events/MouseEvent.h"

namespace HEngine
{
	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void OnUpdate(Timestep ts);
		void	OnEvent(Event& e);

		OrthographiCamera& GetCamera(){ return m_Camera; }
		const OrthographiCamera& GetCamera() const { return m_Camera; }

		float GetZoomLevel() const { return m_ZoomLevel; }
		void SetZoomLevel(float level) { m_ZoomLevel = level; }
	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographiCamera m_Camera;

		bool m_Rotation;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f;
		float m_CameraTranslationSpeed = 10.0f, m_CameraRotationSpeed = 180.0f;
	};
}