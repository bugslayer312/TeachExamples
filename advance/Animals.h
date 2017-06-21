#pragma once


#include <iostream>
#include <string>

class Pet
{
protected:
    std::string m_name;
    
public:
    std::string const& GetName() const
    {
        return m_name;
    }
};

class Cat : public virtual Pet
{
public:
    void Purr() const
    {
        std::cout << "Murr mur murrrr...\n";
    }
};

class Dog : public virtual Pet
{
public:
    void Bark() const
    {
        std::cout << "Woof woof Wooooof...\n";
    }
};

class CatDog : public Cat, public Dog
{
public:
    void Introduce()
    {
        std::cout << "My name is " << m_name << "\n";
    }
    void Bark() const
    {
        std::cout << "Hey man! Don't mess with me...\n";
    }
    void ShowTricks()
    {
        std::cout << "Look! I will show you some magic!\n";
    }
};

void StrokeTheCat(Cat const& cat)
{
    cat.Purr();
}

void KickTheDog(Dog const& dog)
{
    dog.Bark();
}