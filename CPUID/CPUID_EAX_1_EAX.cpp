#include "CPUID_EAX_1_EAX.h"

CPUID_EAX_1_EAX::CPUID_EAX_1_EAX()
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

    // Get the vendor string ID
    Get_Vendor_ID(data[0][static_cast<unsigned>(Registers::EBX)],
                  data[0][static_cast<unsigned>(Registers::EDX)],
                  data[0][static_cast<unsigned>(Registers::ECX)]);
    Display_Vendor_ID();

    // load bitset with flags for function 0x00000001
    if (numOfIDs >= 1)
    {
        cpuid_EAX_1_EAX = data[1][static_cast<unsigned>(Registers::EAX)];
    }

    DisplayFamily_DisplayModel(Get_Family_ID(cpuid_EAX_1_EAX.to_ulong()),
                               Get_Model_ID(cpuid_EAX_1_EAX.to_ulong()));
}

void CPUID_EAX_1_EAX::printVersionInfoInEAX() const
{
    const auto support_message = [](bool is_supported)
        {
            int supportStatus{};
            (is_supported ? supportStatus = 1 : supportStatus = 0);

            return supportStatus;
        };

    std::cout << "\n                                                Version Information Returned by CPUID in EAX Register\n";
    std::cout << "                                31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0 \n";
    std::cout << "                               -------------------------------------------------------------------------------------------------\n";
    std::cout << "                               |           |                       |           |     |     |           |           |           |\n";
    std::cout << "                               |           |        Extended       | Extended  |     |     |  Family   |           | Stepping  |\n";
    std::cout << "                               |           |        Family ID      | Model ID  |     |     |    ID     |   Model   |    ID     |\n";
    std::cout << "                               |           |                       |           |     |     |           |           |           |\n";
    printf("                               | %d  %d  %d  %d| %d  %d  %d  %d  %d  %d  %d  %d| %d  %d  %d  %d| %d  %d| %d  %d| %d  %d  %d  %d| %d  %d  %d  %d| %d  %d  %d  %d|\n",
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Reserved_BIT_31))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Reserved_BIT_30))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Reserved_BIT_29))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Reserved_BIT_28))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_Family_BIT_27))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_Family_BIT_26))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_Family_BIT_25))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_Family_BIT_24))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_Family_BIT_23))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_Family_BIT_22))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_Family_BIT_21))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_Family_BIT_20))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_ID_BIT_19))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_ID_BIT_18))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_ID_BIT_17))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Extended_Model_ID_BIT_16))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Reserved_BIT_15))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Reserved_BIT_14))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Processor_Type_BIT_13))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Processor_Type_BIT_12))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Family_ID_BIT_11))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Family_ID_BIT_10))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Family_ID_BIT_9))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Family_ID_BIT_8))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Model_BIT_7))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Model_BIT_6))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Model_BIT_5))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Model_BIT_4))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Stepping_ID_BIT_3))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Stepping_ID_BIT_2))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Stepping_ID_BIT_1))),
        support_message(cpuid_EAX_1_EAX.test(static_cast<unsigned>(CPUID_EAX_1_EAX_BITS::Stepping_ID_BIT_0))));
    std::cout << "                               -------------------------------------------------------------------------------------------------\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << "                                     |                 |                 |        |     |        |           |\n";
    std::cout << " Reserved ---------------------------|                 |                 |        |     |        |           |\n";
    std::cout << " Extended Family ID (0) -------------------------------|                 |        |     |        |           |\n";
    std::cout << " Extended Model ID (0) --------------------------------------------------|        |     |        |           |\n";
    std::cout << " Reserved ------------------------------------------------------------------------|     |        |           |\n";
    std::cout << " Processor Type ------------------------------------------------------------------------|        |           |\n";
    std::cout << " Family (0FH for the Pentium 4 Processor Family -------------------------------------------------|           |\n";
    std::cout << " Model ------------------------------------------------------------------------------------------------------|\n";
}

