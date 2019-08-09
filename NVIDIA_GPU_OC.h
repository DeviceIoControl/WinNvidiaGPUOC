#pragma once
#include <Windows.h>

namespace NV_API 
{
	class OC_API 
	{
	public:
		explicit OC_API();

		int Set_GPU_OVERCLOCK(bool E_Over, int OC_GPU, int OC_M, int OC_V);
		int Set_CoreOC(int index, int offset);
		int Set_MEMOC(int index, int offset);
		int Get_GPU_Overclock_range();
		int Get_GPU_Overclock_Max();
		int Set_GPU_Number(int number);
		void* Read_VF_Point(const char* file_name);
		void Set_VFOffset(int number, int vfPointIdx, int freqOffsetkHz);
		void reset();
		~OC_API();

	private:
		int m_InitGPU_API();
		void m_CloseGPU_API();
		HMODULE m_hModule;
		FARPROC fnPtrArray[10];
	};


}