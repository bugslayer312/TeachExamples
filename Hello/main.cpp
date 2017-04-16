#include <iostream>

int main(int argc, char* args[])
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Как ваше имя?" << std::endl;
    char name[20];
    std::cin >> name;
    std::cout << "Здравствуйте, " << name << "!" << std::endl;
    return 0;
}
