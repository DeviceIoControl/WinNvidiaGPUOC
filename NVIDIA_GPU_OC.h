#pragma once

#include <Windows.h>

#define GetProcAddressEx(hModule, fnSignature) reinterpret_cast<decltype(&fnSignature)>(GetProcAddress(hModule, #fnSignature))

namespace NV_API 
{
	class GPU
	{
	public:
		static bool Initialize();

		static int Set_GPU_OVERCLOCK(bool E_Over, int OC_GPU, int OC_M, int OC_V);
		static int Set_CoreOC(int index, int offset);
		static int Set_MEMOC(int index, int offset);
		static int Get_GPU_Overclock_Range();
		static int Get_GPU_Overclock_Max();
		static int Set_GPU_Number(int number);
		static void* Read_VF_Point(const char* file_name);
		static void Set_VFOffset(int number, int vfPointIdx, int freqOffsetkHz);
		static void Reset();
		
		static bool Uninitialize();

	private:
		inline static HMODULE s_hModule = NULL;

		static int InitGPU_API()
		{
			static const auto pfn = GetProcAddressEx(s_hModule, InitGPU_API);
			return pfn();
		}
		
		static void CloseGPU_API() 
		{
			static const auto pfn = GetProcAddressEx(s_hModule, CloseGPU_API);
			return pfn();
		}
	};

} // namespace NV_API