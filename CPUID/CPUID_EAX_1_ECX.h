#ifndef CPUID_EAX_1_ECX_H
#define CPUID_EAX_1_ECX_H

#include "Enumerators_List.h"
#include <array>
#include <bitset>
#include <intrin.h>
#include <iostream>
#include <vector>

class CPUID_EAX_1_ECX
{
private:

    std::array<int, 4> cpui{};
	std::vector <std::array<int, 4>> data{};
	std::vector <std::array<int, 4>> extData{};
	int numOfIDs{};
	int numOFExIDs{};
	std::bitset<32> cpuid_EAX_1_ECX{};

    bool SSE3() const;
    bool PCLMULQDQ() const;
    bool DTES64() const;
    bool MONITOR() const;
    bool DS_CPL() const;
    bool VMX() const;
    bool SMX() const;
    bool EIST() const;
    bool TM2() const;
    bool SSSE3() const;
    bool CNXT_ID() const;
    bool SDBG() const;
    bool FMA() const;
    bool CMPXCHG16B() const;
    bool xTPR() const;
    bool PDCM() const;
    bool RESERVED_ECX_16() const;
    bool PCID() const;
    bool DCA() const;
    bool SSE41() const;
    bool SSE42() const;
    bool x2APIC() const;
    bool MOVBE() const;
    bool POPCNT() const;
    bool TSC_DEADLINE() const;
    bool AES() const;
    bool XSAVE() const;
    bool OSXSAVE() const;
    bool AVX() const;
    bool F16C() const;
    bool RDRAND() const;
    bool SPARE_BIT() const;

public:
	CPUID_EAX_1_ECX();

    void printFeaturesInECX() const;

};







































#endif
