#include <stdio.h>
#include <iostream>

enum SemaState
{
    SS_GREEN = 1,
    SS_YELLOW = 2,
    SS_RED = 4
};

void PrintSemafore(int state)
{
    bool isRed = (state & SS_RED) > 0;
    bool isYellow = (state & SS_YELLOW) > 0;
    bool isGreen = (state & SS_GREEN) > 0;
    
    printf("[%c]\n[%c]\n[%c]\n", isRed ? 'R' : ' ', isYellow ? 'Y' : ' ', isGreen ? 'G' : ' ');
}

int NextSemafore(int state)
{
    if ((state & SS_GREEN) > 0)
    {
        return SS_YELLOW;
    }
    if ((state & SS_RED))
    {
        if ((state & SS_YELLOW))
        {
            return SS_GREEN;
        }
        else
        {
            return SS_RED|SS_YELLOW;
        }
    }
    return SS_RED;
}

void TestSemafore()
{
    int state = SS_GREEN;
    char answer = 'y';
    while (answer == 'y')
    {
        PrintSemafore(state);
        std::cout << "Continue ? ";
        std::cin >> answer;
        state = NextSemafore(state);
    }
}

enum LabelColor
{
    LC_RED,
    LC_ORANGE,
    LC_YELLOW,
    LC_OLIVE,
    LC_GREEN,
    LC_BLUE,
    LC_VIOLET,
    LC_WHITE
};  // 8 elements - reserving 4 bits

enum LabelAlign
{
    LA_TOP,
    LA_CENTER,
    LA_BOTTOM
};  // 4 elements - reserving 2 bits

uint32_t ConvertLabelSettingsToInt(bool visible, bool enable, LabelColor color, LabelAlign align, int8_t xoffset)
{
    uint32_t result = 0;
    
    // 0 bit
    if (visible)
    {
        result |= 0x00000001;
    }
    
    // 1 bit
    if (enable)
    {
        result |= 0x00000002;
    }

    // 2..5 bits
    uint32_t colorValue = color << 2;
    result |= colorValue;
    
    // 6..7 bits
    uint32_t alignValue = align << 6;
    result |= alignValue;
    
    // 8 - 15 bits
    uint32_t offsetValue = (uint8_t)xoffset << 8;
    result |= offsetValue;
    
    return result;
}

void PrintlabelSettings(uint32_t settings)
{
    bool visible = (settings & 0x00000001) > 0;
    bool enable = (settings & 0x00000002) > 0;
    uint32_t mask = 0x00000004|0x00000008|0x00000010|0x00000020;
    LabelColor color = (LabelColor)((settings & mask) >> 2);
    mask = 0x00000040|0x00000080;
    LabelAlign align = (LabelAlign)((settings & mask) >> 6);
    mask = 0x0000ff00;
    int8_t offset = (int8_t)((settings & mask) >> 8);
    printf("visible:%i, enable:%i, color:%i, align:%i, xoffset:%i\n", visible, enable, color, align, offset);
}

void SetLabelVisible(uint32_t* settings, bool value)
{
    if (value)
    {
        *settings |= 0x00000001;
    }
    else
    {
        *settings &= ~0x00000001;
    }
}

void SetLabelEnable(uint32_t* settings, bool value)
{
    if (value)
    {
        *settings |= 0x00000002;
    }
    else
    {
        *settings &= ~0x00000002;
    }
}

void TestLabelSettings()
{
    uint32_t labelSettings = ConvertLabelSettingsToInt(true, true, LC_OLIVE, LA_CENTER, -53);
    PrintlabelSettings(labelSettings);
    SetLabelVisible(&labelSettings, false);
    PrintlabelSettings(labelSettings);
    SetLabelEnable(&labelSettings, false);
    PrintlabelSettings(labelSettings);
}

void SwitchLamps(uint8_t* lamps, int begin, int end, bool value)
{
    uint8_t mask = 0;
    for (int i = begin; i <= end; ++i)
    {
        mask |= 0x01 << i;
    }
    if (value)
    {
        *lamps |= mask;
    }
    else
    {
        *lamps &= ~mask;
    }
}

void PrintLampsState(uint8_t lamps)
{
    for (uint8_t mask = 0x80; mask > 0; mask >>= 1)
    {
        std::cout << ((lamps & mask) ? '1' : '0');
    }
    std::cout << std::endl;
}

void TestLamps()
{
    uint8_t lamps = 0;
    PrintLampsState(lamps);
    SwitchLamps(&lamps, 2, 6, true);
    PrintLampsState(lamps);
    SwitchLamps(&lamps, 4, 7, false);
    PrintLampsState(lamps);
}

int main()
{
    // TestSemafore();
    // TestLabelSettings();
    TestLamps();
    
    return 0;
}