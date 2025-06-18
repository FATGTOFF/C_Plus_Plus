#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char  uchar;
typedef uchar uint_8;
typedef          short int_16;
typedef unsigned short uint_16;
typedef unsigned int uint_32;

#define CRC16_SEED_VALUE        (uint_16)0xFFFF

#pragma pack(1)
typedef struct
{
    // Type     // Field             // Offset
    uint_8      reserved1;           // 00   
    uint_8      reserved2;           // 08   
    uint_32     reserved3;           // 16   
    uint_8      reserved4;           // 48   
    uint_8      reserved5;           // 56   
    uint_8      reserved6[14];       // 64   
    int_16      reserved7;           // 176  
    uint_8      reserved8;           // 192   
    uint_8      reserved9;           // 200   
    uint_32     reserved10;          // 208   
    uint_16     checksum;            // 240   

} INPUT_MSG;
//#pragma pack()

// Function to swap bytes of a 16-bit value
static uint_16 swap_bytes(uint_16 value)
{
    return (uint_16)((value >> 8) | (value << 8));
}


static const uint16_t GENERIC_CRC16_Table[] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
    0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
    0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
    0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
    0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
    0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
    0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
    0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
    0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
    0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
    0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
    0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
    0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
    0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
    0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
    0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
    0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
    0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
    0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
    0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
    0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
    0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
    0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};


static uint_16
Compute_CRC16_Bytes_Swapped(const uchar* ubBuf, const int ubLen, const uint_16 CRC16_Seed_Value)
{

    uchar  ubBuf_with_bytes_swapped[30];
    memcpy(ubBuf_with_bytes_swapped, ubBuf, ubLen);
    uint_16 crc = CRC16_Seed_Value;
    uint_16 temp;

    for (int everyTwoBytesCounter = 0; everyTwoBytesCounter < (ubLen - 1); everyTwoBytesCounter += 2)
    {
        temp = swap_bytes((uint_16)(ubBuf_with_bytes_swapped[everyTwoBytesCounter] << 8 | ubBuf_with_bytes_swapped[everyTwoBytesCounter + 1]));
        ubBuf_with_bytes_swapped[everyTwoBytesCounter] = (temp >> 8) & 0xFF;
        ubBuf_with_bytes_swapped[everyTwoBytesCounter + 1] = temp & 0xFF;
    }

    for (int byteCount = 0; byteCount < ubLen; byteCount++)
    {
        if (0 == byteCount)
        {
            printf("      %02X ", ubBuf_with_bytes_swapped[byteCount]);
        }
        else
        {
            printf("  %02X ", ubBuf_with_bytes_swapped[byteCount]);
        }
    }
    printf("\t");

    for (int eachByteCounter = 0; eachByteCounter < ubLen; eachByteCounter++)
    {
        crc = (uint_16)((crc << 8) ^ GENERIC_CRC16_Table[((uchar)(crc >> 8) ^ ubBuf_with_bytes_swapped[eachByteCounter]) & 0xFF]);
    }

    return crc;
}

static uint_16
Compute_CRC16_Bytes_NOT_Swapped(const uchar* ubBuf, const int ubLen, const uint_16 CRC16_Seed_Value)
{
    uint_16 crc = CRC16_Seed_Value;

    for (int byteCount = 0; byteCount < ubLen; byteCount++)
    {
        if (0 == byteCount)
        {
            printf("      %02X ", ubBuf[byteCount]);
        }
        else
        {
            printf("  %02X ", ubBuf[byteCount]);
        }

    }

    printf("\t");

    for (int eachByteCounter = 0; eachByteCounter < ubLen; eachByteCounter++)
    {
        crc = (uint_16)((crc << 8) ^ GENERIC_CRC16_Table[((uchar)(crc >> 8) ^ *ubBuf++) & 0xFF]);
    }

    return crc;
}



int main()
{
    uint_16   crc = 0;
    INPUT_MSG inputMsgformat;

    memset(&inputMsgformat, 0, sizeof(inputMsgformat));

    inputMsgformat.reserved1 = 0x01;
    inputMsgformat.reserved2 = 0x02;
    inputMsgformat.reserved3 = 0x06050403;
    inputMsgformat.reserved4 = 0x07;
    inputMsgformat.reserved5 = 0x08;
    memset(&inputMsgformat.reserved6, 0x09, sizeof(inputMsgformat.reserved6));
    inputMsgformat.reserved7 = 0x1110;
    inputMsgformat.reserved8 = 0x12;
    inputMsgformat.reserved9 = 0x13;
    inputMsgformat.reserved10 = 0x17161514;

//                            =====================Data====================
//                            [=Data 0=]  [=Data 1=]  [=Data 2=]  [=Data 3=]
    uint8_t test_data_1[] =  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 4=]  [=Data 5=]  [=Data 6=]  [=Data 7=]
                              0x00, 0x00, 0x25, 0x90, 0x25, 0x50, 0x3F, 0xA0,
//                            [=Data 8=]  [=Data 9=]  [=Data 10=] [=Data 11=]
                              0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x25, 0x80,
