#include "hepch.h"
#include "UUID.h"

#include <random>

#include <unordered_map>

namespace HEngine
{
	static std::random_device s_RandomDevice;						// ����������
	static std::mt19937_64 s_Engine(s_RandomDevice());			//���ɾ��ȷֲ���α�����
	static std::uniform_int_distribution<uint64_t> s_UniformDistribution;	//����ָ����Χ�ڵ��������

	static std::atomic<uint64_t> s_Counter = 1;

	UUID::UUID()
		: m_UUID(s_Counter.fetch_add(1, std::memory_order_relaxed)) // ����
	{
	}

	UUID::UUID(uint64_t uuid)
		: m_UUID(uuid)
	{
	}

}