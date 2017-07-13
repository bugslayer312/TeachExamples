#include "Student.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

template<class KeyT, class ValueT>
std::ostream& operator<<(std::ostream& stream, std::pair<const KeyT, ValueT> const& pair)
{
    std::cout << "key: " << pair.first << ", value: " << pair.second;
    return stream;
}

void WorkWithMaps()
{
    // Создание и заполнение
    std::map<std::string, Student> students = { {"Ivanov", Student("Ivanov", 6)},
        {"Azarenko", Student("Azarenko", 3)}, {"Shukherman", Student("Shukherman", 8)}};
    Student belkin("Belkin", 7);
    
    // вставка элемента
    students.insert(std::pair<std::string, Student>(belkin.GetName(), belkin));
    
    // вывод посредством обхода с помощью итераторов
    for (std::map<std::string, Student>::iterator it = students.begin(); it != students.end(); ++it)
    {
        std::cout << "key: " << it->first << ", value: " << it->second << "\n";
        // другой вариант
        // std::cout << *it << "\n";
    }
    std::cout << "=============================\n";
    
    // вывод с помощью цикла for each
    for (std::pair<const std::string, Student>& studPair : students)
    {
        std::cout << studPair << "\n";
    }
    std::cout << "=============================\n";
    
    // вывод с помощью algoritma copy
    std::copy(students.begin(), students.end(),
              std::ostream_iterator<std::pair<const std::string, Student>>(std::cout, "\n"));
    std::cout << "=============================\n";
    
    // вставка и проверка вставился ли элемент с новым ключом
    std::pair<std::map<std::string, Student>::iterator, bool> ret;
    ret = students.insert(std::pair<std::string, Student>(belkin.GetName(), belkin));
    if (!ret.second)
    {
        std::cout << ret.first->first << " already in map\n";
    }
    else
    {
        std::cout << "inserted new element: " << ret.first->first << "\n\n";
    }
    
    // find element
    auto found = students.find("Ivanov");
    if (found != students.end())
    {
        std::cout << "found " << found->first << ", deleting\n";
        students.erase(found);
    }
    else
    {
        std::cout << "not found\n";
    }
    std::copy(students.begin(), students.end(),
              std::ostream_iterator<std::pair<const std::string, Student>>(std::cout, "\n"));
    std::cout << "=============================\n";
    
    students["Shukherman"].SetRating(10);
    students["Eroshenko"].SetRating(8);
    std::copy(students.begin(), students.end(),
              std::ostream_iterator<std::pair<const std::string, Student>>(std::cout, "\n"));
    std::cout << "=============================\n\n";
    
    std::multimap<std::string, Student> students2(students.begin(), students.end());
    belkin.SetRating(9);
    students2.insert(std::pair<std::string, Student>(belkin.GetName(), belkin));
    std::copy(students2.begin(), students2.end(),
              std::ostream_iterator<std::pair<const std::string, Student>>(std::cout, "\n"));
    std::cout << "=============================\n\n";
}

void WorkWithSets()
{
    std::set<int> set1 = {10, 1, 23, 6, 4, 2, 3};
    std::copy(set1.begin(), set1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    int a = 5;
    if (set1.find(a) != set1.end())
    {
        std::cout << "set has " << a << std::endl;
    }
    else
    {
        std::cout << "set hasn't " << a << std::endl;
    }
    std::set<int> set2 = {0, 1, 5, 17, 34, 2};
    std::copy(set1.begin(), set1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    // объединение множеств
    std::set<int> setUnion(set1);
    setUnion.insert(set2.begin(), set2.end());
    
    std::copy(setUnion.begin(), setUnion.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    // пересечение множеств
    std::set<int> setInsersection(set1);
    for (auto it = setInsersection.begin(); it != setInsersection.end();)
    {
        if (set2.find(*it) == set2.end())
        {
            setInsersection.erase(it++);
        }
        else
        {
            ++it;
        }
    }
    std::copy(setInsersection.begin(), setInsersection.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << std::endl;
    
    std::multiset<int> multi(set1.begin(), set1.end());
    multi.insert(set2.begin(), set2.end());
    
    std::copy(multi.begin(), multi.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    auto it_low = multi.lower_bound(2);
    auto it_up = multi.upper_bound(2);
    
    std::cout << "low: " << std::distance(multi.begin(), it_low) << std::endl;
    std::cout << "high: " << std::distance(multi.begin(), it_up) << std::endl;
    
    multi.erase(it_low, it_up);
    std::copy(multi.begin(), multi.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main()
{
    // WorkWithMaps();
    // WorkWithSets();
    
    return 0;
}