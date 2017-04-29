#include <stdio.h>

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

enum Suit
{
    Heart = 0,      // черви
    Diamond = 1,    // буби
    Club = 2,       // трефы
    Spade = 3       // пики
};

const uint8_t Jack = 11;
const uint8_t Queen = 12;
const uint8_t King = 13;
const uint8_t Ace = 14;

typedef struct
{
    uint8_t value: 4;
    uint8_t suit: 2;
    bool isJoker: 1;
} Card;

typedef struct
{
    uint8_t b1:1;
    uint8_t b2:1;
    uint8_t b3:1;
    uint8_t b4:1;
    uint8_t b5:1;
    uint8_t b6:1;
    uint8_t b7:1;
    uint8_t b8:1;
} Bits;

typedef struct
{
    unsigned Mantissa: 10;
    unsigned Exponent: 5;
    bool Sign: 1;
    
} SmallFloat;

typedef union
{
    Bits AsBits;
    uint8_t AsDecimal;
} CombinedUInt8;

void PrintBinary(Bits bits)
{
    printf("%u%u%u%u%u%u%u%u\n", bits.b8, bits.b7, bits.b6, bits.b5, bits.b4, bits.b3, bits.b2, bits.b1);
}

Bits ReadBinary()
{
    char buffer[9];
    scanf("%s", buffer);
    int length = strlen(buffer);
    while (length < 8)
    {
        memcpy(buffer + 1, buffer, length + 1);
        buffer[0] = '0';
        length = strlen(buffer);
    }
    Bits result;
    result.b8 = buffer[0] == '1' ? 1 : 0;
    result.b7 = buffer[1] == '1' ? 1 : 0;
    result.b6 = buffer[2] == '1' ? 1 : 0;
    result.b5 = buffer[3] == '1' ? 1 : 0;
    result.b4 = buffer[4] == '1' ? 1 : 0;
    result.b3 = buffer[5] == '1' ? 1 : 0;
    result.b2 = buffer[6] == '1' ? 1 : 0;
    result.b1 = buffer[7] == '1' ? 1 : 0;
    return result;
}

Bits DecimalToBinary(uint8_t decimal)
{
    Bits* ptrResult = (Bits*)&decimal;
    return *ptrResult;
}

uint8_t BinaryToDecimal(Bits bits)
{
    uint8_t* ptrResult = (uint8_t*)&bits;
    return *ptrResult;
}

typedef union
{
    struct
    {
        uint8_t A;
        uint8_t R;
        uint8_t G;
        uint8_t B;
    };
    uint32_t AsUInt;
} Color;

/*
typedef struct tagMSG {
    HWND   hwnd;
    UINT   message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD  time;
    POINT  pt;
} MSG, *PMSG, *LPMSG;
*/

typedef union
{
    struct
    {
        uint16_t LowWord;   // 0..65536
        uint16_t HighWord;  // 0..65536
    };
    uint32_t AsUInt;
} DWORD;

int main()
{
    /*
    Card card;
    printf("%lu\n", sizeof(card));
    uint8_t* allMem = (uint8_t*)(&card);
    *allMem = 0;
    printf("%u, %u, %u\n", card.value, card.suit, card.isJoker);
    card.suit = Diamond;
    card.value = Jack;
    printf("%u, %u, %u\n", card.value, card.suit, card.isJoker);
    card.isJoker = true;
    printf("%u, %u, %u\n", card.value, card.suit, card.isJoker);
    card.value = 18;    // overbound of value, will write 2
    printf("%u, %u, %u\n", card.value, card.suit, card.isJoker);
    card.suit = 4;  // overbound of value, will write 0
    printf("%u, %u, %u\n", card.value, card.suit, card.isJoker);
    */
    
    uint8_t decimal;
    uint32_t input;
    /*
    printf("Enter number 0-255\n");
    scanf("%u", &input);
    decimal = (uint8_t)input;
    Bits bits = DecimalToBinary(decimal);
    PrintBinary(bits);
    printf("\nEnter 8 bit number in binary format\n");
    bits = ReadBinary();
    decimal = BinaryToDecimal(bits);
    printf("%u\n", decimal);
    */
    
    printf("\nEnter number 0-255\n");
    scanf("%u", &input);
    CombinedUInt8 combined;
    combined.AsDecimal = (uint8_t)input;
    PrintBinary(combined.AsBits);
    
    printf("\nEnter 8 bit number in binary format\n");
    combined.AsBits = ReadBinary();
    decimal = combined.AsDecimal;
    printf("%u\n", decimal);
    
    return 0;
}