constexpr int CPUID_EAX_1_EAX::Get_Family_ID(const unsigned long verInfoByCPUIDinEAX) const
{
    // Get the family ID first (EAX:[11-8])
    int startingPos{ 8 }; // Starting position that starts with 0.
    int numOfBitsToExtract{ 4 };
    // Create a mask to set the bits (EAX:[11-8]).
    auto mask = ((1 << numOfBitsToExtract) - 1) << startingPos;

    auto familyID = (verInfoByCPUIDinEAX & mask) >> startingPos;

    // Now, let's get the extended family ID (EAX:[27-20])
    startingPos = 20;
    numOfBitsToExtract = 8;
    // Create a mask to set the bits (EAX:[27-20]).
    mask = ((1 << numOfBitsToExtract) - 1) << startingPos;

    auto extendedFamilyID = (verInfoByCPUIDinEAX & mask) >> startingPos;

    if (0xF != familyID)
    {
        return familyID;
    }
    else
    {
        return extendedFamilyID + familyID;
    }
}

constexpr int CPUID_EAX_1_EAX::Get_Model_ID(const unsigned long verInfoByCPUIDinEAX) const
{
    // Get the model ID first (EAX:[7-4])
    const auto familyID = Get_Family_ID(verInfoByCPUIDinEAX);

    int startingPos{ 4 };
    constexpr int numOfBitsToExtract{ 4 };
    // Create a mask to set the bits (EAX:[7-4])
    auto mask = ((1 << numOfBitsToExtract) - 1) << startingPos;

    auto modelID = (verInfoByCPUIDinEAX & mask) >> startingPos;

    // Now, let's get the extended model ID (EAX:[19-16])
    startingPos = 16;
    // Create a mask to set the bits (EAX:[19-16])
    mask = ((11 << numOfBitsToExtract) - 1) << startingPos;
    auto extendedModelID = (verInfoByCPUIDinEAX & mask) >> startingPos;

    if (0x6 == familyID || 0xF == familyID)
    {
        return (extendedModelID << 4) + modelID;
    }
    else
    {
        return modelID;
    }

}

void CPUID_EAX_1_EAX::Get_Vendor_ID(const unsigned long ebx, const unsigned long ecx, const unsigned long edx) const
{
    vendorIDInHex << std::hex << byteSwap(ebx) << byteSwap(ecx) << byteSwap(edx);
}

void CPUID_EAX_1_EAX::Display_Family(const int family_ID) const
{
    std::cout << "Family ID: " << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << family_ID << std::endl;
}

void CPUID_EAX_1_EAX::Display_Model(const int model_ID) const
{
    std::cout << "Model ID: " << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << model_ID << std::endl;
}

void CPUID_EAX_1_EAX::DisplayFamily_DisplayModel(const int family_ID, const int model_ID) const
{
    std::cout << std::hex << std::uppercase;
    std::cout << "DisplayFamily_DisplayModel: " << std::setfill('0') << std::setw(2) 
        << family_ID << "_" << model_ID << "H" << std::endl;
}

std::string CPUID_EAX_1_EAX::hexToAscii(const std::string& hex) const
{
    std::string ascii{};

    for (auto byteCounter = 0; byteCounter < hex.size(); byteCounter += 2)
    {
        const auto byte{ hex.substr(byteCounter, 2) };
        const auto chr{ static_cast<char>(strtol(byte.c_str(), nullptr, 16)) };
        ascii += chr;
    }

    return ascii;
}

constexpr unsigned long CPUID_EAX_1_EAX::byteSwap(unsigned long num) const
{
    return ((num & 0xFF000000) >> 24) |
           ((num & 0x00FF0000) >> 8)  |
           ((num & 0x0000FF00) << 8)  |
           ((num & 0x000000FF) << 24);
}

void CPUID_EAX_1_EAX::Display_Vendor_ID() const
{
    // Convert the hex to string.
    std::string vendorID{ hexToAscii(vendorIDInHex.str()) };

    std::cout << "Vendor ID: " << vendorID << std::endl;
}

