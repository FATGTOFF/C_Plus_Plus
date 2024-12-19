#ifndef ENUMERATORS_LIST_H
#define ENUMERATORS_LIST_H

enum class Registers : unsigned
{
    EAX, EBX, ECX, EDX
};

enum class BitLocation : unsigned
{
    BIT_0,
    BIT_1,
    BIT_2,
    BIT_3,
    BIT_4,
    BIT_5,
    BIT_6,
    BIT_7,
    BIT_8,
    BIT_9,
    BIT_10,
    BIT_11,
    BIT_12,
    BIT_13,
    BIT_14,
    BIT_15,
    BIT_16,
    BIT_17,
    BIT_18,
    BIT_19,
    BIT_20,
    BIT_21,
    BIT_22,
    BIT_23,
    BIT_24,
    BIT_25,
    BIT_26,
    BIT_27,
    BIT_28,
    BIT_29,
    BIT_30,
    BIT_31,
};

enum class CPUID_EAX_1_EAX_BITS : unsigned
{
    Stepping_ID_BIT_0,
    Stepping_ID_BIT_1,
    Stepping_ID_BIT_2,
    Stepping_ID_BIT_3,
    Model_BIT_4,
    Model_BIT_5,
    Model_BIT_6,
    Model_BIT_7,
    Family_ID_BIT_8,
    Family_ID_BIT_9,
    Family_ID_BIT_10,
    Family_ID_BIT_11,
    Processor_Type_BIT_12,
    Processor_Type_BIT_13,
    Reserved_BIT_14,
    Reserved_BIT_15,
    Extended_Model_ID_BIT_16,
    Extended_Model_ID_BIT_17,
    Extended_Model_ID_BIT_18,
    Extended_Model_ID_BIT_19,
    Extended_Model_Family_BIT_20,
    Extended_Model_Family_BIT_21,
    Extended_Model_Family_BIT_22,
    Extended_Model_Family_BIT_23,
    Extended_Model_Family_BIT_24,
    Extended_Model_Family_BIT_25,
    Extended_Model_Family_BIT_26,
    Extended_Model_Family_BIT_27,
    Reserved_BIT_28,
    Reserved_BIT_29,
    Reserved_BIT_30,
    Reserved_BIT_31,
};

enum class INITIAL_EAX_VALUE : unsigned
{
    EAX_00H = 0x00,
    EAX_01H = 0x01,
    EAX_02H = 0x02,
    EAX_03H = 0x03,
    EAX_04H = 0x04,
    EAX_05H = 0x05,
    EAX_06H = 0x06,
    EAX_07H = 0x07,
    EAX_09H = 0x09,
    EAX_0AH = 0x0A,
    EAX_0BH = 0x0B,
    EAX_0DH = 0x0D,
    EAX_0FH = 0x0F,
    EAX_10H = 0x10,
    EAX_12H = 0x12,
    EAX_14H = 0x14,
    EAX_15H = 0x15,
    EAX_16H = 0x16,
    EAX_17H = 0x17,
    EAX_18H = 0x18,
    EAX_19H = 0x19,
    EAX_1AH = 0x1A,
    EAX_1BH = 0x1B,
    EAX_1CH = 0x1C,
    EAX_1DH = 0x1D,
    EAX_1EH = 0x1E,
    EAX_20H = 0x20,
    EAX_23H = 0x23,
    EAX_24H = 0x24,

    // Extended Function CPUID Information
    EAX_80000000H = 0x80000000,
    EAX_80000001H = 0x80000001,
    EAX_80000002H = 0x80000002,
    EAX_80000003H = 0x80000003,
    EAX_80000004H = 0x80000004,
    EAX_80000005H = 0x80000005,
    EAX_80000006H = 0x80000006,
    EAX_80000007H = 0x80000007,
    EAX_80000008H = 0x80000008,

};


#endif
