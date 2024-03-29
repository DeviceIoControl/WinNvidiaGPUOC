// NVIDIA_GPU_OC.cpp : Defines the entry point for the console application.
// Created by Josh Stephenson 

#include "stdafx.h"
#include "NVIDIA_GPU_OC.h"
#include <iostream>

namespace NV_API 
{
	bool GPU::Initialize()
	{
		GPU::s_hModule = LoadLibraryA("NVGPU_DLL.dll");

		if (GPU::s_hModule == nullptr) 
		{
			std::cout << "Error loading: 'NVGPU_DLL.dll'...\n";
			return false;
		}

		return GPU::InitGPU_API();
	}

	int GPU::Set_GPU_OVERCLOCK(bool E_Over, int OC_GPU, int OC_M, int OC_V) 
	{
		static const auto pfn = GetProcAddressEx(s_hModule, Set_GPU_OVERCLOCK);
		return pfn(E_Over, OC_GPU, OC_M, OC_V);
	}

	int GPU::Set_CoreOC(int index, int offset) 
	{
		static const auto pfn = GetProcAddressEx(s_hModule, Set_CoreOC);
		return pfn(index, offset);
	}

	int GPU::Set_MEMOC(int index, int offset) 
	{
		static const auto pfn = GetProcAddressEx(s_hModule, Set_MEMOC);
		return pfn(index, offset);
	}

	int GPU::Get_GPU_Overclock_Range() 
	{
		static const auto pfn = GetProcAddressEx(s_hModule, Get_GPU_Overclock_Range);
		return pfn();
	}

	int GPU::Get_GPU_Overclock_Max() 
	{
		static const auto pfn = GetProcAddressEx(s_hModule, Get_GPU_Overclock_Max);
		return pfn();
	}

	int GPU::Set_GPU_Number(int number) 
	{
		static const auto pfn = GetProcAddressEx(s_hModule, Set_GPU_Number);
		return pfn(number);
	}

	void* GPU::Read_VF_Point(const char* file_name) 
	{
		static const auto pfn = GetProcAddressEx(s_hModule, Read_VF_Point);
		return pfn(file_name);
	}

	void GPU::Set_VFOffset(int number, int vfPointIdx, int freqOffsetkHz) 
	{
		static const auto pfn = GetProcAddressEx(s_hModule, Set_VFOffset);
		return pfn(number, vfPointIdx, freqOffsetkHz);
	}

	void GPU::Reset(int index)
	{
		Set_CoreOC(index, 0);
		Set_MEMOC(index, 0);
	}

	bool GPU::Uninitialize()
	{
		GPU::CloseGPU_API();
		FreeLibrary(GPU::s_hModule); 
	}
}

using namespace NV_API;

int main()
{
	std::cout << "Overclocking your system...\n";

	GPU::Initialize();

	// Overclock the 1st NVIDIA GPU with the following settings.

	GPU::Set_CoreOC(0, 150); // Core overclock (MHz)
	GPU::Set_MEMOC(0, 175); // Memory overclock (MHz)

	GPU::Uninitialize();

    return 0;
}

