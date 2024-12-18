#include "CPUID_EAX_1_ECX.h"
#include "CPUID_EAX_1_EAX.h"

int main()
{

	CPUID_EAX_1_EAX cpuid_eax_1_eax{};

	cpuid_eax_1_eax.printVersionInfoInEAX();

	CPUID_EAX_1_ECX cpuid_eax_1_ecx{};

	cpuid_eax_1_ecx.printFeaturesInECX();

	std::cin.get();
}