#pragma once

class Student
{
private:
    char* m_name = 0;
    int m_rating;
    
    static int g_count;

    static void IncreaseCount();
    static void DecreaseCount();
    
public:
    Student();
    Student(char const* name, int rating);
    Student(Student const& student);
    ~Student();
    
    char const* GetName() const;
    int GetRating() const;
    
    void SetName(char const* name);
    void SetRating(int rating);
    
    void Read();
    void Print() const;
    
    Student& operator=(Student& student);
    
    static int GetStudentCount();
};