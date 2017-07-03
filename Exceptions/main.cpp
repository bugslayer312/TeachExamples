#include "SmartPtr.h"
#include "Stack.h"

#include <iostream>

void CustomTerminate()
{
    std::cout << "Custom teminate\n";
    exit(1);    // всегда завершается вызовом exit() или abort()
}

int main()
{
    // устанавливаем свою функцию-обработчик аварийного завершения
    std::set_terminate(CustomTerminate);
    
    try // блок повторных попыток, здесь может выброситься исключение
    {
        Stack<int, 5> stack;
        for (int i = 0; i < 6; ++i)
        {
            stack.Push(i);
        }
        std::cout << "next instruction\n"; // эта строчка не выполнится из-за исключения
    }
    catch (StackIsFullException& ex)    // ловушки ставятся в порядке от производных классов к базовым
    {
        std::cout << ex.what() << std::endl;
    }
    catch (StackException& ex)
    {
        std::cout << "Stack exception is throwed\n";
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex)  // всегда выбираем базовым классом для исключений std::exception
    {
        std::cout << ex.what() << std::endl;
    }
    catch (...) // этот блок ловит все исключения
    {
        std::cout << "Catching all exceptions\n";
    }
    std::cout << "Continue work\n"; // эта строчка выполнится, т. к. все исключения отловлены
    
    try
    {
        SmartPtr<Stack<int, 5>> stack(new Stack<int, 5>());
        // здесь stack - умный указатель над объектом, созданным динамически
        // при возникновении исключения, у него вызовется десктруктор и память не утечет
        stack->Push(1);
        stack->Push(2);
        stack->Pop();
        stack->Pop();
        stack->Pop();
    }
    catch (StackException& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception&)
    {
        // ничего не делаем
    }
    
    return 0;
}