//                            [=Data 12=] [=Data 13=] [=Data 14=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

//                            =====================Data====================
//                            [=Data 0=]  [=Data 1=]  [=Data 2=]  [=Data 3=]
    uint8_t test_data_2[] =  {0x00, 0x96, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
//                            [=Data 4=]  [=Data 5=]  [=Data 6=]  [=Data 7=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 8=]  [=Data 9=]  [=Data 10=] [=Data 11=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 12=] [=Data 13=] [=Data 14=]
                              0x03, 0x0A, 0x00, 0x00, 0x00, 0x00};


//                            =====================Data====================
//                            [=Data 0=]  [=Data 1=]  [=Data 2=]  [=Data 3=]
    uint8_t test_data_3[] =  {0x00, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
//                            [=Data 4=]  [=Data 5=]  [=Data 6=]  [=Data 7=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 8=]  [=Data 9=]  [=Data 10=] [=Data 11=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 12=] [=Data 13=] [=Data 14=]
                              0x03, 0x0A, 0x00, 0x00, 0x00, 0x00};

//                            =====================Data====================
//                            [=Data 0=]  [=Data 1=]  [=Data 2=]  [=Data 3=]
    uint8_t test_data_4[] =  {0x00, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
//                            [=Data 4=]  [=Data 5=]  [=Data 6=]  [=Data 7=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 8=]  [=Data 9=]  [=Data 10=] [=Data 11=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 12=] [=Data 13=] [=Data 14=]
                              0x03, 0x0A, 0x00, 0x00, 0x00, 0x00};

//                            =====================Data====================
//                            [=Data 0=]  [=Data 1=]  [=Data 2=]  [=Data 3=]
    uint8_t test_data_5[] =  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 4=]  [=Data 5=]  [=Data 6=]  [=Data 7=]
                              0x00, 0x00, 0x25, 0x90, 0x25, 0x50, 0x3F, 0x30,
//                            [=Data 8=]  [=Data 9=]  [=Data 10=] [=Data 11=]
                              0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x25, 0x80,
//                            [=Data 12=] [=Data 13=] [=Data 14=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

