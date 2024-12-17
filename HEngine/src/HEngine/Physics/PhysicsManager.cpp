#include "hepch.h"
#include "PhysicsManager.h"

#include <box2d/box2d.h>
#include <box2d/collision.h>
#include <box2d/math_functions.h>

#include "HEngine/Scene/ScriptableEntity.h"
#include "HEngine/Scene/Components.h"

namespace HEngine
{
	PhysicsManager PhysicsManager::m_instance;

	static b2BodyType GetBox2DBodyType(Rigidbody2DComponent::BodyType bodyType)
	{
		switch (bodyType)
		{
			case HEngine::Rigidbody2DComponent::BodyType::Static:				return b2_staticBody;
			case HEngine::Rigidbody2DComponent::BodyType::Dynamic:		return b2_dynamicBody;
			case HEngine::Rigidbody2DComponent::BodyType::Kinematic:		return b2_kinematicBody;
		}
		HE_CORE_ASSERT(false, "Unknown body type");
		return b2_staticBody;
	}

	void PhysicsManager::CreateWorld()
	{
		b2WorldDef worldDef = b2DefaultWorldDef();
		worldDef.gravity = { 0.0f, -9.8f };
		worldDef.restitutionThreshold = 0.5f;
		m_WorldId = b2CreateWorld(&worldDef);
		HE_CORE_ASSERT(b2World_IsValid(m_WorldId),"World id validation failed. ");
	}

	void PhysicsManager::DestoryWorld()
	{
		b2DestroyWorld(m_WorldId);
		m_WorldId = b2_nullWorldId;
	}

	void PhysicsManager::AddRigibody(Scene* scene, entt::entity e)
	{
		Entity entity = { e, scene };
		auto& transform = entity.GetComponent<TransformComponent>();
		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();

		b2BodyDef bodyDef = b2DefaultBodyDef();
		bodyDef.type = GetBox2DBodyType(rb2d.Type);
		bodyDef.position = { transform.Translation.x, transform.Translation.y };
		bodyDef.rotation = b2MakeRot(transform.Rotation.z);

		b2BodyId bodyId = b2CreateBody(m_WorldId, &bodyDef);
		b2Body_SetFixedRotation(bodyId, rb2d.FixedRotation);
		rb2d.RuntimeBodyId = bodyId;

		HE_CORE_ASSERT(b2Body_IsValid(rb2d.RuntimeBodyId), "Body id validation failed.");

		AttachBoxCollider(scene, e);
		AttachCircleCollider(scene, e);
	}

	void PhysicsManager::AttachBoxCollider(Scene* scene, entt::entity e)
	{
		Entity entity = { e, scene };
		auto& transform = entity.GetComponent<TransformComponent>();
		auto& bc2d = entity.GetComponent<BoxCollider2DComponent>();
		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();

		if (!b2Body_IsValid(rb2d.RuntimeBodyId)) return;

		b2Polygon boxShape = b2MakeBox(bc2d.Size.x * transform.Scale.x, bc2d.Size.y * transform.Scale.y);

		b2ShapeDef shapeDef = b2DefaultShapeDef();
		shapeDef.friction = bc2d.Friction;
		shapeDef.density = bc2d.Density;
		shapeDef.restitution = bc2d.Restitution;

		b2ShapeId shapeID = b2CreatePolygonShape(rb2d.RuntimeBodyId, &shapeDef, &boxShape);
		bc2d.RuntimeShapeId = shapeID;

		HE_CORE_ASSERT(b2Shape_IsValid(bc2d.RuntimeShapeId), "Box Shape id validation failed.");
	}

	void PhysicsManager::AttachCircleCollider(Scene* scene, entt::entity e)
	{
		Entity entity = { e, scene };
		auto& transform = entity.GetComponent<TransformComponent>();
		auto& cc2d = entity.GetComponent<CircleCollider2DComponent>();
		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();

		if (!b2Body_IsValid(rb2d.RuntimeBodyId)) return;

		b2Circle circleShape;
		circleShape.center = { cc2d.Offset.x, cc2d.Offset.y };
		circleShape.radius = cc2d.Radius;

		b2ShapeDef shapeDef = b2DefaultShapeDef();
		shapeDef.friction = cc2d.Friction;
		shapeDef.density = cc2d.Density;
		shapeDef.restitution = cc2d.Restitution;

		b2ShapeId shapeID = b2CreateCircleShape(rb2d.RuntimeBodyId, &shapeDef, &circleShape);
		cc2d.RuntimeShapeId = shapeID;

		HE_CORE_ASSERT(b2Shape_IsValid(cc2d.RuntimeShapeId), "Circle Shape id validation failed.");
	}

	void PhysicsManager::DestoryBoxCollider(Scene* scene, entt::entity e)
	{
		Entity entity = { e, scene };
		auto& bc2d = entity.GetComponent<BoxCollider2DComponent>();
		if (!b2Shape_IsValid(bc2d.RuntimeShapeId)) return;
		
		b2DestroyShape(bc2d.RuntimeShapeId,false);
		bc2d.RuntimeShapeId = b2_nullShapeId;
	}

	void PhysicsManager::DestoryCircleCollider(Scene* scene, entt::entity e)
	{
		Entity entity = { e, scene };
		auto& cc2d = entity.GetComponent<CircleCollider2DComponent>();
		if (!b2Shape_IsValid(cc2d.RuntimeShapeId)) return;

		b2DestroyShape(cc2d.RuntimeShapeId, false);
		cc2d.RuntimeShapeId = b2_nullShapeId;
	}

	void PhysicsManager::FixedUpdate(Timestep ts)
	{
		const int32_t subStepCount = 4;
		b2World_Step(m_WorldId, ts, subStepCount);
	}

	void PhysicsManager::UpdateRigidbody(Scene* scnen, entt::entity e)
	{
		Entity entity = { e, scnen };
		auto& transform = entity.GetComponent<TransformComponent>();
		auto& rb2d = entity.GetComponent<Rigidbody2DComponent>();
		// Retrieve transform from Box2D
		
		b2Vec2 position = b2Body_GetPosition(rb2d.RuntimeBodyId);
		b2Rot rotation = b2Body_GetRotation(rb2d.RuntimeBodyId);
		float radiansAngle = atan2(rotation.s, rotation.c);

		transform.Translation.x = position.x;
		transform.Translation.y = position.y;
		transform.Rotation.z = radiansAngle;
	}

}