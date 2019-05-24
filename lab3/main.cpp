#include "stack.h"

int main()
{

    try
    {
        std::cout << "Stack with std::string type" << std::endl;
        Stack<std::string> mystack;
        mystack.push("dafa");
        mystack.push("bfdasd");
        mystack.push("cgfvv");
        mystack.push("ddfg");

        std::cout << "my stack contains: " << std::endl;
        while (! mystack.empty())
        {
            auto top = mystack.top();
            for (auto i = 0; i < top.size(); ++i)
            {
                std::cout << top[i];
            }
            std::cout << ' ';
            mystack.pop();
        }
        std::cout << std::endl;

        mystack.push("012");
        mystack.push("748");
        mystack.push("663");
        mystack.push("325");
        mystack.pop();
        mystack.push("944");
        while (! mystack.empty())
        {
            auto top = mystack.top();
            for (auto i = 0; i < top.size(); ++i)
            {
                std::cout << top[i];
            }
            std::cout << ' ';
            mystack.pop();
        }
        std::cout << std::endl;

//	  генерация исключения:
//        mystack.pop();

    }
    catch (VectError& vre)
    {
        vre.ErrMsg();
        exit(1);
    }

    try
    {
        std::cout << std::endl;
        std::cout << "Stack with int type" << std::endl;
        Stack<int> mystack;
        mystack.push(1);
        mystack.push(2);
        mystack.push(3);
        mystack.push(4);

        std::cout << "my stack contains: " << std::endl;
        while (! mystack.empty())
        {
            std::cout << mystack.top() << " ";
            mystack.pop();
        }
        std::cout << std::endl;

        mystack.push(0);
        mystack.push(7);
        mystack.push(6);
        mystack.push(3);
        mystack.pop();
        mystack.push(9);
        while (! mystack.empty())
        {
            std::cout << mystack.top() << ' ';
            mystack.pop();
        }
        std::cout << std::endl;

//	генерация исключения
//        mystack.pop();
//        mystack.pop();
    }
    catch (VectError& vre)
    {
        vre.ErrMsg();
        exit(1);
    }

    try
    {
        std::cout << std::endl;
        std::cout << "Stack with double type" << std::endl;
        Stack<double> mystack;
        mystack.push(1.24);
        mystack.push(2.23);
        mystack.push(3.36);
        mystack.push(4.58);
        mystack.push(5.74);

        std::cout << "my stack contains: " << std::endl;
        while (! mystack.empty())
        {
            std::cout << mystack.top() << " ";
            mystack.pop();
        }
        std::cout << std::endl;

        mystack.push(0.24);
        mystack.push(7.77);
        mystack.push(6.66);
        mystack.push(3.33);
        mystack.pop();
        mystack.push(9.55);
        while (! mystack.empty())
        {
            std::cout << mystack.top() << " ";
            mystack.pop();
        }
        std::cout << std::endl;

//	 генерация исключени
//        mystack.pop();
//        mystack.pop();
    }
    catch (VectError& vre)
    {
        vre.ErrMsg();
        exit(1);
    }

    system("pause");
    return 0;
}