//                            =====================Data====================
//                            [=Data 0=]  [=Data 1=]  [=Data 2=]  [=Data 3=]
    uint8_t test_data_6[] =  {0x00, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
//                            [=Data 4=]  [=Data 5=]  [=Data 6=]  [=Data 7=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 8=]  [=Data 9=]  [=Data 10=] [=Data 11=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 12=] [=Data 13=] [=Data 14=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

//                            =====================Data====================
//                            [=Data 0=]  [=Data 1=]  [=Data 2=]  [=Data 3=]
    uint8_t test_data_7[] =  {0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 4=]  [=Data 5=]  [=Data 6=]  [=Data 7=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 8=]  [=Data 9=]  [=Data 10=] [=Data 11=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xF4,
//                            [=Data 12=] [=Data 13=] [=Data 14=]
                              0x00, 0x41, 0x00, 0x00, 0x00, 0x00};

//                            =====================Data====================
//                            [=Data 0=]  [=Data 1=]  [=Data 2=]  [=Data 3=]
    uint8_t test_data_8[] =  {0x00, 0xe8, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
//                            [=Data 4=]  [=Data 5=]  [=Data 6=]  [=Data 7=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 8=]  [=Data 9=]  [=Data 10=] [=Data 11=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 12=] [=Data 13=] [=Data 14=]
                              0x03, 0x0A, 0x00, 0x00, 0x00, 0x00};


//                            =====================Data====================
//                            [=Data 0=]  [=Data 1=]  [=Data 2=]  [=Data 3=]
    uint8_t test_data_9[] =  {0x00, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
//                            [=Data 4=]  [=Data 5=]  [=Data 6=]  [=Data 7=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 8=]  [=Data 9=]  [=Data 10=] [=Data 11=]
                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//                            [=Data 12=] [=Data 13=] [=Data 14=]
                              0x03, 0x0A, 0x00, 0x00, 0x00, 0x00};

    /*
       00000000000000000000259025503fa00050000000002580000000000000
       0000000000000000000090255025a03f5000000000008025000000000000

       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x25, 0x90, 0x25, 0x50, 0x3F, 0xA0,
       0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x25, 0x80,   0x00, 0x00, 0x00, 0x00, 0x00, 0x00

       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x90, 0x25, 0x50, 0x25, 0xA0, 0x3F,
       0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x25,   0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    */
    for (int byteCount = 0; byteCount < 15; byteCount++)
    {
        if (0 == byteCount)
        {
            printf("     [ DATA%d ]", byteCount);
        }
        else if (byteCount > 0 && byteCount < 10)
        {
            printf(" [ DATA%d ]", byteCount);
        }
        else
        {
            printf(" [DATA%d ]", byteCount);
        }

    }
    printf("\n");

    printf("Byte ");
    for (int byteCount = 0; byteCount < 30; byteCount++)
    {
        if (byteCount < 10)
        {
            printf("[0%d] ", byteCount);
        }
        else
        {
            printf("[%d] ", byteCount);
        }

    }
    printf("\n");

    //crc = Compute_CRC16_Bytes_NOT_Swapped((uchar*)test_data_1, sizeof(test_data_1), CRC16_SEED_VALUE);
    //printf("#1 (BCU CRC Calc): %04X\n", crc);

    //crc = Compute_CRC16_Bytes_Swapped((uchar*)test_data_1, sizeof(test_data_1), CRC16_SEED_VALUE);
    //printf("#1 (RCU CRC Calc): %04X\n\n", crc);

    //crc = Compute_CRC16_Bytes_NOT_Swapped((uchar*)test_data_2, sizeof(test_data_2), CRC16_SEED_VALUE);
    //printf("#2 (BCU CRC Calc): %04X\n", crc);

    //crc = Compute_CRC16_Bytes_Swapped((uchar*)test_data_2, sizeof(test_data_2), CRC16_SEED_VALUE);
    //printf("#2 (RCU CRC Calc): %04X\n\n", crc);

    //crc = Compute_CRC16_Bytes_NOT_Swapped((uchar*)test_data_3, sizeof(test_data_3), CRC16_SEED_VALUE);
    //printf("#3 (BCU CRC Calc): %04X\n", crc);

    //crc = Compute_CRC16_Bytes_Swapped((uchar*)test_data_3, sizeof(test_data_3), CRC16_SEED_VALUE);
    //printf("#3 (RCU CRC Calc): %04X\n\n", crc);

    //crc = Compute_CRC16_Bytes_NOT_Swapped((uchar*)test_data_4, sizeof(test_data_4), CRC16_SEED_VALUE);
    //printf("#4 (BCU CRC Calc): %04X\n", crc);

    //crc = Compute_CRC16_Bytes_Swapped((uchar*)test_data_4, sizeof(test_data_4), CRC16_SEED_VALUE);
    //printf("#4 (RCU CRC Calc): %04X\n\n", crc);

    //crc = Compute_CRC16_Bytes_NOT_Swapped((uchar*)test_data_5, sizeof(test_data_5), CRC16_SEED_VALUE);
    //printf("#5 (BCU CRC Calc): %04X\n", crc);

    //crc = Compute_CRC16_Bytes_Swapped((uchar*)test_data_5, sizeof(test_data_5), CRC16_SEED_VALUE);
    //printf("#5 (RCU CRC Calc): %04X\n\n", crc);

    //crc = Compute_CRC16_Bytes_NOT_Swapped((uchar*)test_data_6, sizeof(test_data_6), CRC16_SEED_VALUE);
    //printf("#6 (BCU CRC Calc): %04X\n", crc);

    //crc = Compute_CRC16_Bytes_Swapped((uchar*)test_data_6, sizeof(test_data_6), CRC16_SEED_VALUE);
    //printf("#6 (RCU CRC Calc): %04X\n\n", crc);

    //crc = Compute_CRC16_Bytes_NOT_Swapped((uchar*)test_data_7, sizeof(test_data_7), CRC16_SEED_VALUE);
    //printf("#7 (BCU CRC Calc): %04X\n", crc);

    //crc = Compute_CRC16_Bytes_Swapped((uchar*)test_data_7, sizeof(test_data_7), CRC16_SEED_VALUE);
    //printf("#7 (RCU CRC Calc): %04X\n\n", crc);

    //crc = Compute_CRC16_Bytes_NOT_Swapped((uchar*)test_data_8, sizeof(test_data_8), CRC16_SEED_VALUE);
    //printf("#8 (BCU CRC Calc): %04X\n", crc);

    //crc = Compute_CRC16_Bytes_Swapped((uchar*)test_data_8, sizeof(test_data_8), CRC16_SEED_VALUE);
    //printf("#8 (RCU CRC Calc): %04X\n\n", crc);

    //crc = Compute_CRC16_Bytes_NOT_Swapped((uchar*)test_data_9, sizeof(test_data_9), CRC16_SEED_VALUE);
    //printf("#9 (BCU CRC Calc): %04X\n", crc);

    //crc = Compute_CRC16_Bytes_Swapped((uchar*)test_data_9, sizeof(test_data_9), CRC16_SEED_VALUE);
    //printf("#9 (RCU CRC Calc): %04X\n\n", crc);


    const uint_8 CRC_Buffer_Length = sizeof(inputMsgformat) - sizeof(inputMsgformat.checksum);

    inputMsgformat.checksum = Compute_CRC16_Bytes_NOT_Swapped((uchar*)&inputMsgformat, CRC_Buffer_Length, CRC16_SEED_VALUE);
    printf("#10 (BCU CRC Calc): %04X\n", inputMsgformat.checksum);

    inputMsgformat.checksum = Compute_CRC16_Bytes_Swapped((uchar*)&inputMsgformat, CRC_Buffer_Length, CRC16_SEED_VALUE);
    printf("#10 (RCU CRC Calc): %04X\n\n", inputMsgformat.checksum);

    return 0;
}
