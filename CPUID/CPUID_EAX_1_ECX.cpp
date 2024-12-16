#include "CPUID_EAX_1_ECX.h"

CPUID_EAX_1_ECX::CPUID_EAX_1_ECX()
{

    // Calling __cpuid with 0x0 as the function_id argument
    // gets the number of the highest valid function ID.
    __cpuid(cpui.data(), 0);
    numOfIDs = cpui[static_cast<unsigned>(Registers::EAX)];

    for (int i = 0; i <= numOfIDs; ++i)
    {
        __cpuidex(cpui.data(), i, 0);
        data.push_back(cpui);
    }

    // load bitset with flags for function 0x00000001
    if (numOfIDs >= 1)
    {
        cpuid_EAX_1_ECX = data[1][static_cast<unsigned>(Registers::ECX)];
    }
}

void CPUID_EAX_1_ECX::printFeaturesInECX() const
{
    const auto support_message = [](bool is_supported)
        {
            int supportStatus{};
            (is_supported ? supportStatus = 1 : supportStatus = 0);

            return supportStatus;
        };

    std::cout << "\n                                               Feature Information Returned in the ECX Register\n";
    std::cout << "                                31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0 \n";
    std::cout << "                               -------------------------------------------------------------------------------------------------\n";
    std::cout << "                               |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "                               |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    printf("                               | %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d| %d|\n",
        support_message(SPARE_BIT()), support_message(RDRAND()),      support_message(F16C()),  support_message(AVX()),            support_message(OSXSAVE()),support_message(XSAVE()),
        support_message(AES()),       support_message(TSC_DEADLINE()),support_message(POPCNT()),support_message(MOVBE()),          support_message(x2APIC()), support_message(SSE42()),
        support_message(SSE41()),     support_message(DCA()),         support_message(PCID()),  support_message(RESERVED_ECX_16()),support_message(PDCM()),   support_message(xTPR()),
        support_message(CMPXCHG16B()),support_message(FMA()),         support_message(SDBG()),  support_message(CNXT_ID()),        support_message(SSSE3()),  support_message(TM2()),
        support_message(EIST()),      support_message(SMX()),         support_message(VMX()),   support_message(DS_CPL()),         support_message(MONITOR()),support_message(DTES64()),
        support_message(PCLMULQDQ()), support_message(SSE3()));
    std::cout << "                               |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "                               |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "                               -------------------------------------------------------------------------------------------------\n";
    std::cout << "Not Used - Always returns 0 -----|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "RDRAND -----------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "F16C ----------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "AVX --------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "OSXSAVE -------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "XSAVE ------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "AES -----------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "TSC-Deadline -----------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "POPCNT --------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "MOVBE ------------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "x2APIC --------------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "SSE4_2 - SSE4.2 --------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "SSE4_1 - SSE4.1 -----------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "DCA - Direct Cache Access ----------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "PCID - Process-context Identifiers ----------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "Reserved ---------------------------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "PDCM - Perf/Debug Capability MSR ------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "xTPR Update Control ----------------------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "CMPXCHG16B ----------------------------------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "FMA - Fused Multiply Add -----------------------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "SDBG ----------------------------------------------------------------------------------------|  |  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "CNXT-ID - L1 Context ID ------------------------------------------------------------------------|  |  |  |  |  |  |  |  |  |  |\n";
    std::cout << "SSSE3 - SSSE3 Extensions --------------------------------------------------------------------------|  |  |  |  |  |  |  |  |  |\n";
    std::cout << "TM2 - Thermal Monitor 2 ------------------------------------------------------------------------------|  |  |  |  |  |  |  |  |\n";
    std::cout << "EIST - Enhanced Intel SpeedStep Technology --------------------------------------------------------------|  |  |  |  |  |  |  |\n";
    std::cout << "SMX - Safer Mode Extensions --------------------------------------------------------------------------------|  |  |  |  |  |  |\n";
    std::cout << "VMX - Virtual Machine Extensions ------------------------------------------------------------------------------|  |  |  |  |  |\n";
    std::cout << "DS-CPL - CPL Qualified Debug Store -------------------------------------------------------------------------------|  |  |  |  |\n";
    std::cout << "MONITOR - MONITOR/MWAIT ---------------------------------------------------------------------------------------------|  |  |  |\n";
    std::cout << "DTES64 - 64-bit DS Area ------------------------------------------------------------------------------------------------|  |  |\n";
    std::cout << "PCLMULQDQ - Carryless Multiplication --------------------------------------------------------------------------------------|  |\n";
    std::cout << "SSE3 - SSE3 Extensions -------------------------------------------------------------------------------------------------------|\n";
}

bool CPUID_EAX_1_ECX::SSE3() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_0));
}

bool CPUID_EAX_1_ECX::PCLMULQDQ() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_1));
}

bool CPUID_EAX_1_ECX::DTES64() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_2));
}

bool CPUID_EAX_1_ECX::MONITOR() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_3));
}

bool CPUID_EAX_1_ECX::DS_CPL() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_4));
}

bool CPUID_EAX_1_ECX::VMX() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_5));
}

bool CPUID_EAX_1_ECX::SMX() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_6));
}

bool CPUID_EAX_1_ECX::EIST() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_7));
}

bool CPUID_EAX_1_ECX::TM2() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_8));
}

bool CPUID_EAX_1_ECX::SSSE3() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_9));
}

bool CPUID_EAX_1_ECX::CNXT_ID() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_10));
}

bool CPUID_EAX_1_ECX::SDBG() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_11));
}

bool CPUID_EAX_1_ECX::FMA() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_12));
}

bool CPUID_EAX_1_ECX::CMPXCHG16B() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_13));
}

bool CPUID_EAX_1_ECX::xTPR() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_14));
}

bool CPUID_EAX_1_ECX::PDCM() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_15));
}

bool CPUID_EAX_1_ECX::RESERVED_ECX_16() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_16));
}

bool CPUID_EAX_1_ECX::PCID() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_17));
}

 bool CPUID_EAX_1_ECX::DCA() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_18));
}

bool CPUID_EAX_1_ECX::SSE41() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_19));
}

bool CPUID_EAX_1_ECX::SSE42() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_20));
}

bool CPUID_EAX_1_ECX::x2APIC() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_21));
}

bool CPUID_EAX_1_ECX::MOVBE() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_22));
}

bool CPUID_EAX_1_ECX::POPCNT() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_23));
}

bool CPUID_EAX_1_ECX::TSC_DEADLINE() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_24));
}

bool CPUID_EAX_1_ECX::AES() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_25));
}

bool CPUID_EAX_1_ECX::XSAVE() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_26));
}

bool CPUID_EAX_1_ECX::OSXSAVE() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_27));
}

bool CPUID_EAX_1_ECX::AVX() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_28));
}

bool CPUID_EAX_1_ECX::F16C() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_29));
}

bool CPUID_EAX_1_ECX::RDRAND() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_30));
}

bool CPUID_EAX_1_ECX::SPARE_BIT() const
{
    return cpuid_EAX_1_ECX.test(static_cast<unsigned>(BitLocation::BIT_31));
}
