#include "CPUID_EAX_1_ECX.h"

int main()
{
	CPUID_EAX_1_ECX cpuid_eax_1_ecx{};

	cpuid_eax_1_ecx.printFeaturesInECX();

	std::cin.get();
}