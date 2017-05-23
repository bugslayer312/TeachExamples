#pragma once

class Student
{
private:
    char* m_name;
    int m_rating;
    
public:
    Student();
    Student(char const* name, int rating);
    
    char const* GetName();
    int GetRating();
    
    void SetName(char const* name);
    void SetRating(int rating);
    
    void Read();
    void Print();
};