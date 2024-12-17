#pragma once

#include <entt.hpp>
#include <box2d/id.h>

namespace HEngine
{
	class Scene;
	class Timestep;
	struct Rigidbody2DComponent;
	struct BoxCollider2DComponent;

	class PhysicsManager
	{
	public:
		void CreateWorld();
		void DestoryWorld();
		void AddRigibody(Scene* scene, entt::entity e);
		void AttachBoxCollider(Scene* scene, entt::entity e);
		void AttachCircleCollider(Scene* scene, entt::entity e);
		void DestoryBoxCollider(Scene* scene, entt::entity e);
		void DestoryCircleCollider(Scene* scene, entt::entity e);
		void FixedUpdate(Timestep ts);
		void UpdateRigidbody(Scene* scnen, entt::entity e);

	public:
		static PhysicsManager& Get() { return m_instance; }

	private:
		b2WorldId m_WorldId = b2_nullWorldId;

		static PhysicsManager m_instance;
	};
}