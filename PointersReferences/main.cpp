#include <clocale>
#include <iostream>

struct Distance
{
    int feet;
    float inches;
};

void Add(Distance* d1, Distance const* d2)
{
    d1->feet += d2->feet;
    d1->inches += d2->inches;
    if (d1->inches >= 12.0f)
    {
        d1->feet += 1;
        d1->inches -= 12.0f;
    }
}

void Substract(Distance* d1, Distance const* d2)
{
    d1->feet -= d2->feet;
    d1->inches -= d2->inches;
    if (d1->inches < 0)
    {
        d1->inches += 12.0f;
        d1->feet -= 1;
    }
}

Distance Summ(Distance const* d1, Distance const* d2)
{
    Distance result = *d1;
    Add(&result, d2);
    return result;
}

Distance Difference(Distance const* d1, Distance const* d2)
{
    Distance result = *d1;
    Substract(&result, d2);
    return result;
}

Distance Read()
{
    Distance result;
    std::cout << "feet: ";
    std::cin >> result.feet;
    std::cout << "inches: ";
    std::cin >> result.inches;
    return result;
}

void Print(Distance const* value)
{
    std::cout << value->feet << "\'" << value->inches << "\"";
}

int main()
{
    Distance d1 = {3, 5.0f};
    Distance d2 = {2, 8.0f};
    Distance summ = d1;
    Add(&summ, &d2);
    Distance diff = d1;
    Substract(&diff, &d2);
    
    Print(&d1);
    std::cout << " + ";
    Print(&d2);
    std::cout << " = ";
    Print(&summ);
    std::cout << std::endl;
    
    Print(&d1);
    std::cout << " - ";
    Print(&d2);
    std::cout << " = ";
    Print(&diff);
    std::cout << std::endl;
    return 0;
}