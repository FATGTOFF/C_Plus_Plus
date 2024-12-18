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



#endif
