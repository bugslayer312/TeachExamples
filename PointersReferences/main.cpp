#include <clocale>
#include <iostream>

struct Distance
{
    int feet;
    float inches;
};

Distance Summ(Distance d1, Distance d2)
{
    Distance result = {d1.feet + d2.feet, d1.inches + d2.inches};
    return result;
}

Distance Difference(Distance d1, Distance d2)
{
    Distance result = {d1.feet - d2.feet, d1.inches - d2.inches};
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

void Print(Distance value)
{
    std::cout << value.feet << "\'" << value.inches << "\"";
}

int main()
{
    Distance d1 = {3, 5.0f};
    Distance d2 = {2, 8.0f};
    Distance summ = Summ(d1, d2);
    Distance sub = Difference(d1, d2);
    
    Print(d1);
    std::cout << " + ";
    Print(d2);
    std::cout << " = ";
    Print(summ);
    std::cout << std::endl;
    
    Print(d1);
    std::cout << " - ";
    Print(d2);
    std::cout << " = ";
    Print(sub);
    std::cout << std::endl;
    return 0;
}