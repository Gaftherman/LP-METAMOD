#pragma once

#include <functional>
#include <thread>
#include <chrono>

class Scheduler
{
public:
	static void DelayWithCallback(long long nanoseconds, CASFunction* pFunction)
	{
		std::function<void()> callback = [=]()
		{
			if (ASEXT_CallCASBaseCallable && (*ASEXT_CallCASBaseCallable))
			{
				(*ASEXT_CallCASBaseCallable)(pFunction, 0);
			}
		};

		std::thread([=]()
		{
			std::this_thread::sleep_for(std::chrono::nanoseconds(nanoseconds));
			callback();
		}).detach();
	}

	static void SetScheduler(double delay_time, aslScriptFunction* aslfn)
	{
		long long nanosegundos = static_cast<long long>(delay_time * 1000000000 + ((10 ^ 9) * 2));
		auto callback = ASEXT_CreateCASFunction(aslfn, ASEXT_GetServerManager()->curModule, 1);

		if(callback)
			DelayWithCallback(nanosegundos, callback);
	}
};