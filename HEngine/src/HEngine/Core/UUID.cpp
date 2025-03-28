#include "hepch.h"
#include "UUID.h"

#include <random>

#include <unordered_map>

namespace HEngine
{
	static std::random_device s_RandomDevice;						// 种子生成器
	static std::mt19937_64 s_Engine(s_RandomDevice());			//生成均匀分布的伪随机数
	static std::uniform_int_distribution<uint64_t> s_UniformDistribution;	//生成指定范围内的随机整数

	static std::atomic<uint64_t> s_Counter = 1;

	UUID::UUID()
		: m_UUID(s_Counter.fetch_add(1, std::memory_order_relaxed)) // 递增
	{
	}

	UUID::UUID(uint64_t uuid)
		: m_UUID(uuid)
	{
	}

}