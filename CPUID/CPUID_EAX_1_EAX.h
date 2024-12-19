#ifndef CPUID_EAX_1_EAX_H
#define CPUID_EAX_1_EAX_H

#include "Enumerators_List.h"
#include <array>
#include <bitset>
#include <intrin.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>


class CPUID_EAX_1_EAX
{
private:

    mutable std::ostringstream vendorBrandIDInHex{};
    std::vector <std::array<int, 4>> data{};
    std::vector <std::array<int, 4>> extData{};
    std::array<int, 4> cpui{};
    int numOfIDs{};
    int numOFExIDs{};
    std::bitset<32> cpuid_EAX_1_EAX{};

    constexpr int Get_Family_ID(const unsigned long) const;
    constexpr int Get_Model_ID(const unsigned long) const;
    void Get_Vendor_ID(const unsigned long, const unsigned long, const unsigned long) const;
    void Get_Brand_ID(const std::vector <std::array<int, 4>> &extData) const;
    void Display_Family(const int) const;
    void Display_Model(const int) const;
    void DisplayFamily_DisplayModel(const int, const int) const;
    std::string hexToAscii(const std::string&) const;
    constexpr unsigned long byteSwap(unsigned long) const;
    void Display_Vendor_ID() const;
    void Display_Brand_ID() const;

public:
    CPUID_EAX_1_EAX();

    void printVersionInfoInEAX() const;

};
#endif